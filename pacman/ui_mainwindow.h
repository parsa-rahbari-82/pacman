/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QLabel *score;
    QLabel *Win;
    QLabel *Lose;
    QLabel *ready;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(812, 857);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(5, 50, 802, 802));
        graphicsView->setFocusPolicy(Qt::StrongFocus);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 10, 141, 31));
        lcdNumber->setDigitCount(9);
        lcdNumber->setSegmentStyle(QLCDNumber::Outline);
        score = new QLabel(centralWidget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(5, 8, 81, 31));
        QFont font;
        font.setPointSize(16);
        score->setFont(font);
        score->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Win = new QLabel(centralWidget);
        Win->setObjectName(QString::fromUtf8("Win"));
        Win->setGeometry(QRect(257, 370, 300, 150));
        Win->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Win.png")));
        Win->setScaledContents(true);
        Lose = new QLabel(centralWidget);
        Lose->setObjectName(QString::fromUtf8("Lose"));
        Lose->setGeometry(QRect(257, 370, 300, 150));
        Lose->setPixmap(QPixmap(QString::fromUtf8(":/img/img/Lose.png")));
        Lose->setScaledContents(true);
        ready = new QLabel(centralWidget);
        ready->setObjectName(QString::fromUtf8("ready"));
        ready->setGeometry(QRect(288, 460, 240, 64));
        ready->setPixmap(QPixmap(QString::fromUtf8(":/img/img/ready.png")));
        ready->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        score->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        Win->setText(QString());
        Lose->setText(QString());
        ready->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
