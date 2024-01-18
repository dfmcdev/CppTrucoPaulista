#include "pch.h"
#include "CppUnitTest.h"
#include "TrucoGameMode.h"
#include "GameState.h"
#include "Result.h"
#include "Deck.h"
#include "TrucoPlayer.h"
#include "TrucoPlayerState.h"
#include "Hand.h"
#include "TrucoGameState.h"

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
			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new TrucoGameState(new Deck()));

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

			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new TrucoGameState(new Deck()));

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

			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new TrucoGameState(new Deck()));

			gameMode->Join(controllerOne);
			gameMode->Join(controllerTwo);

			TrucoPlayer* pPlayerOne = dynamic_cast<TrucoPlayer*>(controllerOne->GetControlledPlayer());
			Assert::IsNotNull(pPlayerOne);

			TrucoPlayerState* pTrucoPlayerStateOne = dynamic_cast<TrucoPlayerState*>(pPlayerOne->GetPlayerState());
			Assert::IsNotNull(pTrucoPlayerStateOne);

			Assert::AreEqual(0, (int)pTrucoPlayerStateOne->GetHand()->GetCards().size());

			TrucoPlayer* pPlayerTwo = dynamic_cast<TrucoPlayer*>(controllerTwo->GetControlledPlayer());
			Assert::IsNotNull(pPlayerTwo);

			TrucoPlayerState* pTrucoPlayerStateTwo = dynamic_cast<TrucoPlayerState*>(pPlayerTwo->GetPlayerState());
			Assert::IsNotNull(pTrucoPlayerStateTwo);

			Assert::AreEqual(0, (int)pTrucoPlayerStateTwo->GetHand()->GetCards().size());

			gameMode->StartGame();

			Assert::AreEqual(gameMode->GetNumStartCards(), (int)pTrucoPlayerStateOne->GetHand()->GetCards().size());
			Assert::AreEqual(gameMode->GetNumStartCards(), (int)pTrucoPlayerStateTwo->GetHand()->GetCards().size());

			delete controllerOne;
			delete controllerTwo;
			delete gameMode;
		}
	};
}