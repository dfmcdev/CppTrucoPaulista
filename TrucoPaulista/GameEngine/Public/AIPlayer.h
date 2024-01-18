#pragma once

class AIPlayerState;

class AIPlayer
{
private:
	double m_MinThinkTimeSeconds;
	double m_MaxThinkTimeSeconds;
	AIPlayerState* m_AIPlayerState;

public:
	AIPlayer(AIPlayerState* aiPlayerState, double minThinkTimeSec, double maxThinkTimeSec);
	virtual ~AIPlayer();

	virtual void Think();
	virtual void DaAction();
};
