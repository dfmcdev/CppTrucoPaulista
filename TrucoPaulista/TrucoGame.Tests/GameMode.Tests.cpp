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
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace TrucoGame;
using namespace GameEngine;

namespace TrucoPaulistaTests
{
	TEST_CLASS(TrucoGameModeTests)
	{
	public:

		TEST_METHOD(JoinAndLeaveShouldIncreaseAndDescreaseNumPlayers)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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

		TEST_METHOD(CallStartGameShouldInvokeOnGameStartedCallback)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			int numPlayers = 1;
			static bool startGameCallbackCalled = false;

			PlayerController* controller = new PlayerController();
			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new TrucoGameState(new Deck()));

			gameMode->Join(controller);

			std::function<void(void)> callback = [=]() { startGameCallbackCalled = true; };

			gameMode->BindGameStartedCallback(callback);
			gameMode->StartGame();

			Assert::IsTrue(startGameCallbackCalled);

			delete controller;
			delete gameMode;
		}

		TEST_METHOD(CallAdvanceTurnShouldInvokeOnTurnAdvancedCallback)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			int numPlayers = 1;
			static bool turnAdvancedCallbackCalled = false;
			static TrucoPlayer* pTestPlayer = nullptr;

			PlayerController* controller = new PlayerController();
			TrucoGameMode* gameMode = new TrucoGameMode(numPlayers, new TrucoGameState(new Deck()));

			gameMode->Join(controller);

			std::function<void(TrucoPlayer*)> callback = [=](TrucoPlayer* pTrucoPlayer) 
			{ 
				turnAdvancedCallbackCalled = true; 
				pTestPlayer = pTrucoPlayer;
			};

			gameMode->BindTurnAdvancedCallback(callback);
			gameMode->StartGame();

			Assert::IsTrue(turnAdvancedCallbackCalled);
			Assert::IsNotNull(pTestPlayer);

			delete controller;
			delete gameMode;
		}
	};
}