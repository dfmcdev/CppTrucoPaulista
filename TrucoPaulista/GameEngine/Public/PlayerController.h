#pragma once

class Player;

/*! \class PlayerController
	\brief Classe base que representa um jogador. 

	Ela e responsavel por controlar um Player atraves de inputs recebidos, pode se considerar como cerebro do Player.
*/
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

