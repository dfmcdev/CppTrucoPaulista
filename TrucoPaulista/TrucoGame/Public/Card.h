#pragma once

#include <vector>

namespace TrucoGame
{
	/*! \enum Naipes
		\brief Enumeracao que representa os possiveis naipes de um baralho.: PAUS > COPAS > ESPADAS > OUROS
	*/
	enum Naipes : int
	{
		Paus = 0,
		Copas = 1,
		Espadas = 2,
		Ouros = 3,
		Last = 4
	};

	/*! \vector m_Schackle
		\brief Vetor de manilha, do index 0 ao index 9, onde quanto menor o index maior o peso da carta. Index 0 ? a manilha
	*/
	const std::vector<int> m_Schackle = { 3, 2, 1, 10, 8, 9, 7, 6, 5, 4 };

	/*! \class Card
		\brief Classe que representa uma carte de baralho.: 3 > 2 > A(1) > K(10) > J(8) > Q(9) > 7 > 6 > 5 > 4
	*/
	class Card
	{
	private:
		Naipes m_Naipe;
		int m_Value;

	public:
		Card(Naipes naipe, int value);

		bool operator>(const Card& card) const;
		bool operator==(const Card& card) const;

		Naipes GetNaipe();
		int GetValue();
		char GetLudicValue();
	};
};
