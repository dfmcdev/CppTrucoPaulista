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
    void SetPlayerCardInRound();
    void SetIACardInRound();
    void SetScorePlayer(double Score);
    void SetScoreIA(double Score);

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
