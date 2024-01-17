#include "Core\AIPlayer.h"
#include "Core\AIPlayerState.h"

AIPlayer::AIPlayer(AIPlayerState* pPlayerState) : Player(pPlayerState)
{
	m_PlayerState = pPlayerState;
}
