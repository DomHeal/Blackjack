#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <QDebug>

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/blackjack_table.png");
    ui->tableLabel->setPixmap(pix);
    ui->tableLabel->lower();
    ui->stickButton->setEnabled(false);
    this->statusBar()->setSizeGripEnabled(false);
    this->setFixedSize(800,500);
}


static int player_score = 0;
static int computer_score = 0;
int computer_wins = 0;
int player_wins = 0;



PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::on_twistButton_clicked()
{
    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap draw(":/images/images/draw.png");
    int number = rand() % 10 + 1;
    ui->playercurrentLabel->setText("Current Card: " + QString::number(number));
    player_score += number;
    ui->playertotalLabel->setText("Total: " + QString::number(player_score));

    // if player bust
    if (player_score > 21){
        ui->statusLabel->setText("Bust!");
        ui->twistButton->setEnabled(false);

        //Generating Computer score
        int score = 0;
        while (score < 16){
            score += rand() % 10 + 1;

        }
        computer_score = score;
        ui->computerScoreLabel->setText("Computer: " + QString::number(computer_score));

        // if computer bust
        if (computer_score > 21){
            ui->computerStatusLabel->setText("Bust!");
        }
        else{
            ui->computerStatusLabel->setText("Stick!");
        }

        // if same score or both bust
        if (computer_score == player_score || (computer_score > 21 && player_score > 21)){
            //ui->outcomeLabel->setText("Its a Draw!");
            ui->outcomeLabel->setPixmap(draw);
        }
        // if both players are not bust AND computer is larger than player
        else if ((computer_score < 22 && player_score < 22 && computer_score > player_score) || (player_score > 21 && computer_score < 22 )){
            //ui->outcomeLabel->setText("Computer Win");
            ui->outcomeLabel->setPixmap(lose);
            computer_wins++;;
        }
        else{
            //ui->outcomeLabel->setText("You Win");
            ui->outcomeLabel->setPixmap(win);
            player_wins++;
        }
        ui->outcomeLabel->raise();

    }
    if (player_score > 15 && player_score < 22){
        ui->stickButton->setEnabled(true);
    }
    else {
        ui->stickButton->setEnabled(false);
        ui->playagainButton->setEnabled(true);
    }
    ui->statusbar->showMessage("Player " + QString::number(player_wins) + " - Gamescore - " + "Computer " + QString::number(computer_wins));
}

void PlayWindow::on_stickButton_clicked()
{
    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap draw(":/images/images/draw.png");
    ui->statusLabel->setText("Stick");
    ui->playagainButton->setEnabled(true);
    ui->twistButton->setEnabled(false);
    ui->stickButton->setEnabled(false);
    int score = 0;
    while (score < 16){
        score += rand() % 10 + 1;
    }
    computer_score = score;
    ui->computerScoreLabel->setText("Computer: " + QString::number(computer_score));

    //if computer is bust
    if (score > 21){
        ui->computerStatusLabel->setText("Bust!");
    } else{
        ui->computerStatusLabel->setText("Stick");
    }
    // if same score or both bust
    if (computer_score == player_score || (computer_score > 21 && player_score > 21)){
        ui->outcomeLabel->setPixmap(draw);
    }
    // if both players are not bust AND computer is larger than player
    else if ((computer_score < 22 && player_score < 22 && computer_score > player_score) || (player_score > 21 && computer_score < 22 )){
        ui->outcomeLabel->setPixmap(lose);;
        computer_wins++;
    }
    // else, player wins
    else{
        ui->outcomeLabel->setPixmap(win);
        player_wins++;
    }
    ui->statusbar->showMessage("Player " + QString::number(player_wins) + " - Gamescore - " + "Computer " + QString::number(computer_wins));
}

void PlayWindow::on_playagainButton_clicked()
{
    //Clear Labels and Variables
    player_score = 0;
    computer_score = 0;

    ui->playercurrentLabel->setText("Card: " + QString::number(0));
    ui->playertotalLabel->setText("Total: " + QString::number(0));

    ui->twistButton->setEnabled(true);
    ui->playagainButton->setEnabled(false);
    ui->stickButton->setEnabled(false);
    ui->outcomeLabel->clear();
    ui->computerStatusLabel->setText("");
    ui->statusLabel->setText("");
    ui->computerScoreLabel->setText("Computer: " + QString::number(0));

}

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

