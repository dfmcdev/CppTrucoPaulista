#include "pch.h"
#include "CppUnitTest.h"
#include "TrucoAIPlayer.h"
#include "TrucoPlayerState.h"
#include "TrucoAIPlayerState.h"
#include "Result.h"
#include "Hand.h"
#include "Card.h"
#include <thread>
#include <future>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace TrucoGame;

namespace TrucoPaulistaTests
{
	TEST_CLASS(TrucoAIPlayerTests)
	{
	public:

		TEST_METHOD(CallDoActionOnTrucoAIPlayerShouldPlayACardAfterAFewSeconds)
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

			GameEngine::AIPlayerController* pAIController = new GameEngine::AIPlayerController();
			TrucoPlayerState* pAIPlayerState = new TrucoPlayerState(new Hand());
			TrucoAIPlayer* pAIPlayer = new TrucoAIPlayer(pAIPlayerState, new TrucoAIPlayerState(), pAIController, 2, 5);

			Hand* pAIHand = pAIPlayerState->GetHand();

			Card* cardOne = new Card(Naipes::Ouros, 4);
			Card* cardTwo = new Card(Naipes::Paus, 6);
			pAIHand->AddCard(cardOne);
			pAIHand->AddCard(cardTwo);

			Assert::IsTrue(pAIHand->GetNumCards() == 2);			

			auto async_action = [=](TrucoAIPlayer* player)
			{
				return player->DoAction();
			};

			std::future<GameEngine::Result> future = std::async(async_action, pAIPlayer);

			GameEngine::Result result = future.get();

			Assert::IsNotNull(result.GetPayload());
			Assert::IsTrue(pAIHand->GetNumCards() == 1);

			delete result.GetPayload();
			delete pAIController;
		}		
	};
}