#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(500, 200);
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");

    if ((time.second()%2)==0)
    {
        text[2] = ' ';
        text[5] = ' ';
    }
    ui->label->setText(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

