#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
#include <QDebug>
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
    QList<QPixmap> cardHolder;
    int deckValues[52];


public slots:
    void loadList();

    void computerTurn();
private slots:
    void on_twistButton_clicked();

    void on_stickButton_clicked();

    void on_playagainButton_clicked();

    void on_actionQuit_triggered();


private:
    Ui::PlayWindow *ui;

protected:
};



#endif // PLAYWINDOW_H
