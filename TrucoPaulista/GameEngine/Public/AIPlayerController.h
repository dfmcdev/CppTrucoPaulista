#pragma once

#include "PlayerController.h"

namespace GameEngine
{
	/*! \class AIPlayerController
		\brief Classe base que representa um avatar controlado por AI.

		Ela e responsavel por controlar um avatar atraves de inputs gerados por arvore de decisao,
		maquina de estado finita, entre outros. Pode se considerar como cerebro do AIPlayer.
	*/
	class AIPlayerController :
		public PlayerController
	{
	public:
		AIPlayerController();
	};
};
