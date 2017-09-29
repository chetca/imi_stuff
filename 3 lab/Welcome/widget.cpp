#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setGeometry(0,0,w,h);
    QPixmap pic(QString::fromUtf8(":/screen/screen"));
    ui->label->setPixmap(pic);
    ui->label->setScaledContents(true);
    QPixmap logo(QString::fromUtf8(":/icon/logo"));
    ui->logoImg->setPixmap(logo);
    ui->logoImg->setScaledContents(true);

    //ui->Lgn->

    a = new Answer;
    //connect(ui->Lgn, SIGNAL(ui->Lgn->clicked()), this, SLOT(this->btnClickked()));

    //connect(this, SIGNAL(this->btnClicked(msg)), a, SLOT(a->setMessage(msg)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Lgn_clicked()
{
    if ((ui->login->text() == lgn) && (ui->password->text() == pssw)) {
        msg = "Login Ok!";
    }
    else {
        msg = "Invalid Login or Password";
    }
    a->setMessage(msg);
    a->show();
}
