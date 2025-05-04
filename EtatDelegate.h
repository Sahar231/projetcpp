#ifndef ETATDELEGATE_H
#define ETATDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class EtatDelegate : public QStyledItemDelegate
{
public:
    explicit EtatDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Mettre en gras toute la colonne 2 (NOM_EQ)
        if (index.column() == 1) { // Qt commence les colonnes à 0, donc 1 = colonne 2
            opt.font.setBold(true);
        }

        // Appliquer les couleurs à la colonne ETAT (colonne 5)
        if (index.column() == 5) {
            QString ETAT = index.data().toString();
            if (ETAT == "disponible") {
                opt.palette.setColor(QPalette::Text, Qt::green);
            } else if (ETAT == "en service") {
                opt.palette.setColor(QPalette::Text, Qt::blue);
            } else if (ETAT == "en panne") {
                opt.palette.setColor(QPalette::Text, Qt::red);
            }
              // Texte en gras aussi pour ETAT
        }

        QStyledItemDelegate::paint(painter, opt, index);
    }
};

#endif // ETATDELEGATE_H
