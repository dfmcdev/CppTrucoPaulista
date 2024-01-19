#include "AIPlayer.h"
#include "AIPlayerState.h"

using namespace GameEngine;

AIPlayer::AIPlayer(AIPlayerState* aiPlayerState, double minThinkTimeSec, double maxThinkTimeSec)
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

void AIPlayer::Think()
{
}

void AIPlayer::DaAction()
{
}
