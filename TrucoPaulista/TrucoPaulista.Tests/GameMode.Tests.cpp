#include "pch.h"
#include "CppUnitTest.h"
#include "Game\TrucoGameMode.h"
#include "Core\GameState.h"
#include "Core\Result.h"
#include "Game\Deck.h"
#include "Game\TrucoPlayer.h"
#include "Game\TrucoPlayerState.h"
#include "Game\Hand.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrucoPaulistaTests
{
	TEST_CLASS(TrucoGameModeTests)
	{
	public:

		TEST_METHOD(JoinAndLeaveShouldIncreaseAndDescreaseNumPlayers)
		{
			int numPlayers = 1;

			PlayerController* controller = new PlayerController();
			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new GameState(), new Deck());

			Assert::AreEqual(0, gameMode->GetNumPlayers());

			Result result = gameMode->Join(controller);

			Assert::IsTrue(result.IsSuccess());
			Assert::AreEqual(1, gameMode->GetNumPlayers());

			gameMode->Leave(controller);

			Assert::AreEqual(0, gameMode->GetNumPlayers());

			delete controller;
			delete gameMode;
		}

		TEST_METHOD(JoinInAFullGameShouldNotIncreaseNumPlayers)
		{
			int numPlayers = 1;

			PlayerController* pControllerOne = new PlayerController();
			PlayerController* pControllerTwo = new PlayerController();

			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new GameState(), new Deck());

			Assert::AreEqual(0, gameMode->GetNumPlayers());

			Result result = gameMode->Join(pControllerOne);

			Assert::IsTrue(result.IsSuccess());
			Assert::AreEqual(1, gameMode->GetNumPlayers());

			result = gameMode->Join(pControllerTwo);

			Assert::IsFalse(result.IsSuccess());
			Assert::AreEqual(1, gameMode->GetNumPlayers());

			delete pControllerOne;
			delete pControllerTwo;
			delete gameMode;
		}

		TEST_METHOD(StartGameShouldGiveCardsToPlayers)
		{
			int numPlayers = 2;

			PlayerController* controllerOne = new PlayerController();
			PlayerController* controllerTwo = new PlayerController();

			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new GameState(), new Deck());

			gameMode->Join(controllerOne);
			gameMode->Join(controllerTwo);

			TrucoPlayer* pPlayerOne = dynamic_cast<TrucoPlayer*>(controllerOne->GetControlledPlayer());
			Assert::IsNotNull(pPlayerOne);
			Assert::AreEqual(0, (int)pPlayerOne->GetHand()->GetCards().size());

			TrucoPlayer* pPlayerTwo = dynamic_cast<TrucoPlayer*>(controllerTwo->GetControlledPlayer());
			Assert::IsNotNull(pPlayerTwo);
			Assert::AreEqual(0, (int)pPlayerTwo->GetHand()->GetCards().size());

			gameMode->StartGame();

			Assert::AreEqual(gameMode->GetNumStartCards(), (int)pPlayerOne->GetHand()->GetCards().size());
			Assert::AreEqual(gameMode->GetNumStartCards(), (int)pPlayerTwo->GetHand()->GetCards().size());

			delete controllerOne;
			delete controllerTwo;
			delete gameMode;
		}
	};
}