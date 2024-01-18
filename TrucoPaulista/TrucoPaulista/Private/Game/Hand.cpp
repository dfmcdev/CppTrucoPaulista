#include "Game\Hand.h"

Hand::Hand()
{
}

Hand::~Hand()
{
	if (!m_cards.empty())
	{
		m_cards.clear();
	}
}

void Hand::SetInitalCards(std::vector<Card*> cards)
{
	m_cards.clear();
	m_cards.insert(m_cards.end(), cards.begin(), cards.end());
}

void Hand::AddCard(Card* card)
{
	m_cards.push_back(card);
}

Card* Hand::PlayCard(int index)
{
	Card* card = m_cards[index];
	m_cards.erase(m_cards.begin() + index);

	return card;
}

std::vector<Card*> Hand::GetCards()
{
	return m_cards;
}
