#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>

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
            ui->outcomeLabel->setText("Its a Draw!");
        }
        // if both players are not bust AND computer is larger than player
        else if ((computer_score < 22 && player_score < 22 && computer_score > player_score) || (player_score > 21 && computer_score < 22 )){
            ui->outcomeLabel->setText("Computer Win");
            computer_wins++;
            ui->gamescoreLabel->setText(QString::number(player_wins) + " - Gamescore - " + QString::number(computer_wins));
        }
        else{
            ui->outcomeLabel->setText("You Win");
            player_wins++;
            ui->gamescoreLabel->setText(QString::number(player_wins) + " - Gamescore - " + QString::number(computer_wins));
        }

    }
    if (player_score > 15 && player_score < 22){
        ui->stickButton->setEnabled(true);
    }
    else {
        ui->stickButton->setEnabled(false);
        ui->playagainButton->setEnabled(true);
    }
}

void PlayWindow::on_stickButton_clicked()
{
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
        ui->outcomeLabel->setText("Its a Draw!");
    }
    // if both players are not bust AND computer is larger than player
    else if ((computer_score < 22 && player_score < 22 && computer_score > player_score) || (player_score > 21 && computer_score < 22 )){
        ui->outcomeLabel->setText("Computer Win");
        computer_wins++;
        ui->gamescoreLabel->setText(QString::number(player_wins) + " - Gamescore - " + QString::number(computer_wins));
    }
    // else, player wins
    else{
        ui->outcomeLabel->setText("You Win");
        player_wins++;
        ui->gamescoreLabel->setText(QString::number(player_wins) + " - Gamescore - " + QString::number(computer_wins));
    }

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
    ui->outcomeLabel->setText("");
    ui->computerStatusLabel->setText("");
    ui->statusLabel->setText("");
    ui->computerScoreLabel->setText("Computer: " + QString::number(0));
}

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
