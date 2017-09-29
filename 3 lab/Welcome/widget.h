#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QPixmap>

#include "answer.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Answer *a;

    int w = 640;
    int h = 360;

    QString lgn = "123";
    QString pssw = "123";
    QString msg;

private slots:
    void on_Lgn_clicked();

};

#endif // WIDGET_H
