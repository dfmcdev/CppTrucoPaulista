#include "Card.h"

Card::Card(Naipes naipe, int value) :
	m_Naipe(naipe),
	m_Value(value)
{
}

bool Card::operator>(const Card& card) const
{
	if (m_Value == 0 && m_Naipe == Naipes::Paus) 
	{
		return true;
	}
	else if (m_Value == 3 && m_Naipe == Naipes::Copas && !(card.m_Value == 0 && card.m_Naipe == Naipes::Paus))
	{
		return true;
	}
	else if (m_Value == 7 && m_Naipe == Naipes::Espadas && !((card.m_Value == 0 && card.m_Naipe == Naipes::Paus) || (card.m_Value == 3 && card.m_Naipe == Naipes::Copas)))
	{
		return true;
	}
	else if (m_Value == 3 && m_Naipe == Naipes::Ouros && !((card.m_Value == 0 && card.m_Naipe == Naipes::Paus) || (card.m_Value == 3 && card.m_Naipe == Naipes::Copas) || (card.m_Value == 7 && card.m_Naipe == Naipes::Espadas)))
	{
		return true;
	}
	else if (!((card.m_Value == 0 && card.m_Naipe == Naipes::Paus) || (card.m_Value == 3 && card.m_Naipe == Naipes::Copas) || (card.m_Value == 7 && card.m_Naipe == Naipes::Espadas) || (card.m_Value == 3 && card.m_Naipe == Naipes::Ouros)))
	{
		return m_Value > card.m_Value;
	}
	else 
	{
		return false;
	}
}

bool Card::operator==(const Card& card) const
{
	if (m_Naipe == card.m_Naipe && m_Value == card.m_Value)
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
	return m_Naipe;
}

int Card::GetValue()
{
	return m_Value;
}
