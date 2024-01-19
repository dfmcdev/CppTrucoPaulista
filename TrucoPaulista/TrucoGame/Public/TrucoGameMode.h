#pragma once
#include "GameMode.h"
#include <functional>

class Deck;
class TrucoPlayer;
class TrucoGameState;

/*! \class TrucoGameMode
	\brief Especializacao da classe GameMode para um jogo de truco.
*/
class TrucoGameMode : public GameMode
{
private:	
	int m_NumStartCards = 3;

	TrucoPlayer* GetStartPlayer();
	std::function<void(TrucoPlayer*)> m_OnTurnAdvancedCallback;

	void OnTurnAdvanced(TrucoPlayer* turnPlayer);

public:
	TrucoGameMode(int numPlayers, TrucoGameState* gameState);
	~TrucoGameMode();

	void StartGame() override;
	void OnGameStarted() override;
	void OnJoined(PlayerController* pPlayerController, bool isAIControlled = false) override;	
	
	void BindTurnAdvancedCallback(std::function<void(TrucoPlayer*)> callback);
	void AdvancedTurn(TrucoPlayer* turnPlayer);

	int GetNumStartCards() { return m_NumStartCards; }
};

