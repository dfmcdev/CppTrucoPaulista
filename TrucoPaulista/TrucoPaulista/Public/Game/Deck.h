#pragma once

#include <stack>
#include <vector>

class Card;

class Deck
{
private:
	std::stack<Card*> m_cards;
	const int MAX_CARDS_PER_NAIPE = 10;
	
	void Clear();
	void DestroyCards();

public:
	Deck();
	~Deck();

	void Init();
	int GetNumCards();
	void Shuffle();
	Card* DrawCard();
	std::vector<Card*> DrawCards(int numCards);
};

