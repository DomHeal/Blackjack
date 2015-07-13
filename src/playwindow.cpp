#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <QDebug>
#include <QList>
#include <map>


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


    loadList();
}


static int player_score = 0;
static int computer_score = 0;
int computer_wins = 0;
int player_wins = 0;
int holdingCardCount = 1;
int holdingCardCountComputer = 1;

void PlayWindow::loadList(){

    // Clear List
    cardHolder.clear();

    // Load in Spades
    QPixmap card1(":/images/images/cards/ace_of_spades.png");
    QPixmap card2(":/images/images/cards/2_of_spades.png");
    QPixmap card3(":/images/images/cards/3_of_spades.png");
    QPixmap card4(":/images/images/cards/4_of_spades.png");
    QPixmap card5(":/images/images/cards/5_of_spades.png");
    QPixmap card6(":/images/images/cards/6_of_spades.png");
    QPixmap card7(":/images/images/cards/7_of_spades.png");
    QPixmap card8(":/images/images/cards/8_of_spades.png");
    QPixmap card9(":/images/images/cards/9_of_spades.png");
    QPixmap card10(":/images/images/cards/10_of_spades.png");
    QPixmap card11(":/images/images/cards/jack_of_spades2.png");
    QPixmap card12(":/images/images/cards/queen_of_spades2.png");
    QPixmap card13(":/images/images/cards/king_of_spades2.png");

    // Load in Hearts

    QPixmap card14(":/images/images/cards/ace_of_hearts.png");
    QPixmap card15(":/images/images/cards/2_of_hearts.png");
    QPixmap card16(":/images/images/cards/3_of_hearts.png");
    QPixmap card17(":/images/images/cards/4_of_hearts.png");
    QPixmap card18(":/images/images/cards/5_of_hearts.png");;
    QPixmap card19(":/images/images/cards/6_of_hearts.png");
    QPixmap card20(":/images/images/cards/7_of_hearts.png");
    QPixmap card21(":/images/images/cards/8_of_hearts.png");
    QPixmap card22(":/images/images/cards/9_of_hearts.png");
    QPixmap card23(":/images/images/cards/10_of_hearts.png");
    QPixmap card24(":/images/images/cards/jack_of_hearts2.png");
    QPixmap card25(":/images/images/cards/queen_of_hearts2.png");
    QPixmap card26(":/images/images/cards/king_of_hearts2.png");

    // Load in clubs

    QPixmap card27(":/images/images/cards/ace_of_clubs.png");
    QPixmap card28(":/images/images/cards/2_of_clubs.png");
    QPixmap card29(":/images/images/cards/3_of_clubs.png");
    QPixmap card30(":/images/images/cards/4_of_clubs.png");
    QPixmap card31(":/images/images/cards/5_of_clubs.png");
    QPixmap card32(":/images/images/cards/6_of_clubs.png");
    QPixmap card33(":/images/images/cards/7_of_clubs.png");
    QPixmap card34(":/images/images/cards/8_of_clubs.png");
    QPixmap card35(":/images/images/cards/9_of_clubs.png");
    QPixmap card36(":/images/images/cards/10_of_clubs.png");
    QPixmap card37(":/images/images/cards/jack_of_clubs2.png");
    QPixmap card38(":/images/images/cards/queen_of_clubs2.png");
    QPixmap card39(":/images/images/cards/king_of_clubs2.png");

    // Load in diamonds

    QPixmap card40(":/images/images/cards/ace_of_diamonds.png");
    QPixmap card41(":/images/images/cards/2_of_diamonds.png");
    QPixmap card42(":/images/images/cards/3_of_diamonds.png");
    QPixmap card43(":/images/images/cards/4_of_diamonds.png");
    QPixmap card44(":/images/images/cards/5_of_diamonds.png");
    QPixmap card45(":/images/images/cards/6_of_diamonds.png");
    QPixmap card46(":/images/images/cards/7_of_diamonds.png");
    QPixmap card47(":/images/images/cards/8_of_diamonds.png");
    QPixmap card48(":/images/images/cards/9_of_diamonds.png");
    QPixmap card49(":/images/images/cards/10_of_diamonds2.png");
    QPixmap card50(":/images/images/cards/jack_of_diamonds2.png");
    QPixmap card51(":/images/images/cards/queen_of_diamonds2.png");
    QPixmap card52(":/images/images/cards/king_of_diamonds2.png");

    // add Spades to List
    cardHolder.append(card1);
    cardHolder.append(card2);
    cardHolder.append(card3);
    cardHolder.append(card4);
    cardHolder.append(card5);
    cardHolder.append(card6);
    cardHolder.append(card7);
    cardHolder.append(card8);
    cardHolder.append(card9);
    cardHolder.append(card10);
    cardHolder.append(card11);
    cardHolder.append(card12);
    cardHolder.append(card13);

    // add Hearts to List
    cardHolder.append(card14);
    cardHolder.append(card15);
    cardHolder.append(card16);
    cardHolder.append(card17);
    cardHolder.append(card18);
    cardHolder.append(card19);
    cardHolder.append(card20);
    cardHolder.append(card21);
    cardHolder.append(card22);
    cardHolder.append(card23);
    cardHolder.append(card24);
    cardHolder.append(card25);
    cardHolder.append(card26);

    // add clubs to List
    cardHolder.append(card27);
    cardHolder.append(card28);
    cardHolder.append(card29);
    cardHolder.append(card30);
    cardHolder.append(card31);
    cardHolder.append(card32);
    cardHolder.append(card33);
    cardHolder.append(card34);
    cardHolder.append(card35);
    cardHolder.append(card36);
    cardHolder.append(card37);
    cardHolder.append(card38);
    cardHolder.append(card39);

    // add Diamonds to List
    cardHolder.append(card40);
    cardHolder.append(card41);
    cardHolder.append(card42);
    cardHolder.append(card43);
    cardHolder.append(card44);
    cardHolder.append(card45);
    cardHolder.append(card46);
    cardHolder.append(card47);
    cardHolder.append(card48);
    cardHolder.append(card49);
    cardHolder.append(card50);
    cardHolder.append(card51);
    cardHolder.append(card52);

}


PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::on_twistButton_clicked()
{
    int deckValues[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};

    int number = rand() % 52;
    ui->playercurrentLabel->setText("Current Card: " + QString::number(deckValues[number-1]));
    player_score += deckValues[number-1];
    ui->playertotalLabel->setText("Total: " + QString::number(player_score));

    // Which position should the Card be drawn.
    switch(holdingCardCount){
    case 1:
        ui->card1Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 2:
        ui->card2Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 3:
        ui->card3Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 4:
        ui->card4Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 5:
        ui->card5Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 6:
        ui->card6Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 7:
        ui->card7Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 8:
        ui->card8Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 9:
        ui->card9Label->setPixmap(cardHolder.at(number - 1));
        break;
    case 10:
        ui->card10Label->setPixmap(cardHolder.at(number - 1));
        break;

    }
    // increment Card Count for position
    ++holdingCardCount;

    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap draw(":/images/images/draw.png");
    // if player bust
    if (player_score > 21){
        ui->statusLabel->setText("Bust!");
        ui->twistButton->setEnabled(false);

        //Generating Computer score
        computerTurn();
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
    // To prevent users from activating function before the function ending.
    this->setEnabled(false);
    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap draw(":/images/images/draw.png");
    ui->statusLabel->setText("Stick");
    ui->playagainButton->setEnabled(true);
    ui->twistButton->setEnabled(false);
    ui->stickButton->setEnabled(false);

    //Generating Computer score
    computerTurn();

}

void PlayWindow::on_playagainButton_clicked()
{
    //Clear Labels and Variables
    player_score = 0;
    computer_score = 0;
    holdingCardCount = 1;
    holdingCardCountComputer = 1;

    ui->playercurrentLabel->setText("Card: " + QString::number(0));
    ui->playertotalLabel->setText("Total: " + QString::number(0));

    ui->twistButton->setEnabled(true);
    ui->playagainButton->setEnabled(false);
    ui->stickButton->setEnabled(false);
    ui->outcomeLabel->clear();
    ui->computerStatusLabel->setText("");
    ui->statusLabel->setText("");
    ui->computerScoreLabel->setText("Computer: " + QString::number(0));

    // Clear Cards from player table
    ui->card1Label->clear();
    ui->card2Label->clear();
    ui->card3Label->clear();
    ui->card4Label->clear();
    ui->card5Label->clear();
    ui->card6Label->clear();
    ui->card8Label->clear();
    ui->card9Label->clear();
    ui->card10Label->clear();

    ui->card10Label_2->clear();
    ui->card9Label_2->clear();
    ui->card8Label_2->clear();
    ui->card7Label_2->clear();
    ui->card6Label_2->clear();
    ui->card5Label_2->clear();
    ui->card4Label_2->clear();
    ui->card3Label_2->clear();
    ui->card2Label_2->clear();
    ui->card1Label_2->clear();

}

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void PlayWindow::computerTurn(){
    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap draw(":/images/images/draw.png");

    int computer_score = 0;
    while (computer_score < 16){
        computer_score += rand() % 10 + 1;

        ui->computerScoreLabel->setText("Computer: " + QString::number(computer_score));

            switch(holdingCardCountComputer){
                case 1:
                    ui->card10Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 2:
                    ui->card9Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 3:
                    ui->card8Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 4:
                    ui->card7Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 5:
                    ui->card6Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 6:
                    ui->card5Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 7:
                    ui->card4Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 8:
                    ui->card3Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 9:
                    ui->card2Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
                case 10:
                    ui->card1Label_2->setPixmap(cardHolder.at(computer_score - 1));
                    break;
            }
            ++holdingCardCountComputer;
    }




    //if computer is bust
    if (computer_score > 21){
        ui->computerStatusLabel->setText("Bust!");
    } else{
        ui->computerStatusLabel->setText("Stick");
    }
    // if same score or both bust
    if ((computer_score == player_score) || ((computer_score > 21) && (player_score > 21))){
        ui->outcomeLabel->setPixmap(draw);
    }
    // if both players are not bust AND computer is larger than player
    else if (((computer_score < 22) && (player_score < 22) && (computer_score > player_score)) || ((player_score > 21) && computer_score < 22 )){
        ui->outcomeLabel->setPixmap(lose);;
        ++computer_wins;
    }
    // else, player wins
    else{
        ui->outcomeLabel->setPixmap(win);
        ++player_wins;
    }
    ui->statusbar->showMessage("Player " + QString::number(player_wins) + " - Gamescore - " + "Computer " + QString::number(computer_wins));
    this->setEnabled(true);
}
