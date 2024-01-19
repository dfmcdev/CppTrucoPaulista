#pragma once

#include <vector>

class Card;

/*! \class Hand
	\brief Classe que representa as cartas de baralho que estao em posse (na mao) de um jogador.
*/
class Hand
{
private:
	std::vector<Card*> m_Cards;

public:
	Hand();
	~Hand();

	void SetInitalCards(std::vector<Card*> cards);
	void AddCard(Card* card);
	Card* PlayCard(int index);
	std::vector<Card*> GetCards();
};

