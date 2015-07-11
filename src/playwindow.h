#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

private slots:
    void on_twistButton_clicked();

    void on_stickButton_clicked();

    void on_playagainButton_clicked();

    void on_actionQuit_triggered();

private:
    Ui::PlayWindow *ui;
};

#endif // PLAYWINDOW_H
