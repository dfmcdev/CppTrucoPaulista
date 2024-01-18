#pragma once

enum Naipes : int
{
	Paus,
	Ouros,
	Copas,
	Espadas,
	Last
};

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

