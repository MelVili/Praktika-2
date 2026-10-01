#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void moveUAV();
    void on_btnStartPause_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = nullptr;
    QGraphicsEllipseItem *uav = nullptr;
    QTimer *timer = nullptr;
    int x = 50;
    int speed = 2;
};

#endif