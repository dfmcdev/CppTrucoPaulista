#pragma once

class AIPlayerState;

class AIPlayer
{
private:
	double m_minThinkTimeSeconds;
	double m_maxThinkTimeSeconds;
	AIPlayerState* m_AIPlayerState;

public:
	AIPlayer(AIPlayerState* aiPlayerState, double minThinkTimeSec, double maxThinkTimeSec);
	virtual ~AIPlayer();

	virtual void Think();
	virtual void DaAction();
};
