#include "Hand.h"
#include "Card.h"

Hand::Hand()
{
}

Hand::~Hand()
{
	if (!m_Cards.empty())
	{
		for (Card* card : m_Cards)
		{
			delete card;
		}

		m_Cards.clear();
	}
}

void Hand::SetInitalCards(std::vector<Card*> cards)
{
	m_Cards.clear();
	m_Cards.insert(m_Cards.end(), cards.begin(), cards.end());
}

void Hand::AddCard(Card* card)
{
	m_Cards.push_back(card);
}

Card* Hand::PlayCard(int index)
{
	Card* card = m_Cards[index];
	m_Cards.erase(m_Cards.begin() + index);

	return card;
}

std::vector<Card*> Hand::GetCards()
{
	return m_Cards;
}
