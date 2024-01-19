#pragma once

namespace GameEngine
{
	/*! \class PlayerState
		\brief Classe base responsavel por gerenciar o estado do Player durante as partidas.

		Aqui teremos as informacoes que sao relevantes apenas para a partida em curso.
	*/
	class PlayerState
	{
	public:
		PlayerState();
		virtual ~PlayerState() = default;
	};
};
