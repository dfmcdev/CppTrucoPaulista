#include "AIPlayer.h"
#include "AIPlayerState.h"
#include "Result.h"

using namespace GameEngine;

AIPlayer::AIPlayer(AIPlayerState* aiPlayerState, int minThinkTimeSec, int maxThinkTimeSec)
{
	m_AIPlayerState = aiPlayerState;

	m_MinThinkTimeSeconds = minThinkTimeSec;
	m_MaxThinkTimeSeconds = maxThinkTimeSec;
}

AIPlayer::~AIPlayer()
{
	if (m_AIPlayerState)
	{
		delete m_AIPlayerState;
	}
}

void AIPlayer::Think(int thinkTime)
{
}

Result AIPlayer::DoAction()
{
	return Result::Success();
}
