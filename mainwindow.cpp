#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 150, 150);
    ui->graphicsView->setScene(scene);

    uav = scene->addEllipse(0, 0, 20, 20, QPen(Qt::black), QBrush(Qt::red));
    uav->setPos(5, 65);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveUAV);

    ui->sliderSpeed->setMinimum(1);
    ui->sliderSpeed->setMaximum(10);
    ui->sliderSpeed->setValue(speed);

    connect(ui->sliderSpeed, &QSlider::valueChanged, this, [this](int v) {
        speed = v;
        ui->labelSpeed->setText(QString("Скорость: %1").arg(speed));
    });

    ui->labelSpeed->setText(QString("Скорость: %1").arg(speed));
    ui->btnStartPause->setText("Старт");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveUAV()
{
    x += speed;
    if (x > 750) x = 50;
    uav->setPos(x, 50);
}

void MainWindow::on_btnStartPause_clicked()
{
    if (timer->isActive())
    {
        timer->stop();
        ui->btnStartPause->setText("Старт");
    }
    else
    {
        timer->start(20);
        ui->btnStartPause->setText("Пауза");
    }
}