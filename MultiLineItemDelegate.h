#ifndef MULTILINEITEMDELEGATE_H
#define MULTILINEITEMDELEGATE_H
#include <QStyledItemDelegate>
#include <QTextOption>

class MultiLineItemDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);
        opt.textElideMode = Qt::ElideNone;
        opt.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;
        opt.features |= QStyleOptionViewItem::WrapText;

        QTextOption textOption;
        textOption.setWrapMode(QTextOption::WordWrap);

        QStyledItemDelegate::paint(painter, opt, index);
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QSize size = QStyledItemDelegate::sizeHint(option, index);
        QString text = index.data().toString();

        QFontMetrics fm(option.font);
        QRect rect = fm.boundingRect(QRect(0, 0, option.rect.width(), 0), Qt::TextWordWrap, text);
        size.setHeight(rect.height() + 10); // Ajoute un petit padding
        return size;
    }
};

#endif // MULTILINEITEMDELEGATE_H
