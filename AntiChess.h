/*
	IEEE DTU TROIKA 2015
	BOTS - The AI Gaming Challenge

	AntiChess.h

	This is a header file for the game Anti-Chess.
	It contains all the variables and functions which have been defined in the main cpp file.
	You are requested to go through the file and read through the meanings of variables.
	The functions have been defined and used in AntiChess.cpp
	You are requested not to change this file, because any of your change wont be incorporated in the actual competition.
*/

#pragma once
#include<iostream>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Class For Move
class Move{
	public:
		int xInit;
		int yInit;
		int xFinal;
		int yFinal;
		Move();
		void print();
};

//Class For Board
class AntiChess{
    public:
         char board[8][8];  	//Current Board Situation: Small letters for Player 2 and Caps for Player 1. Player one at bottom.
		 bool turn;   			//0 for player 2 and 1 for player 1
		 int captureOrPawnMove; //Stores no.of moves since last capture or pawn movement
		 int totalMoves;  		//total number of moves present for the current player
		 Move validMoves[80]; 	//Valid Moves available to players
		 int movesDone; 		//total no. of moves done by now
		 bool captureAvailable; //whether capture is available or not.

		 //Functions
		 AntiChess();
    	 void print(); 		//To print current board;
         void evaluate();	//To generate moves
    	 bool isMyPiece(char piece);
    	 bool isPromotion();
    	 void updateMovesPawn();
    	 void updateMovesKnight();
    	 void updateMovesBishop();
    	 void updateMovesRook();
    	 void updateMovesQueen();
		 void updateMovesKing();
		 bool inRange(int y,int x);
		 void updateMovesArray(int x1,int y1,int x2,int y2);

};
