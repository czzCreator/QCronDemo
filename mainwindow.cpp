#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "qcron.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCron *pCron = new QCron("1/3 8-12 * * * *");
    //QCron cron("* 8-11,14-17 * * 1-5 *");

    if(pCron->isValid())
    {
        qDebug() << "cron.isValid()";
    }

    connect(pCron, SIGNAL(activated()),this,SLOT(onActivation()));
    connect(pCron, SIGNAL(deactivated()),this,SLOT(onDeactivated()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void    MainWindow::onActivation()
{
    qDebug() << "active";

}

void    MainWindow::onDeactivated()
{
    qDebug() << "deactive";
}

