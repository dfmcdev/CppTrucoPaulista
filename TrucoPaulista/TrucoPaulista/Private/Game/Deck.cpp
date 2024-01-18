#include "Game\Deck.h"
#include "Game\Card.h"
#include <algorithm>
#include <random>

void Deck::Init()
{
	DestroyCards();

	for (int naipe = Naipes::Paus; naipe != Naipes::Last; naipe++)
	{
		for (int i = 1; i <= MAX_CARDS_PER_NAIPE; i++)
		{
			Card* card = new Card(static_cast<Naipes>(naipe), i);
			m_cards.push(card);
		}
	}
}

void Deck::Clear()
{
	while (!m_cards.empty())
	{
		m_cards.pop();
	}
}

void Deck::DestroyCards()
{
	while (!m_cards.empty())
	{
		Card* card = m_cards.top();
		m_cards.pop();

		delete card;
	}
}

Deck::Deck()
{
}

Deck::~Deck()
{
	DestroyCards();
}

int Deck::GetNumCards()
{
	return (int)m_cards.size();
}

void Deck::Shuffle()
{
	auto& container = m_cards._Get_container();
	std::vector<Card*> aux(container.begin(), container.end());

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(aux.begin(), aux.end(), g);

	Clear();

	std::for_each(aux.begin(), aux.end(), [=](Card* card)
		{
			m_cards.push(card);
		}
	);
}

Card* Deck::DrawCard()
{
	Card* card = m_cards.top();
	m_cards.pop();

	return card;
}

std::vector<Card*> Deck::DrawCards(int numCards)
{
	std::vector<Card*> cards(numCards);

	if (!m_cards.empty())
	{
		if (m_cards.size() < numCards)
		{
			numCards = (int)m_cards.size();
		}

		while (numCards > 0)
		{
			Card* card = m_cards.top();
			m_cards.pop();

			cards.push_back(card);
			numCards--;
		}
	}

	return cards;
}
