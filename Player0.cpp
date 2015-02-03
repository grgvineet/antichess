/*
	IEEE DTU TROIKA 2014
	BOTS - An AI Gaming Challenge

	Player0.cpp(Black)

	This is a sample player file for the player playing with BLACK PIECES.
	You have to code this file. A sample code has been provided currently.
	You are asked to use only these variables which are provided to you.
	Using/Changing any variable from the AntiChess.cpp or AntiChess.h, other than those provided to you will lead to disqualification.
	You can be any one of the players, Player1(White) or Player0(Black). You are advised to test your code for both.
*/

#pragma once
#include "AntiChess.h"

Move player0(AntiChess ob)
{
    /*Sample code using random function*/
	int k=rand()%ob.totalMoves;
 	return ob.validMoves[k];
}
