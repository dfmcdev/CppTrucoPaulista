#pragma once

class Player;

class PlayerController
{
private:
	bool m_IsAIControled;
	void Posses(Player* pPlayer);

protected:
	Player* m_ControlledPlayer;

public:
	PlayerController();
	PlayerController(bool isAIControlled);
	virtual ~PlayerController();
	
	Player* GetControlledPlayer();

	friend Player;
};

