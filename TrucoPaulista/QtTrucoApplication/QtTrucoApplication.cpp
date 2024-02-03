#include "QtTrucoApplication.h"

QtTrucoApplication::QtTrucoApplication(QWidget *parent)
    : QWidget(parent)
{
    PlayerRound = 0;
    IARound = 0;
    ui.setupUi(this);
    connect(ui.StartPushButton, SIGNAL(clicked()), this, SLOT(StartClicked()));
    connect(ui.NewGamePushButton, SIGNAL(clicked()), this, SLOT(NewGameClicked()));
    connect(ui.PokerPushButton, SIGNAL(clicked()), this, SLOT(PokerClicked()));

    connect(ui.PlayerCardOne, SIGNAL(clicked()), this, SLOT(PlayerCardOneClicked()));
    connect(ui.PlayerCardTwo, SIGNAL(clicked()), this, SLOT(PlayerCardTwoClicked()));
    connect(ui.PlayerCardThree, SIGNAL(clicked()), this, SLOT(PlayerCardThreeClicked()));

    connect(ui.IACardOne, SIGNAL(clicked()), this, SLOT(IACardOneClicked()));
    connect(ui.IACardTwo, SIGNAL(clicked()), this, SLOT(IACardTwoClicked()));
    connect(ui.IACardThree, SIGNAL(clicked()), this, SLOT(IACardThreeClicked()));

    SetScorePlayer(5);
    SetScoreIA(10);

}

QtTrucoApplication::~QtTrucoApplication()
{}

void QtTrucoApplication::StartClicked()
{

}

void QtTrucoApplication::NewGameClicked()
{

}
void QtTrucoApplication::PokerClicked()
{

}

void QtTrucoApplication::PlayerCardOneClicked()
{
    SetPlayerCardInRound();
}
void QtTrucoApplication::PlayerCardTwoClicked()
{
    SetPlayerCardInRound();
}
void QtTrucoApplication::PlayerCardThreeClicked()
{
    SetPlayerCardInRound();
}

void QtTrucoApplication::IACardOneClicked()
{
    SetIACardInRound();
}
void QtTrucoApplication::IACardTwoClicked()
{
    SetIACardInRound();
}
void QtTrucoApplication::IACardThreeClicked()
{
    SetIACardInRound();
}

void QtTrucoApplication::SetPlayerCardInRound()
{
    PlayerRound++;
    if (PlayerRound == 1)
    {
        ui.PlayerCardRoundOne->setPixmap(ui.PlayerCardOne->pixmap());
    }
    else if (PlayerRound == 2)
    {
        ui.PlayerCardRoundTwo->setPixmap(ui.PlayerCardTwo->pixmap());
    }
    else
    {
        ui.PlayerCardRoundThree->setPixmap(ui.PlayerCardThree->pixmap());
    }
}

void QtTrucoApplication::SetIACardInRound()
{
    IARound++;
    if (IARound == 1)
    {
        ui.IACardRoundOne->setPixmap(ui.IACardOne->pixmap());
    }
    else if (IARound == 2)
    {
        ui.IACardRoundTwo->setPixmap(ui.IACardTwo->pixmap());
    }
    else
    {
        ui.IACardRoundThree->setPixmap(ui.IACardThree->pixmap());
    }
}

void QtTrucoApplication::SetScorePlayer(double Score)
{
    ui.ScorePlayer->display(ui.ScorePlayer->value() + Score);
}
void QtTrucoApplication::SetScoreIA(double Score)
{
    ui.ScoreIA->display(ui.ScoreIA->value() + Score);
}

