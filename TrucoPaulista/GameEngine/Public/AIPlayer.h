#pragma once

class AIPlayerState;

/*! \class AIPlayer
	\brief Classe base que representa o avatar controlado por AI.

	Aqui teremos as informacoes sobre o avatar que nao mudam entre uma partida e outra.
*/
class AIPlayer
{
private:
	double m_MinThinkTimeSeconds;
	double m_MaxThinkTimeSeconds;
	AIPlayerState* m_AIPlayerState;

public:
	AIPlayer(AIPlayerState* aiPlayerState, double minThinkTimeSec, double maxThinkTimeSec);
	virtual ~AIPlayer();

	virtual void Think();
	virtual void DaAction();
};
