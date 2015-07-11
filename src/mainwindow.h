#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PlayWindow *playwindow;


private slots:
    void on_closeButton_clicked();

    void on_playButton_clicked();

    void on_actionQuit_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
