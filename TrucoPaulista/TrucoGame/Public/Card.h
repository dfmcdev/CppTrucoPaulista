#pragma once

/*! \enum Naipes
	\brief Enumeracao que representa os possiveis naipes de um baralho.
*/
enum Naipes : int
{
	Paus,
	Ouros,
	Copas,
	Espadas,
	Last
};

/*! \class Card
	\brief Classe que representa uma carte de baralho.
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
};

