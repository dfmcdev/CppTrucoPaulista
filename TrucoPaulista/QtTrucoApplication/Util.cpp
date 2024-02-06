#include "Util.h"
#include <string>

string Util::GetCardImage(int card, Suits suit)
{
	string base = ":/QtTrucoApplication/images/";
	switch (suit)
	{
		
	case Suits::Diamonds:
		return base + std::to_string(300 + card)+ ".gif";
		break;
	case Suits::Clubs:
		return base + std::to_string(400 + card) + ".gif";
		break;
		
	case Suits::Hearts:
		return base + std::to_string(200 + card) + ".gif";
		break;
		
	case Suits::Spades:
		return base + std::to_string(100 + card) + ".gif";
		break;

	case Suits::IACard:
		return ":/QtTrucoApplication/images/cardback.gif";
		break;

	case Suits::Empty:
		return ":/QtTrucoApplication/images/blank.gif";
		break;
	default:
		return ":/QtTrucoApplication/images/blank.gif";
			break;

	}

}