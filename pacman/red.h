#ifndef RED_H
#define RED_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class Red : public Ghost
{
public:
    Red();
    virtual void move();

};
#endif // RED_H
