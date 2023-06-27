#ifndef CHERRY_H
#define CHERRY_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <cstdlib>

class Cherry : public QGraphicsPixmapItem
{
public:
    Cherry();
    void changePics(int i);

private:
    QList<QPixmap> pics;

};

#endif // CHERRY_H
