#ifndef PINK_H
#define PINK_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class Pink : public Ghost
{
public:
    Pink();
    virtual void move();

};
#endif // PINK_H
