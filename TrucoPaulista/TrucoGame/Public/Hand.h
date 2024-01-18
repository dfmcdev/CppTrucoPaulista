#pragma once

#include <vector>

class Card;

class Hand
{
private:
	std::vector<Card*> m_cards;

public:
	Hand();
	~Hand();

	void SetInitalCards(std::vector<Card*> cards);
	void AddCard(Card* card);
	Card* PlayCard(int index);
	std::vector<Card*> GetCards();
};

