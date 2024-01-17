#pragma once

#include "Core\PlayerState.h"
#include "Core\PlayerController.h"

class Player
{
private:
	void SetControlled(PlayerController* pPlayerController);

protected:
	PlayerController* m_PlayerController;
	PlayerState* m_PlayerState;	

public:
	Player(PlayerState* pPlayerState);
	virtual ~Player();
	
	PlayerController* GetPlayerController();
	PlayerState* GetPlayerState();

	friend class PlayerController;
};

