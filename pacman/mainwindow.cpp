#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Win->setVisible(false);
    ui->Lose->setVisible(false);

    scene = new QGraphicsScene(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    scene->addPixmap(QPixmap(":/img/img/background"));
    ui->graphicsView->setScene(scene);

    // add small points to scene
    for(int i = 0; i < 29; i++){
        for(int j = 0; j < 26; j++){
            Smallpoint[i][j] = new smallpoint(18 + j * 28.5, 8 + i * 26.1, i, j);
            scene->addItem(Smallpoint[i][j]);
        }
    }
    smallpointNum = 0;

    // add big points to scene
    float poses[4][2] = {{18, 60.2}, {730.5, 60.2}, {18, 582.2}, {730.5, 582.2}};
    for (int i = 0; i < 4; i++) {
        Bigpoint[i] = new bigpoint();
        Bigpoint[i]->setPos(poses[i][0], poses[i][1]);
        
        scene->addItem(Bigpoint[i]);
    }
    bigpointNum = 0;

    // add pacman to scene
    Pacman = new pacman();
    Pacman->setPos(376, 576);
    Pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    Pacman->setFocus();
    scene->addItem(Pacman);

    // add ghosts to scene
    ghosts[0] = new red();
    ghosts[1] = new pink();
    ghosts[2] = new cyan();
    ghosts[3] = new orange();
    for (int i = 0; i < 4; i++) scene->addItem(ghosts[i]);
    
    // point lable
    point = new QLabel(this);
    point->setGeometry(0, 0, 49, 17);
    point->setFont(QFont("Ubuntu Regular", 14));
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    point->setPalette(pa);
    point->setVisible(false);

    // cherry
    Cherry = new cherry();
    scene->addItem(Cherry);

    srandom(time(NULL)); // seed
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(allMove()));
    timer1->start(18);
    
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(allChangePics()));
    timer2->start(100);
    
    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(bigpointChangePics()));
    timer3->start(200);
    
    for (int i = 0; i < 4; i++) modes[i] = 0;
    addpoint = 200;
    pause = false;
    isBonus2 = false;
    
    timer8 = new QTimer(this);
    timer8->setSingleShot(true);
    connect(timer8, SIGNAL(timeout()), this, SLOT(pauseTime()));
    timer8->start(2000);
    
    timer9 = new QTimer(this); /* ####################### */
    connect(timer9, SIGNAL(timeout()), this, SLOT(slowMove()));
    timer9->start(32);
    
    timer10 = new QTimer(this);
    timer10->setSingleShot(true);
    connect(timer10, SIGNAL(timeout()), this, SLOT(cherrySetVisibleTrue()));
    timer10->start(60000);
    
    pause = true;
    for (int i = 0; i < 4; i++) slows[i] = true;
}

void MainWindow::allMove(){
    if(!pause){
        Pacman->move();
        for (int i = 0; i < 4; i++)
            (ghosts[i])->move();
            
        // collide small points
        for(int i = 0; i < 29; i++){
            for(int j = 0; j < 26; j++){
                bool isCollided = Pacman->collidesWithItem(Smallpoint[i][j]);
                if(isCollided){
                    Smallpoint[i][j]->collide();
                    ui->lcdNumber->display(ui->lcdNumber->value() + 10);
                    smallpointNum++;
                }
            }
        }

        // collide big points
        for(int i = 0; i < 4; i++){
            bool isCollided = Pacman->collidesWithItem(Bigpoint[i]);
            if(isCollided){
                if(!q.empty()){ /* ######################## */
                    int temp = q.front();
                    q.pop_front();
                    delete timer4[temp];
                    delete timer5[temp];
                    delete timer6[temp];
                    delete timer7[temp];
                    addpoint = 200;
                    isBonus2 = false;
                }

                Bigpoint[i]->collide();
                ui->lcdNumber->display(ui->lcdNumber->value() + 50);

                for (int i = 0; i < 4; i++) modes[i] = 1;

                timer4[i] = new QTimer(this);
                timer4[i]->setSingleShot(true);
                connect(timer4[i], SIGNAL(timeout()), this, SLOT(bonusTime()));
                timer4[i]->start(9000);

                timer5[i] = new QTimer(this);
                timer5[i]->setSingleShot(true);
                connect(timer5[i], SIGNAL(timeout()), this, SLOT(bonusTime2()));
                timer5[i]->start(6500);

                timer6[i] = new QTimer(this);
                connect(timer6[i], SIGNAL(timeout()), this, SLOT(flicker()));
                timer6[i]->start(200);

                timer7[i] = new QTimer(this);
                connect(timer7[i], SIGNAL(timeout()), this, SLOT(ghostmove2()));
                timer7[i]->start(32);

                q.push_back(i);
                bigpointNum++;
            }
        }

        // collided list
        bool isCollided[4];
        for (int i = 0; i < 4; i++)
            isCollided[i] = Pacman->collidesWithItem(ghosts[i]);

        if((isCollided[0] && !modes[0]) || (isCollided[1] && !modes[1])
        || (isCollided[2] && !modes[2]) || (isCollided[3] && !modes[3])){
            pause = true;
            ui->Lose->setVisible(true);
        }
        

        for (int i = 0; i < 4; i++) {
            if(isCollided[i] && modes[i]){
                modes[i] = 0; // exit bonus

                point->setText(QString::number(addpoint));
                point->setGeometry((ghosts[i])->x(), (ghosts[i])->y() + 30, 49, 17);
                point->setVisible(true);
                ui->lcdNumber->display(ui->lcdNumber->value() + addpoint);
                pause = true;
                // pause for 1 sec
                timer8 = new QTimer(this);
                timer8->setSingleShot(true);
                connect(timer8, SIGNAL(timeout()), this, SLOT(getPointTime()));
                timer8->start(1000);

                (ghosts[i])->setPos(376, 342); // set to home
                ghosts[i]->setDirection(0);
                slows[i] = true;
                addpoint *= 2;
            }
        }

        bool isCollidedCherry = Pacman->collidesWithItem(Cherry);
        if(isCollidedCherry){
            Cherry->changePics(1);
            ui->lcdNumber->display(ui->lcdNumber->value() + 100);
        }
        if(smallpointNum == 242 && bigpointNum == 4){
            pause = true;
            ui->Win->setVisible(true);
        }
    }
}

void MainWindow::allChangePics(){
    if(!pause){
        Pacman->changePics();

        for (int i = 0; i < 4; i++){
            if(modes[i] == 0){
                (ghosts[i])->changePics();
            }
            else if(modes[i] == 1){
                (ghosts[i])->changePics2();
            }
            else if(modes[i] == 2){
                (ghosts[i])->changePics3();
            }
        }
    }
}

void MainWindow::bigpointChangePics(){
    if(!pause){
        for (int i = 0; i < 4; i++)
            Bigpoint[i]->changePics();
    }
}

void MainWindow::bonusTime(){
    int i = q.front(); /* ########## */
    q.pop_front();
    for (int i = 0; i < 4; i++) modes[i] = 0;
    isBonus2 = false;
    addpoint = 200;
    delete timer4[i];
    delete timer5[i];
    delete timer6[i];
    delete timer7[i];
}

void MainWindow::bonusTime2(){
    isBonus2 = true;
}

void MainWindow::flicker(){
    if(!pause){
        if(isBonus2){
            for (int i = 0; i < 4; i++){
                if(modes[i] == 1){
                    modes[i] = 2;
                }
                else if(modes[i] == 2){
                    modes[i] = 1;
                }
            }
        }
    }
}

void MainWindow::ghostmove2(){
    if(!pause){
        for (int i = 0; i < 4; i++){
            if((modes[i] == 1 || modes[i] == 2) && !slows[i])
                (ghosts[i])->move();
        }
    }  
}

void MainWindow::getPointTime(){
    delete timer8;
    point->setVisible(false);
    pause = false;
}

void MainWindow::pauseTime(){
    delete timer8;
    ui->ready->setVisible(false);
    pause = false;
}

void MainWindow::slowMove(){
    if(!pause){
        for (int i = 0; i < 4; i++){
            if(slows[i])
                (ghosts[i])->move();
        }
    }

    for (int i = 0; i < 4; i++){
        if((ghosts[i])->x() == 376.0 && (ghosts[i])->y() == 272.0){
            slows[i] = false;
        }
    }
}

void MainWindow::cherrySetVisibleTrue(){
    Cherry->changePics(0);

    connect(timer10, SIGNAL(timeout()), this, SLOT(cherrySetVisibleFalse()));
    timer10->start(10000);
}

void MainWindow::cherrySetVisibleFalse(){
    Cherry->changePics(1);

    connect(timer10, SIGNAL(timeout()), this, SLOT(cherrySetVisibleTrue()));
    timer10->start(60000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
