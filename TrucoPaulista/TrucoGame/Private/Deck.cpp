#include "Deck.h"
#include "Card.h"
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
			m_Cards.push(card);
		}
	}
}

void Deck::Clear()
{
	while (!m_Cards.empty())
	{
		m_Cards.pop();
	}
}

void Deck::DestroyCards()
{
	while (!m_Cards.empty())
	{
		Card* card = m_Cards.top();
		m_Cards.pop();

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
	return (int)m_Cards.size();
}

void Deck::Shuffle()
{
	auto& container = m_Cards._Get_container();
	std::vector<Card*> aux(container.begin(), container.end());

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(aux.begin(), aux.end(), g);

	Clear();

	std::for_each(aux.begin(), aux.end(), [=](Card* card)
		{
			m_Cards.push(card);
		}
	);
}

Card* Deck::DrawCard()
{
	Card* card = m_Cards.top();
	m_Cards.pop();

	return card;
}

std::vector<Card*> Deck::DrawCards(int numCards)
{
	std::vector<Card*> cards(numCards);

	if (!m_Cards.empty())
	{
		if (m_Cards.size() < numCards)
		{
			numCards = (int)m_Cards.size();
		}

		while (numCards > 0)
		{
			Card* card = m_Cards.top();
			m_Cards.pop();

			cards.push_back(card);
			numCards--;
		}
	}

	return cards;
}
