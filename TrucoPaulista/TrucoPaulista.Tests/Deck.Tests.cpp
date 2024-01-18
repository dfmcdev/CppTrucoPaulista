#include "pch.h"
#include "CppUnitTest.h"
#include "Game\Deck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrucoPaulistaTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(ANewDeckShouldHave40CardsAfterInit)
		{
			Deck* deck = new Deck();

			Assert::IsTrue(deck->GetNumCards() == 0);

			deck->Init();

			Assert::IsTrue(deck->GetNumCards() == 40);

			delete deck;
		}

		TEST_METHOD(ShuffleShouldChangeCardPositions)
		{
			Deck* deckOne = new Deck();
			deckOne->Init();

			Deck* deckTwo = new Deck();
			deckTwo->Init();

			deckOne->Shuffle();

			bool changed = false;

			while (deckOne->GetNumCards() > 0)
			{
				Card* cardFromOne = deckOne->DrawCard();
				Card* cardFromTwo = deckTwo->DrawCard();

				if (cardFromOne != cardFromTwo)
				{
					changed = true;
					break;
				}
			}

			Assert::IsTrue(changed);

			delete deckOne;
			delete deckTwo;
		}
	};
}