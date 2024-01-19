#include "pch.h"
#include "CppUnitTest.h"
#include "Deck.h"
#include "Card.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace TrucoGame;

namespace TrucoPaulistaTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(ANewDeckShouldHave40CardsAfterInit)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			Deck* deck = new Deck();

			Assert::IsTrue(deck->GetNumCards() == 0);

			deck->Init();

			Assert::IsTrue(deck->GetNumCards() == 40);

			delete deck;
		}

		TEST_METHOD(ShuffleShouldChangeCardPositions)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			Deck* deckOne = new Deck();
			deckOne->Init();

			Deck* deckTwo = new Deck();
			deckTwo->Init();

			deckOne->Shuffle();

			bool changed = false;

			Card* cardFromOne = nullptr;
			Card* cardFromTwo = nullptr;

			while (deckOne->GetNumCards() > 0)
			{
				cardFromOne = deckOne->DrawCard();
				cardFromTwo = deckTwo->DrawCard();

				if (cardFromOne != cardFromTwo)
				{
					changed = true;
					break;
				}
			}

			Assert::IsTrue(changed);

			if (cardFromOne)
				delete cardFromOne;

			if (cardFromTwo)
				delete cardFromTwo;

			delete deckOne;
			delete deckTwo;
		}
	};
}