#include "smallpoint.h"
#include "mainwindow.h"

SmallPoint::SmallPoint(double X, double Y, int i, int j){
    // load pics
    pics.push_back(QPixmap(":/img/img/smallpoint"));
    pics.push_back(QPixmap(":/img/img/transparent"));
    if(map[i][j]){
        setPixmap(pics[0].scaled(50, 50, Qt::KeepAspectRatio));
    }
    else {
        setPixmap(pics[1].scaled(50, 50, Qt::KeepAspectRatio));
    }
    setPos(X, Y);
}

void SmallPoint::collide(){
    setPixmap(pics[1].scaled(50, 50, Qt::KeepAspectRatio));
}
