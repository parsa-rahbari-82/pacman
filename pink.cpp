#include "pink.h"

Pink::Pink(){
    // load pics
    pics[0].push_back(QPixmap(":/img/img/pinku1"));
    pics[0].push_back(QPixmap(":/img/img/pinku2"));
    pics[1].push_back(QPixmap(":/img/img/pinkd1"));
    pics[1].push_back(QPixmap(":/img/img/pinkd2"));
    pics[2].push_back(QPixmap(":/img/img/pinkl1"));
    pics[2].push_back(QPixmap(":/img/img/pinkl2"));
    pics[3].push_back(QPixmap(":/img/img/pinkr1"));
    pics[3].push_back(QPixmap(":/img/img/pinkr2"));
    pics[4].push_back(QPixmap(":/img/img/blue1"));
    pics[4].push_back(QPixmap(":/img/img/blue2"));
    pics[5].push_back(QPixmap(":/img/img/white1"));
    pics[5].push_back(QPixmap(":/img/img/white2"));
    setPixmap(pics[1][0].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(376, 342);
    direction = 0;
    picsArg = 0;
}
