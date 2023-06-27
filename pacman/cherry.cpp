#include "cherry.h"
#include "mainwindow.h"

Cherry::Cherry()
{
    // load pics
    pics.push_back(QPixmap(":/img/img/cherry"));
    pics.push_back(QPixmap(":/img/img/transparent"));
    setPixmap(pics[1].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(376, 416);
}

void Cherry::changePics(int i){
    setPixmap(pics[i].scaled(50, 50, Qt::KeepAspectRatio));
}
