#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtTrucoApplication.h"

class QtTrucoApplication : public QWidget
{
    Q_OBJECT

public:
    QtTrucoApplication(QWidget *parent = nullptr);
    ~QtTrucoApplication();

private:
    Ui::QtTrucoApplicationClass ui;
    int PlayerRound;
    int IARound;
    bool IACardInvalid[3] = { false, false, false };
    bool PlayerCardInvalid[3] = { false, false, false };
    void SetPlayerCardInRound(int card);
    void SetIACardInRound(int card);
    void SetScorePlayer(double Score);
    void SetScoreIA(double Score);
    void InitializeCards();
    QPixmap GetImageCardPlayer(int card);
    void SetEmptyImageCardPlayer(int card);
    QPixmap GetImageCardIA(int card);
    void SetEmptyImageCardIA(int card);


signals:
public slots:
    void StartClicked();
    void NewGameClicked();
    void PokerClicked();
    void PlayerCardOneClicked();
    void PlayerCardTwoClicked();
    void PlayerCardThreeClicked();
    void IACardOneClicked();
    void IACardTwoClicked();
    void IACardThreeClicked();
};
