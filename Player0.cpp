#pragma once
#include "AntiChess.h"

int MaxDepth = 4;
int INFINITY = 10000;
int KING = 2;
int QUEEN = 1;
int ROOK = 5;
int KNIGHT = 5;
int BISHOP = 5;
int PAWN = 20;
int HeuristicsCounter;

int min(AntiChess,int,int,int,Move);
int max(AntiChess,int,int,int,Move);
int heuristics(AntiChess&);
void playMove(AntiChess&,Move);

void playMove(AntiChess &actualGame,Move mo){

	actualGame.board[mo.yFinal][mo.xFinal]=actualGame.board[mo.yInit][mo.xInit];
    actualGame.board[mo.yInit][mo.xInit]='-';
    if(actualGame.board[mo.yFinal][mo.xFinal]=='p' || actualGame.board[mo.yFinal][mo.xFinal]=='P'){
        if(actualGame.isPromotion()){

        }
    }

}

void obCorrection(AntiChess &ob){
	ob.totalMoves = 0;
	ob.turn = !ob.turn;
	ob.captureAvailable = false;
	ob.evaluate();
}

int heuristics(AntiChess &ob){

	int my_heuristic,opponent_heuristic;
	HeuristicsCounter++;
	ob.turn = !ob.turn;

	int i,j,ans = 0;
	if (ob.turn){
		for (i=0 ; i<8 ; i++){
			for (j=0 ; j<8 ; j++){
				switch(ob.board[i][j]){ // upper case letters
					case 'K' :
						ans += KING;
						break;
					case 'Q' :
						ans += QUEEN;
						break;
					case 'R' :
						ans += ROOK;
						break;
					case 'N' :
						ans += KNIGHT;
						break;
					case 'B' :
						ans += BISHOP;
						break;
					case 'P' :
						ans += PAWN;
						break;
					default:
						ans += 0;

				}
			}
		}
	}else{
		for (i=0 ; i<8 ; i++){
			for (j=0 ; j<8 ; j++){
				switch(ob.board[i][j]){ // small letters
					case 'k' :
						ans += KING;
						break;
					case 'q' :
						ans += QUEEN;
						break;
					case 'r' :
						ans += ROOK;
						break;
					case 'n' :
						ans += KNIGHT;
						break;
					case 'b' :
						ans += BISHOP;
						break;
					case 'p' :
						ans += PAWN;
						break;
					default :
						ans += 0;
				}
			}
		}

	}

	my_heuristic = ans;


	ans = 0;
	ob.turn = !ob.turn;
	if (ob.turn){
		for (i=0 ; i<8 ; i++){
			for (j=0 ; j<8 ; j++){
				switch(ob.board[i][j]){ // upper case letters
					case 'K' :
						ans += KING;
						break;
					case 'Q' :
						ans += QUEEN;
						break;
					case 'R' :
						ans += ROOK;
						break;
					case 'N' :
						ans += KNIGHT;
						break;
					case 'B' :
						ans += BISHOP;
						break;
					case 'P' :
						ans += PAWN;
						break;
					default:
						ans += 0;

				}
			}
		}
	}else{
		for (i=0 ; i<8 ; i++){
			for (j=0 ; j<8 ; j++){
				switch(ob.board[i][j]){ // small letters
					case 'k' :
						ans += KING;
						break;
					case 'q' :
						ans += QUEEN;
						break;
					case 'r' :
						ans += ROOK;
						break;
					case 'n' :
						ans += KNIGHT;
						break;
					case 'b' :
						ans += BISHOP;
						break;
					case 'p' :
						ans += PAWN;
						break;
					default :
						ans += 0;
				}
			}
		}

	}

	opponent_heuristic = ans;
	return my_heuristic - opponent_heuristic;
}

int max(AntiChess ob,int alpha,int beta,int depth,Move move){

	int maximum = -INFINITY;

	int temp;
	int i;

	obCorrection(ob);
	playMove(ob,move);

	if (depth == MaxDepth){
		return heuristics(ob);
	}


	for (i=0 ; i < ob.totalMoves ; i++){
		if (temp = min(ob,alpha,beta,depth+1,ob.validMoves[i]) > alpha){
				alpha = temp;
		}

		if (alpha > beta)
			return alpha;
	}

	return alpha;

}

int min(AntiChess ob,int alpha,int beta,int depth,Move move){

	int minimum = INFINITY;
	int temp;
	int i;

	obCorrection(ob);
	playMove(ob,move);

	if (depth == MaxDepth){
		return heuristics(ob);
	}



	for (i=0 ; i < ob.totalMoves ; i++){
		if (temp = max(ob,alpha,beta,depth+1,ob.validMoves[i]) < beta){
				beta = temp;
		}

		if (alpha > beta)
			return beta;
	}

	return beta;
}

Move player0(AntiChess ob){

	int k=rand()%ob.totalMoves;

 	int i;
 	int maximum = -INFINITY;
 	int temp;
 	int alpha = -INFINITY;
 	int beta = INFINITY;

 	HeuristicsCounter = 0;

 	for (i=0 ; i<ob.totalMoves ; i++){

 		// calculate max
 		if ((temp = min(ob,alpha,beta,1,ob.validMoves[i])) > alpha){
 			alpha = temp;
 			k = i;
 		}

 		if (alpha > beta)
 			return ob.validMoves[k];

 	}

 	return ob.validMoves[k];
}
