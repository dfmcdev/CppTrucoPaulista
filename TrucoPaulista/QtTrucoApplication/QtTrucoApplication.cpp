#include "QtTrucoApplication.h"
#include "Util.h"

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
    InitializeCards();

}

QtTrucoApplication::~QtTrucoApplication()
{}

void QtTrucoApplication::InitializeCards()
{
    QPixmap pixmap;
    string path = Util::GetCardImage(rand() % 15, Util::Suits::Clubs);
    QString qPath = QString::fromStdString(path);
    pixmap.load(qPath);

    ui.IACardOne->setPixmap(pixmap);

    path = Util::GetCardImage(rand() % 15, Util::Suits::Hearts);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);
    ui.IACardTwo->setPixmap(pixmap);

    path = Util::GetCardImage(rand() % 15, Util::Suits::Diamonds);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);
    ui.IACardThree->setPixmap(pixmap);

    path = Util::GetCardImage(rand() % 15, Util::Suits::Spades);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);
    ui.ViraCard->setPixmap(pixmap);

    path = Util::GetCardImage(0, Util::Suits::Empty);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);

    ui.PlayerCardRoundOne->setPixmap(pixmap);
    ui.PlayerCardRoundTwo->setPixmap(pixmap);
    ui.PlayerCardRoundThree->setPixmap(pixmap);

    ui.IACardRoundOne->setPixmap(pixmap);
    ui.IACardRoundTwo->setPixmap(pixmap);
    ui.IACardRoundThree->setPixmap(pixmap);

    path = Util::GetCardImage(rand()%15, Util::Suits::Clubs);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);

    ui.PlayerCardOne->setPixmap(pixmap);

    path = Util::GetCardImage(rand() % 15, Util::Suits::Hearts);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);
    ui.PlayerCardTwo->setPixmap(pixmap);

    path = Util::GetCardImage(rand() % 15, Util::Suits::Diamonds);
    qPath = QString::fromStdString(path);
    pixmap.load(qPath);
    ui.PlayerCardThree->setPixmap(pixmap);

    IARound = 0;
    PlayerRound = 0;
    PlayerCardInvalid[0] = false;
    PlayerCardInvalid[1] = false;
    PlayerCardInvalid[2] = false;
    IACardInvalid[0] = false;
    IACardInvalid[1] = false;
    IACardInvalid[2] = false;
}

void QtTrucoApplication::StartClicked()
{

}

void QtTrucoApplication::NewGameClicked()
{
    InitializeCards();

}
void QtTrucoApplication::PokerClicked()
{

}

void QtTrucoApplication::PlayerCardOneClicked()
{
    SetPlayerCardInRound(1);
}
void QtTrucoApplication::PlayerCardTwoClicked()
{
    SetPlayerCardInRound(2);
}
void QtTrucoApplication::PlayerCardThreeClicked()
{
    SetPlayerCardInRound(3);
}

void QtTrucoApplication::IACardOneClicked()
{
    SetIACardInRound(1);
}
void QtTrucoApplication::IACardTwoClicked()
{
    SetIACardInRound(2);
}
void QtTrucoApplication::IACardThreeClicked()
{
    SetIACardInRound(3);
}

QPixmap QtTrucoApplication::GetImageCardPlayer(int card)
{
    if (card == 1)
    {
        return ui.PlayerCardOne->pixmap();
    }
    else if (card == 2)
    {
        return ui.PlayerCardTwo->pixmap();
    }
    else
    {
        return ui.PlayerCardThree->pixmap();
    }
}

void QtTrucoApplication::SetEmptyImageCardPlayer(int card)
{
    QPixmap pixmap;
    string path = Util::GetCardImage(0, Util::Suits::Empty);
    QString qPath = QString::fromStdString(path);
    pixmap.load(qPath);

    if (card == 1)
    {
        ui.PlayerCardOne->setPixmap(pixmap);
    }
    else if (card == 2)
    {
        ui.PlayerCardTwo->setPixmap(pixmap);
    }
    else
    {
        ui.PlayerCardThree->setPixmap(pixmap);
    }
}

QPixmap QtTrucoApplication::GetImageCardIA(int card)
{
    if (card == 1)
    {
        return ui.IACardOne->pixmap();
    }
    else if (card == 2)
    {
        return ui.IACardTwo->pixmap();
    }
    else
    {
        return ui.IACardThree->pixmap();
    }

}
void QtTrucoApplication::SetEmptyImageCardIA(int card)
{
    QPixmap pixmap;
    string path = Util::GetCardImage(0, Util::Suits::Empty);
    QString qPath = QString::fromStdString(path);
    pixmap.load(qPath);

    if (card == 1)
    {
        ui.IACardOne->setPixmap(pixmap);
    }
    else if (card == 2)
    {
        ui.IACardTwo->setPixmap(pixmap);
    }
    else
    {
        ui.IACardThree->setPixmap(pixmap);
    }

}

void QtTrucoApplication::SetPlayerCardInRound(int card)
{
    if (PlayerRound == 0 && !PlayerCardInvalid[card - 1])
    {
        ui.PlayerCardRoundOne->setPixmap(GetImageCardPlayer(card));
        SetEmptyImageCardPlayer(card);
        PlayerCardInvalid[card-1] = true;
        PlayerRound++;
    }
    else if (PlayerRound == 1 && !PlayerCardInvalid[card - 1])
    {
        ui.PlayerCardRoundTwo->setPixmap(GetImageCardPlayer(card));
        SetEmptyImageCardPlayer(card);
        PlayerCardInvalid[card-1] = true;
        PlayerRound++;
        
    }
    else if(PlayerRound == 2 && !PlayerCardInvalid[card - 1])
    {
        ui.PlayerCardRoundThree->setPixmap(GetImageCardPlayer(card));
        SetEmptyImageCardPlayer(card);
        PlayerCardInvalid[card-1] = true;
        PlayerRound++;
    }
}

void QtTrucoApplication::SetIACardInRound(int card)
{   
    if (IARound == 0 && !IACardInvalid[card - 1])
    {
        ui.IACardRoundOne->setPixmap(GetImageCardIA(card));
        SetEmptyImageCardIA(card);
        IACardInvalid[card - 1] = true;
        IARound++;
    }
    else if (IARound == 1 && !IACardInvalid[card - 1])
    {
        ui.IACardRoundTwo->setPixmap(GetImageCardIA(card));
        SetEmptyImageCardIA(card);
        IACardInvalid[card - 1] = true;
        IARound++;
    }
    else if(IARound == 2 && !IACardInvalid[card - 1])
    {
        ui.IACardRoundThree->setPixmap(GetImageCardIA(card));
        SetEmptyImageCardIA(card);
        IACardInvalid[card - 1] = true;
        IARound++;
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

