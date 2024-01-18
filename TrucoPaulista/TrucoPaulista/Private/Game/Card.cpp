#include "Game\Card.h"

Card::Card(Naipes naipe, int value) :
	m_naipe(naipe),
	m_value(value)
{
}

bool Card::operator>(const Card& card) const
{
	if (m_value == 0 && m_naipe == Naipes::Paus) 
	{
		return true;
	}
	else if (m_value == 3 && m_naipe == Naipes::Copas && !(card.m_value == 0 && card.m_naipe == Naipes::Paus)) 
	{
		return true;
	}
	else if (m_value == 7 && m_naipe == Naipes::Espadas && !((card.m_value == 0 && card.m_naipe == Naipes::Paus) || (card.m_value == 3 && card.m_naipe == Naipes::Copas))) 
	{
		return true;
	}
	else if (m_value == 3 && m_naipe == Naipes::Ouros && !((card.m_value == 0 && card.m_naipe == Naipes::Paus) || (card.m_value == 3 && card.m_naipe == Naipes::Copas) || (card.m_value == 7 && card.m_naipe == Naipes::Espadas)))
	{
		return true;
	}
	else if (!((card.m_value == 0 && card.m_naipe == Naipes::Paus) || (card.m_value == 3 && card.m_naipe == Naipes::Copas) || (card.m_value == 7 && card.m_naipe == Naipes::Espadas) || (card.m_value == 3 && card.m_naipe == Naipes::Ouros)))
	{
		return m_value > card.m_value;
	}
	else 
	{
		return false;
	}
}

bool Card::operator==(const Card& card) const
{
	if (m_naipe == card.m_naipe && m_value == card.m_value) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Naipes Card::GetNaipe()
{
	return m_naipe;
}

int Card::GetValue()
{
	return m_value;
}
