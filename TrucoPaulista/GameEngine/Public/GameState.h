#pragma once

/*! \class GameState
	\brief Classe base responsavel por gerenciar o estado do jogo.

	Aqui teremos as informacoes que sao relevantes apenas para a partida em curso.
*/
class GameState
{
public:
	GameState();
	virtual ~GameState() = default;
};

