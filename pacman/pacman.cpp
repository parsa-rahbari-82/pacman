#include "pacman.h"
#include "mainwindow.h"

Pacman::Pacman(){
    // load pics
    pics[0].push_back(QPixmap(":/img/img/pacmanu1"));
    pics[0].push_back(QPixmap(":/img/img/pacmanu2"));
    pics[1].push_back(QPixmap(":/img/img/pacmand1"));
    pics[1].push_back(QPixmap(":/img/img/pacmand2"));
    pics[2].push_back(QPixmap(":/img/img/pacmanl1"));
    pics[2].push_back(QPixmap(":/img/img/pacmanl2"));
    pics[3].push_back(QPixmap(":/img/img/pacmanr1"));
    pics[3].push_back(QPixmap(":/img/img/pacmanr2"));
    setPixmap(pics[3][0].scaled(50, 50, Qt::KeepAspectRatio));
    direction = 3;
    keyDirection = 3;
    picsArg = 0;
}

void Pacman::keyPressEvent(QKeyEvent *event){
    // pacman moves
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
        keyDirection = 0;
        if(direction == 1){
            direction = 0;
        }
    }
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
        keyDirection = 1;
        if(direction == 0){
            direction = 1;
        }
    }
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        keyDirection = 2;
        if(direction == 3){
            direction = 2;
        }
    }
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        keyDirection = 3;
        if(direction == 2){
            direction = 3;
        }
    }
}

void Pacman::move(){
    if(direction == 0){
        setPos(x(), y() - 2);
    }
    if(direction == 1){
        setPos(x(), y() + 2);
    }
    if(direction == 2){
        setPos(x() - 2, y());
    }
    if(direction == 3){
        setPos(x() + 2, y());
    }
    if(canChange() && direction != keyDirection){
        direction = keyDirection;
        setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
    }
    if(isWall()){
        direction = 4;
        keyDirection = 4;
    }
    if(x() > 792){
        setPos(-40, 342);
    }
    if(x() < -40){
        setPos(792, 342);
    }
}

void Pacman::changePics(){
    picsArg = picsArg * -1 + 1;
    if(direction < 4)
    setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

bool Pacman::canChange(){
    if(keyDirection == 4)   return true;
    int i = 0, j = 0;
    bool checkX = false, checkY = false;
    float blocksX[] = {10.0, 74.0, 170.0, 252.0, 334.0, 418.0, 500.0, 584.0, 678.0, 740.0};
    float blocksY[] = {8.0, 110.0, 194.0, 272.0, 342.0, 416.0, 492.0, 576.0, 660.0, 742.0};
        
    for (int k = 0; k < 10; k++){
        if (x() == blocksX[k]){
            i = k;
            checkX = true;
        }
    }

    for (int k = 0; k < 10; k++){
        if (y() == blocksY[k]){
            j = k;
            checkY = true;
        }
    }

    if(checkX && checkY && mapDirection[i][j][keyDirection]){
        return true;
    }
    else{
        return false;
    }
}

bool Pacman::isWall(){
    if(direction == 4)   return true;
    int i = 0, j = 0;
    bool checkX = false, checkY = false;
    float blocksX[] = {10.0, 74.0, 170.0, 252.0, 334.0, 418.0, 500.0, 584.0, 678.0, 740.0};
    float blocksY[] = {8.0, 110.0, 194.0, 272.0, 342.0, 416.0, 492.0, 576.0, 660.0, 742.0};
        
    for (int k = 0; k < 10; k++){
        if (x() == blocksX[k]){
            i = k;
            checkX = true;
        }
    }

    for (int k = 0; k < 10; k++){
        if (y() == blocksY[k]){
            j = k;
            checkY = true;
        }
    }
    
    if(checkX && checkY && !mapDirection[i][j][direction]){
        return true;
    }
    else{
        return false;
    }
}
