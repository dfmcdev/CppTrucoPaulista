#include "Core\PlayerController.h"
#include "Core\Player.h"

PlayerController::PlayerController() : 
	m_IsAIControled(false), 
	m_ControlledPlayer(nullptr)
{
}

PlayerController::PlayerController(bool isAIControlled) : 
	m_IsAIControled(isAIControlled),
	m_ControlledPlayer(nullptr)
{
}

void PlayerController::Posses(Player* pPlayer)
{
	m_ControlledPlayer = pPlayer;
	pPlayer->SetControlled(this);
}

Player* PlayerController::GetControlledPlayer()
{
	return m_ControlledPlayer;
}