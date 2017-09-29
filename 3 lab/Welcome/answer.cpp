#include "answer.h"

Answer::Answer(QWidget *parent) : QWidget(parent)
{
    int w = 200;
    int h = 100;
    setWindowTitle("Answer");
    setFixedSize(w,h);
    setMinimumSize(w, h);
    lbl = new QLabel(this);
    lbl->setGeometry(10,10,w, h/2);
    btn = new QPushButton(this);
    btn->setGeometry(w/2,h/2, 50, 30);
    btn->setText("Ok");
    connect(btn, SIGNAL(clicked()), SLOT(close()));
}

void Answer::setMessage(QString str)
{
    lbl->setText(str);
}

