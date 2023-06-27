#include "red.h"

Red::Red(){
    // load pics
    pics[0].push_back(QPixmap(":/img/img/redu1"));
    pics[0].push_back(QPixmap(":/img/img/redu2"));
    pics[1].push_back(QPixmap(":/img/img/redd1"));
    pics[1].push_back(QPixmap(":/img/img/redd2"));
    pics[2].push_back(QPixmap(":/img/img/redl1"));
    pics[2].push_back(QPixmap(":/img/img/redl2"));
    pics[3].push_back(QPixmap(":/img/img/redr1"));
    pics[3].push_back(QPixmap(":/img/img/redr2"));
    pics[4].push_back(QPixmap(":/img/img/blue1"));
    pics[4].push_back(QPixmap(":/img/img/blue2"));
    pics[5].push_back(QPixmap(":/img/img/white1"));
    pics[5].push_back(QPixmap(":/img/img/white2"));
    setPixmap(pics[2][0].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(376, 272);
    direction = 0;
    picsArg = 0;
}

