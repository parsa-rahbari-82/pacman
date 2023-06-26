#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <QTimer>
#include <QString>
#include <QLabel>
#include <cstdlib>
#include <ctime>
#include <QQueue>
#include <unistd.h>
#include "pacman.h"
#include "smallpoint.h"
#include "bigpoint.h"
#include "ghost.h"
#include "red.h"
#include "pink.h"
#include "cyan.h"
#include "orange.h"
#include "cherry.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void allMove();
    void allChangePics();
    void bigpointChangePics();
    void bonusTime();
    void bonusTime2();
    void flicker();
    void ghostmove2();
    void getPointTime();
    void pauseTime();
    void slowMove();
    void cherrySetVisibleTrue();
    void cherrySetVisibleFalse();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    smallpoint *Smallpoint[29][26];
    bigpoint *Bigpoint[4];
    pacman *Pacman;
    ghost *ghosts[4];
    cherry *Cherry;

    QTimer *timer1; //for move
    QTimer *timer2; //for changePics
    QTimer *timer3; //for bigpoint
    QTimer *timer4[4]; //for bonus time 1
    QTimer *timer5[4]; //for bonus time 2
    QTimer *timer6[4]; //for flicker
    QTimer *timer7[4]; //for move in bonus time
    QTimer *timer8; //for point, pause time
    QTimer *timer9; //for slow move
    QTimer *timer10; //for cherry setVisible
    int smallpointNum;
    int bigpointNum;
    
    // mode: 0 := not bonus time, 1 := bonus time, 2 := bonus time2
    int modes[4];
    QLabel *point;
    QQueue<int> q;
    int addpoint;
    bool pause;
    bool isBonus2;

    bool slows[4];
};

#endif // MAINWINDOW_H
