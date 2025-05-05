#include "menu.h"
#include "ui_menu.h"
#include "equip.h"
#include "form.h"
#include "patie.h"
#include "user.h"
#include "projet.h"
#include "mainwindow.h"
menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
    palette.setBrush(QPalette::Window,  pixmap);
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_4_clicked()
{
    equip *e = new equip();
    e->show();
    this->hide();
}


void menu::on_pushButton_3_clicked()
{
    forma *f= new forma();
    f->show();
    this->hide();

}


void menu::on_pushButton_2_clicked()
{
    patie *p=new patie();
    p->show();
    this->hide();
}


void menu::on_pushButton_clicked()
{
    user *u=new user();
    u->show();
    this->hide();
}


void menu::on_pushButton_5_clicked()
{
    projet *r=new projet();
    r->show();
    this->hide();

}


void menu::on_pushButton_6_clicked()
{
    MainWindow *v=new MainWindow();
    v->show();
    this->hide();

}

