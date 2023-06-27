#include "bigpoint.h"

BigPoint::BigPoint(){
    // load pics
    pics.push_back(QPixmap(":/img/img/bigpoint"));
    pics.push_back(QPixmap(":/img/img/transparent"));
    setPixmap(pics[0].scaled(50, 50, Qt::KeepAspectRatio));
    picsArg = 0;
    isEaten = false;
}

void BigPoint::collide(){
    isEaten = true;
    setPixmap(pics[1].scaled(50, 50, Qt::KeepAspectRatio));
}

void BigPoint::changePics(){
    if(!isEaten){
        picsArg = picsArg * -1 + 1;
        setPixmap(pics[picsArg].scaled(50, 50, Qt::KeepAspectRatio));
    }
}
