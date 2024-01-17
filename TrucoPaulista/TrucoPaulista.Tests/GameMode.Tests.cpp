#include "pch.h"
#include "CppUnitTest.h"
#include "Game\TrucoPaulistaGameMode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrucoPaulistaTests
{
	TEST_CLASS(GameModeTests)
	{
	public:

		TEST_METHOD(JoinAndLeaveShouldIncreaseAndDescreaseNumPlayers)
		{
			int numPlayers = 1;

			PlayerController* controller = new PlayerController();
			TrucoPaulistaGameMode* gameMode = new TrucoPaulistaGameMode(numPlayers, new GameState());

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

			PlayerController* controllerOne = new PlayerController();
			PlayerController* controllerTwo = new PlayerController();
			TrucoPaulistaGameMode* gameMode = new TrucoPaulistaGameMode(numPlayers, new GameState());

			Assert::AreEqual(0, gameMode->GetNumPlayers());

			Result result = gameMode->Join(controllerOne);

			Assert::IsTrue(result.IsSuccess());
			Assert::AreEqual(1, gameMode->GetNumPlayers());

			result = gameMode->Join(controllerTwo);

			Assert::IsFalse(result.IsSuccess());
			Assert::AreEqual(1, gameMode->GetNumPlayers());

			delete controllerOne;
			delete controllerTwo;
			delete gameMode;
		}
	};
}