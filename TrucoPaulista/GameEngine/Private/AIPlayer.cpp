#include "AIPlayer.h"

AIPlayer::AIPlayer(AIPlayerState* aiPlayerState, double minThinkTimeSec, double maxThinkTimeSec)
{
	m_AIPlayerState = aiPlayerState;

	m_minThinkTimeSeconds = minThinkTimeSec;
	m_maxThinkTimeSeconds = maxThinkTimeSec;
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
