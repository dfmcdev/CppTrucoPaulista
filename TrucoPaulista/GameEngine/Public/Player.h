#pragma once

#include "PlayerState.h"
#include "PlayerController.h"

class Player
{
protected:
	PlayerController* m_PlayerController;
	PlayerState* m_PlayerState;	

public:
	Player(PlayerState* pPlayerState, PlayerController* pPlayerController);
	virtual ~Player();
	
	PlayerController* GetPlayerController();
	PlayerState* GetPlayerState();
};
