//PlayerClass.cpp

#include "PlayerClass.h"

//constructor function to initialise values of Player objects
Player::Player(string player_Name)
{	set_name(player_Name);
}
//set functions for each data member
void Player::set_name(string playerName)
{	name = playerName;	}
void Player::set_score(float playerScore)
{	score = playerScore;	}
void Player::set_bestScore(float playerBest)
{	bestScore = playerBest;	}
void Player::set_EnShipSunk(int playerSunk)
{	numOfOppShipsSunk += playerSunk;	}
//get functions for each data member
string Player::get_name(void)
{	return name;	}
float Player::get_score(void)
{	return score;	}
float Player::get_bestScore(void)
{	return bestScore;	}
int Player::get_EnShipSunk(void)
{	return numOfOppShipsSunk;	}
//end PlayerClass.cpp

//	FITZROY EDINBOROUGH		//
//	408004140				//
//	Cre 07.03.09				//
//	Mod 15.03.09				// 
