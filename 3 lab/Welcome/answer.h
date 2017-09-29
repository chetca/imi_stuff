#ifndef ANSWER_H
#define ANSWER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Answer : public QWidget
{
    Q_OBJECT
public:
    explicit Answer(QWidget *parent = nullptr);

public slots:
   void setMessage(QString str);

private:
    QLabel *lbl;
    QPushButton *btn;
};

#endif // ANSWER_H
