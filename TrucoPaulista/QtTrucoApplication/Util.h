#pragma once
#include <iostream>

using namespace std;

class Util
{

public:
	
	enum Suits
	{
		Clubs,
		Diamonds,
		Hearts,
		Spades,
		Empty,
		IACard
	};


	static string GetCardImage(int card, Suits suit);
};

