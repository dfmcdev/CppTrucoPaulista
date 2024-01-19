#pragma once

namespace GameEngine
{
	/*! \class AIPlayerState
		\brief Classe base responsavel por gerenciar o estado do Player controlado por AI.

		Aqui teremos informacoes pertinentes ao estado da AI durante as partidas.
	*/
	class AIPlayerState
	{
	public:
		AIPlayerState();
		virtual ~AIPlayerState() = default;
	};
};
