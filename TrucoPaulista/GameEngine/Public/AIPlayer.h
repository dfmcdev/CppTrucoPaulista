#pragma once

namespace GameEngine
{
	class AIPlayerState;

	/*! \class AIPlayer
		\brief Classe base que representa o avatar controlado por AI.

		Aqui teremos as informacoes sobre o avatar que nao mudam entre uma partida e outra.
	*/
	class AIPlayer
	{
	protected:
		int m_MinThinkTimeSeconds;
		int m_MaxThinkTimeSeconds;

		AIPlayerState* m_AIPlayerState;

		virtual void Think(int thinkTime);

	public:
		AIPlayer(AIPlayerState* aiPlayerState, int minThinkTimeSec, int maxThinkTimeSec);
		virtual ~AIPlayer();
		
		virtual void DoAction();
	};
};
