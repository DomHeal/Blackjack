#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/bg.jpg");
    ui->pictureLabel->setPixmap(pix);
    ui->pictureLabel->setFixedSize(480,360);
    ui->pictureLabel->lower();
    this->setFixedSize(480,400);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
   QApplication::quit();
}

void MainWindow::on_playButton_clicked()
{
    playwindow = new PlayWindow(this);
    playwindow->show();
    this->hide();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
