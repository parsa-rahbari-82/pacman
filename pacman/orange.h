#ifndef ORANGE_H
#define ORANGE_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class Orange : public Ghost
{
public:
    Orange();
    virtual void move();

};
#endif // ORANGE_H
