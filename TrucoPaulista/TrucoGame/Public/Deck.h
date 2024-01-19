#pragma once

#include <stack>
#include <vector>

class Card;

/*! \class Deck
	\brief Classe que representa o conjunto de cartas de baralho que estao disponiveis no jogo.
*/
class Deck
{
private:
	std::stack<Card*> m_Cards;
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

