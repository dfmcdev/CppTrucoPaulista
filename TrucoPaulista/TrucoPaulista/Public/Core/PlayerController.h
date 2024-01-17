#pragma once

class Player;

class PlayerController
{
private:
	bool m_IsAIControled;

protected:
	Player* m_ControlledPlayer;

public:
	PlayerController();
	PlayerController(bool isAIControlled);
	virtual ~PlayerController() = default;

	void Posses(Player* pPlayer);
	Player* GetControlledPlayer();
};

