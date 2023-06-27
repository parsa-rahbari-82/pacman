#include "orange.h"

Orange::Orange(){
    // load pics
    pics[0].push_back(QPixmap(":/img/img/orangeu1"));
    pics[0].push_back(QPixmap(":/img/img/orangeu2"));
    pics[1].push_back(QPixmap(":/img/img/oranged1"));
    pics[1].push_back(QPixmap(":/img/img/oranged2"));
    pics[2].push_back(QPixmap(":/img/img/orangel1"));
    pics[2].push_back(QPixmap(":/img/img/orangel2"));
    pics[3].push_back(QPixmap(":/img/img/oranger1"));
    pics[3].push_back(QPixmap(":/img/img/oranger2"));
    pics[4].push_back(QPixmap(":/img/img/blue1"));
    pics[4].push_back(QPixmap(":/img/img/blue2"));
    pics[5].push_back(QPixmap(":/img/img/white1"));
    pics[5].push_back(QPixmap(":/img/img/white2"));
    setPixmap(pics[0][0].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(430, 342);
    direction = 0;
    picsArg = 0;
}

