#include "Card.h"

using namespace TrucoGame;

Card::Card(Naipes naipe, int value) :
	m_Naipe(naipe),
	m_Value(value)
{
}

bool Card::operator>(const Card& card) const
{
	if (m_Value == card.m_Value)
	{
		if ((int)m_Naipe < (int)card.m_Naipe)
			return true;
		return false;
	}
	else
	{
		auto current_it = std::find(m_Schackle.begin(), m_Schackle.end(), m_Value);
		auto card_it = std::find(m_Schackle.begin(), m_Schackle.end(), card.m_Value);

		int value = current_it - m_Schackle.begin();
		int card_value = card_it - m_Schackle.begin();

		return (value < card_value);
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

char Card::GetLudicValue()
{
	switch (m_Value)
	{
	case 1:
		return 'A';
	case 8:
		return 'J';
	case 9:
		return 'Q';
	case 10:
		return 'K';
	default:
		return (char)m_Value;
	}
}