#include <zxing/qrcode/decoder/DecodedBitStreamParser.h>
#include <zxing/common/CharacterSetECI.h>
#include <zxing/FormatException.h>
#include <zxing/common/StringUtils.h>
#include <iostream>

using namespace std;
using namespace zxing;
using namespace zxing::qrcode;
using namespace zxing::common;

const char DecodedBitStreamParser::ALPHANUMERIC_CHARS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', ' ', '$', '%', '*', '+', '-', '.', '/', ':'
};

namespace {int GB2312_SUBSET = 1;}

void DecodedBitStreamParser::append(std::string &result, const std::string& in, const char *src) {
    append(result, (zxing::byte const*)in.c_str(), in.length(), src);
}

void DecodedBitStreamParser::append(std::string &result, const zxing::byte *bufIn, size_t nIn, const char *src) {
    // Utilisation de StringUtils pour une conversion simple de bytes vers une chaîne en UTF-8
    if (nIn == 0) {
        return;
    }
    try {
        result.append((const char *)bufIn, nIn); // Utilisation directe dans le cas d'une absence de conversion nécessaire
    } catch (const std::exception& e) {
        cerr << "Erreur lors de l'ajout au résultat: " << e.what() << endl;
        throw ReaderException("Erreur lors de la conversion de l'encodage.");
    }
}

void DecodedBitStreamParser::decodeHanziSegment(QSharedPointer<BitSource> bits_, std::string& result, int count) {
    BitSource& bits (*bits_);
    if (count * 13 > bits.available()) {
        throw FormatException();
    }

    size_t nBytes = 2 * count;
    byte* buffer = new byte[nBytes];
    int offset = 0;
    while (count > 0) {
        int twoBytes = bits.readBits(13);
        int assembledTwoBytes = ((twoBytes / 0x060) << 8) | (twoBytes % 0x060);
        if (assembledTwoBytes < 0x003BF) {
            assembledTwoBytes += 0x0A1A1;
        } else {
            assembledTwoBytes += 0x0A6A1;
        }
        buffer[offset] = (zxing::byte) ((assembledTwoBytes >> 8) & 0xFF);
        buffer[offset + 1] = (zxing::byte) (assembledTwoBytes & 0xFF);
        offset += 2;
        count--;
    }

    try {
        append(result, buffer, nBytes, StringUtils::GB2312); // Conversion en utilisant StringUtils si possible
    } catch (const ReaderException&) {
        delete[] buffer;
        throw FormatException();
    }

    delete[] buffer;
}

void DecodedBitStreamParser::decodeKanjiSegment(QSharedPointer<BitSource> bits, std::string &result, int count) {
    size_t nBytes = 2 * count;
    byte* buffer = new byte[nBytes];
    int offset = 0;
    while (count > 0) {
        int twoBytes = bits->readBits(13);
        int assembledTwoBytes = ((twoBytes / 0x0C0) << 8) | (twoBytes % 0x0C0);
        if (assembledTwoBytes < 0x01F00) {
            assembledTwoBytes += 0x08140;
        } else {
            assembledTwoBytes += 0x0C140;
        }
        buffer[offset] = (zxing::byte)(assembledTwoBytes >> 8);
        buffer[offset + 1] = (zxing::byte)assembledTwoBytes;
        offset += 2;
        count--;
    }
    try {
        append(result, buffer, nBytes, StringUtils::SHIFT_JIS); // Utilisation du encodage SHIFT_JIS
    } catch (const ReaderException&) {
        delete[] buffer;
        throw FormatException();
    }
    delete[] buffer;
}

std::string DecodedBitStreamParser::decodeByteSegment(QSharedPointer<BitSource> bits_, std::string& result, int count,
                                                      const CharacterSetECI* currentCharacterSetECI,
                                                      QSharedPointer<std::vector< QSharedPointer<std::vector<zxing::byte>>>> byteSegments,
                                                      const Hashtable& hints) {
    int nBytes = count;
    BitSource& bits (*bits_);
    if (count << 3 > bits.available()) {
        throw FormatException();
    }

    QSharedPointer<std::vector<zxing::byte>> bytes_ (new std::vector<zxing::byte>(count));
    byte* readBytes = &(*bytes_)[0];
    for (int i = 0; i < count; i++) {
        readBytes[i] = (zxing::byte) bits.readBits(8);
    }
    string encoding;
    if (currentCharacterSetECI == 0) {
        encoding = StringUtils::guessEncoding(readBytes, count, hints);
    } else {
        encoding = currentCharacterSetECI->name();
    }
    try {
        append(result, readBytes, nBytes, encoding.c_str());
    } catch (const ReaderException&) {
        throw FormatException();
    }
    byteSegments->push_back(bytes_);
    return encoding;
}

void DecodedBitStreamParser::decodeNumericSegment(QSharedPointer<BitSource> bits, std::string &result, int count) {
    int nBytes = count;
    byte* bytes = new byte[nBytes];
    int i = 0;
    while (count >= 3) {
        if (bits->available() < 10) {
            delete[] bytes;
            throw ReaderException("format exception");
        }
        int threeDigitsBits = bits->readBits(10);
        if (threeDigitsBits >= 1000) {
            ostringstream s;
            s << "Illegal value for 3-digit unit: " << threeDigitsBits;
            delete[] bytes;
            throw ReaderException(s.str().c_str());
        }
        bytes[i++] = ALPHANUMERIC_CHARS[threeDigitsBits / 100];
        bytes[i++] = ALPHANUMERIC_CHARS[(threeDigitsBits / 10) % 10];
        bytes[i++] = ALPHANUMERIC_CHARS[threeDigitsBits % 10];
        count -= 3;
    }
    if (count == 2) {
        if (bits->available() < 7) {
            throw ReaderException("format exception");
        }
        int twoDigitsBits = bits->readBits(7);
        if (twoDigitsBits >= 100) {
            ostringstream s;
            s << "Illegal value for 2-digit unit: " << twoDigitsBits;
            delete[] bytes;
            throw ReaderException(s.str().c_str());
        }
        bytes[i++] = ALPHANUMERIC_CHARS[twoDigitsBits / 10];
        bytes[i++] = ALPHANUMERIC_CHARS[twoDigitsBits % 10];
    } else if (count == 1) {
        if (bits->available() < 4) {
            throw ReaderException("format exception");
        }
        int digitBits = bits->readBits(4);
        if (digitBits >= 10) {
            ostringstream s;
            s << "Illegal value for digit unit: " << digitBits;
            delete[] bytes;
            throw ReaderException(s.str().c_str());
        }
        bytes[i++] = ALPHANUMERIC_CHARS[digitBits];
    }
    append(result, bytes, nBytes, StringUtils::ASCII);
    delete[] bytes;
}

char DecodedBitStreamParser::toAlphaNumericChar(size_t value) {
    if (value >= sizeof(DecodedBitStreamParser::ALPHANUMERIC_CHARS)) {
        throw FormatException();
    }
    return ALPHANUMERIC_CHARS[value];
}

void DecodedBitStreamParser::decodeAlphanumericSegment(QSharedPointer<BitSource> bits_, std::string& result, int count, bool fc1InEffect) {
    BitSource& bits (*bits_);
    ostringstream bytes;
    while (count > 1) {
        if (bits.available() < 11) {
            throw FormatException();
        }
        int nextTwoCharsBits = bits.readBits(11);
        bytes << toAlphaNumericChar(nextTwoCharsBits / 45);
        bytes << toAlphaNumericChar(nextTwoCharsBits % 45);
        count -= 2;
    }
    if (count == 1) {
        if (bits.available() < 6) {
            throw FormatException();
        }
        bytes << toAlphaNumericChar(bits.readBits(6));
    }
    string s = bytes.str();
    if (fc1InEffect) {
        ostringstream r;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] != '%') {
                r << s[i];
            } else {
                if (i + 1 < s.length()) {
                    char nextChar = s[i + 1];
                    if (nextChar == 'F') {
                        r << '\n';
                        i++;
                    } else if (nextChar == 'A') {
                        r << '\r';
                        i++;
                    } else {
                        r << '%';
                    }
                } else {
                    r << '%';
                }
            }
        }
        result.append(r.str());
    } else {
        result.append(s);
    }
}
