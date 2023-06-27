#ifndef CYAN_H
#define CYAN_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class Cyan : public Ghost
{
public:
    Cyan();
    virtual void move();

};
#endif // CYAN_H
