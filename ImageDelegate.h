#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H



#include <QStyledItemDelegate>
#include <QPainter>
#include <QPixmap>

class ImageDelegate : public QStyledItemDelegate {
public:
    explicit ImageDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        if (index.column() == 7) { // Supposons que la colonne 7 contient l'image
            QByteArray imageData = index.data(Qt::DisplayRole).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            if (!pixmap.isNull()) {
                QRect rect = option.rect;
                QSize size = QSize(50, 50); // Taille de l'image dans la cellule
                QRect imageRect(rect.x() + (rect.width() - size.width()) / 2,
                                rect.y() + (rect.height() - size.height()) / 2,
                                size.width(), size.height());

                painter->drawPixmap(imageRect, pixmap);
                return;
            }
        }
        QStyledItemDelegate::paint(painter, option, index);
    }
};


#endif // IMAGEDELEGATE_H
