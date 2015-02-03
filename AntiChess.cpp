/*
	IEEE DTU TROIKA 2015
	BOTS - The AI Gaming Challenge

	AntiChess.cpp

	You are suggested to read AntiChess.h before reading this file.
	This is a main cpp file for the game Anti-Chess.
	It contains all the variables and functions declarations.
	It contains main function for running the cpp file.
	You are requested not to change this file, because any of your change wont be incorporated in the actual competition.

	NOTE: This file may not represent the exact main cpp file to be used in the competition. Certain features such as timer for each move have not been incorporated in this file. You are suggested to check regularly for any updates to the file.
*/


#include "Player1.cpp"
#include "Player0.cpp"


using namespace std;

#define PLAYER0 Player0
#define PLAYER1 Player1

bool equateMove(Move a,Move b)
{
	if( a.xFinal == b.xFinal && a.xInit == b.xInit && a.yInit == b.yInit && a.yFinal == b.yFinal)
		return true;
	return false;
}

//Main Function
int main(){
	AntiChess actualGame;
	Move mo;
	actualGame.print();

	while(1)
	{

		actualGame.turn=1;
		actualGame.totalMoves=0;
		actualGame.captureAvailable=false;
		actualGame.evaluate();

		if(actualGame.totalMoves==0)
		{
			cout<<"\n  >>Player 1 won the game!!";
			break;
		}
		//cout<<"\n TOTAL MOVES : "<<actualGame.totalMoves<<"\nENPASSENT INDEX : "<<actualGame.enpassantIndex<<endl;
        AntiChess temp=actualGame;
		mo=player1(temp);
		cout<<"\nTotalMoves="<<actualGame.totalMoves;
		mo.print();
		int fmove=0;
		for(int i=0;i<actualGame.totalMoves;i++){
            if(equateMove(mo,actualGame.validMoves[i])){
                fmove=1;
                break;
            }
		}
		if(fmove==1){
            if(!actualGame.captureAvailable)
			actualGame.captureOrPawnMove ++ ;
			else{
            actualGame.captureOrPawnMove = 0;
            cout<<"\n CAPTURE BY PLAYER 1";
            }
            actualGame.board[mo.yFinal][mo.xFinal]=actualGame.board[mo.yInit][mo.xInit];
            actualGame.board[mo.yInit][mo.xInit]='-';
            cout<<"\nPIECE : "<<actualGame.board[mo.yFinal][mo.xFinal]<<endl;
            if(actualGame.board[mo.yFinal][mo.xFinal]=='p' || actualGame.board[mo.yFinal][mo.xFinal]=='P'){
                    actualGame.captureOrPawnMove=0;
                    if(actualGame.isPromotion()){
                            cout<<"\nPAWN DISAPPEARS PLAYER 1";
                    }
            }
            actualGame.print(); // Print Board.
            if(actualGame.captureOrPawnMove>=50){
                    cout<<"\n  >>Game Drawn!!";
                    break;
            }
            cout<<"Press Enter to continue.";
            cin.get();
		}
		else{
            cout<<"Invalid Move by Player 1! Player 0 wins!";
            break;
		}

		actualGame.turn=0;
		actualGame.totalMoves=0;
		actualGame.captureAvailable=false;
		actualGame.evaluate();

		if(actualGame.totalMoves==0)
		{
			cout<<"\n  >>Player 0 won the game!!";
			break;
		}
	//	cout<<"\n TOTAL MOVES : "<<actualGame.totalMoves<<"\nENPASSENT INDEX : "<<actualGame.enpassantIndex<<endl;

	    temp=actualGame;
		mo=player0(temp);
		cout<<"\nTotalMoves="<<actualGame.totalMoves;
		mo.print();
		fmove=0;
		for(int i=0;i<actualGame.totalMoves;i++){
            if(equateMove(mo,actualGame.validMoves[i])){
                fmove=1;
                break;
            }
		}
		if(fmove==1){
            if(!actualGame.captureAvailable)
                actualGame.captureOrPawnMove ++ ;
            else{
                actualGame.captureOrPawnMove = 0;
                cout<<"\n CAPTURE BY PLAYER 0";
            }
            actualGame.board[mo.yFinal][mo.xFinal]=actualGame.board[mo.yInit][mo.xInit];
            actualGame.board[mo.yInit][mo.xInit]='-';
            cout<<"\nPIECE : "<<actualGame.board[mo.yFinal][mo.xFinal]<<endl;
            if(actualGame.board[mo.yFinal][mo.xFinal]=='p' || actualGame.board[mo.yFinal][mo.xFinal]=='P'){
                    actualGame.captureOrPawnMove=0;
                    if(actualGame.isPromotion()){
                            cout<<"\nPAWN DISAPPEARS PLAYER 0";
                    }
            }
            actualGame.movesDone++;
            actualGame.print();
            if(actualGame.captureOrPawnMove>=50){
                    cout<<"\n  >>Game Drawn!!";
                    break;
            }
            cout<<"Press Enter to continue.";
            cin.get();
		}
		else{
            cout<<"Invalid Move by Player 0! Player 1 wins!";

            break;
		}
	}
}

//Constructor For Move
Move::Move(){
	xInit=-1;
	yInit=-1;
	xFinal=-1;
	yFinal=-1;
}

void Move::print() //Prints a move.
{
	cout<<"\nInit = ("<<yInit<<","<<xInit<<")";
	cout<<"   Final = ("<<yFinal<<","<<xFinal<<")";
}

//Constructor For Chess
AntiChess::AntiChess(){
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j]='-';
			board[1][j]='p';
			board[6][j]='P';
		}

	}

	board[0][0]=board[0][7]='r';
	board[7][0]=board[7][7]='R';

	board[0][1]=board[0][6]='n';
	board[7][1]=board[7][6]='N';

	board[0][2]=board[0][5]='b';
	board[7][2]=board[7][5]='B';

	board[0][4]='k';
	board[7][4]='K';

	board[0][3]='q';
	board[7][3]='Q';

	//To set starting player to be player 1
	turn=1;



	//totalMoves are zero initially
	totalMoves=0;

	//total number of moves done are zero initially
	movesDone=0;

	//Moves since last capture or pawn movement
	captureOrPawnMove=0;

	//true when capture is available
	captureAvailable = false;


}


//Prints current game situation
void AntiChess::print(){
    cout<<"Current Board Situation...\n\n";
    for(int i=0;i<8;i++)
    {
        cout<<" "<<i;
        for(int j=0;j<8;j++)
		{
            printf("%3c",board[i][j]);
		}
        cout<<"\n\n";
    }

    cout<<" Turn of Player -> "<<turn;
    cout<<"\nTotal Number of Moves Done: "<<movesDone<<"\n\n\n";
}

//returns 1 if given piece is mine, 0 otherwise
bool AntiChess::isMyPiece(char piece){
	if(piece>='A' && piece <='Z')
	{
		if(turn==1)
		{
			return 1;
		}
	}
	if(piece>='a' && piece <='z')
	{
		if(turn==0)
		{
			return 1;
		}
	}
	return 0;
}

//Checks if coordinates are within the board
bool AntiChess::inRange(int y,int x){
    if(y<8 && y>=0 && x<8 && x>=0)
        return 1;
    return 0;
}


//Updates the array of valid moves available to the player
void AntiChess::updateMovesArray(int x1,int y1,int x2,int y2)
{

	char final = board[y2][x2];
	if(final!='-' && captureAvailable == false) //first time when a capture move is experienced.
	{
		captureAvailable = true;
		totalMoves=0;
	}

	if(captureAvailable) //When we have make sure a capture is Available
	{
		if(final!='-')
		{
			validMoves[totalMoves].xInit=x1;
			validMoves[totalMoves].yInit=y1;
			validMoves[totalMoves].xFinal=x2;
			validMoves[totalMoves].yFinal=y2;
			totalMoves++;
		}
	}
	else //When capture might, might not be available.
	{
		validMoves[totalMoves].xInit=x1;
		validMoves[totalMoves].yInit=y1;
		validMoves[totalMoves].xFinal=x2;
		validMoves[totalMoves].yFinal=y2;
		totalMoves++;
	}
}


//Check whether promotion is possible or not, returns 1 if posible.
//piece should always be SMALL LETTER.
bool AntiChess::isPromotion(){
	int i=7,flag=0;
	char a='p';

	if(turn==1)
	{
		i=0;
		a='P';
	}
	for(int j=0;j<=7;j++)
	{
		if(board[i][j]==a)
		{
			board[i][j]='-';
			flag=1;
		}
	}
	return flag;
}

//Lists the valid pawn moves available to the player
void AntiChess::updateMovesPawn(){


		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				char current=board[i][j];

				if(current=='p' || current=='P')
				{
					if(isMyPiece(current))
					{
						int w=1;   // initial row of pawn
						int increment=1,increment2=2;    // increment2 is the variable taken for double jump of pawn if it is in its initial position
						if(turn==1)
						{
							w=6;
							increment=-1;
							increment2=-2;
						}

						if(!captureAvailable)
						{
							/*if(i==w && board[i+increment2][j]=='-' && board[i+increment][j]=='-')
							{
								//updateMovesArray(j,i,j,i+increment2);
							}*/
							if(inRange(i+increment,j) && board[i+increment][j]=='-')
							{
								updateMovesArray(j,i,j,i+increment);
							}
						}
						if(inRange(i+increment,j+1) && board[i+increment][j+1]!='-' && !isMyPiece(board[i+increment][j+1]))
						{
							updateMovesArray(j,i,j+1,i+increment);
						}
						if(inRange(i+increment,j-1) && board[i+increment][j-1]!='-' && !isMyPiece(board[i+increment][j-1]))
						{
							updateMovesArray(j,i,j-1,i+increment);
						}
					}
				}
			}
		}
	//}
}

//Lists the valid rook moves available to the player
void AntiChess::updateMovesRook(){
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char current = board[i][j];

			if (current == 'r' || current == 'R')
			{
				if (isMyPiece(current))
				{
					int x[4] = { 0, 1, 0, -1 };
					int y[4] = { 1, 0, -1, 0 };

					for (int k = 0; k < 4; k++)
					{
						int incx = x[k];
						int incy = y[k];
						int iy = i;
						int jx = j;

						while (inRange(iy + incy, jx + incx)
								&& board[iy + incy][jx + incx] == '-')
						{
							updateMovesArray(j, i, jx + incx, iy + incy);
							iy = iy + incy;
							jx = jx + incx;
						}

						if (inRange(iy + incy, jx + incx)
							&& !isMyPiece(board[iy + incy][jx + incx]))
						{
							updateMovesArray(j, i, jx + incx, iy + incy);
						}
					}
				}
			}
		}
	}
}

//Lists the valid knight moves available to the player
void AntiChess::updateMovesKnight(){
	int kx[8]={1,1,-1,-1,2,2,-2,-2};
	int ky[8]={2,-2,2,-2,1,-1,1,-1};

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			char current=board[i][j];

			if(current=='n' || current=='N')
			{
				if(isMyPiece(current))
				{
					int ix,iy;
				 	for(int l=0;l<8;l++)
				  	{
						ix=kx[l];
			 			iy=ky[l];
			 	 		if(inRange(i+ix,j+iy) && (board[i+ix][j+iy]=='-'|| !isMyPiece(board[i+ix][j+iy])))
						{
				 	 		updateMovesArray(j,i,j+iy,i+ix);
					 	}
				  	}

				}
			}
		}
	}
}

//Lists the valid bishop moves available to the player
void AntiChess::updateMovesBishop(){
	int kx[2]={-1,1};
	int ky[2]={-1,1};

	for( int i=0 ; i<8 ; i++)
	{
		for( int j=0 ; j<8 ; j++)
		{
			char current=board[i][j];

			if(current == 'b' || current == 'B')
			{
				if(isMyPiece(current))
				{
					for(int k=0 ; k<2 ; k++)
					{
						for(int l=0 ; l<2 ; l++)
						{
							int incx=kx[k];
							int incy=ky[l];
							int iy=i;
							int jx=j;

							while(inRange(iy+incy,jx+incx) && (board[iy+incy][jx+incx]=='-' || !isMyPiece(board[iy+incy][jx+incx])))
							{
							    updateMovesArray(j, i, jx + incx, iy + incy);
								iy=iy+incy;
								jx=jx+incx;

							}

							if(inRange(iy+incy,jx+incx) && !isMyPiece(board[iy+incy][jx+incx]))
							{
								updateMovesArray(j,i,jx+incx,iy+incy);
							}
						}
					}
				}
			}
		}
	}
}

//Lists the valid queen moves available to the player
void AntiChess::updateMovesQueen(){
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			char current=board[i][j];

			if(current=='q' || current=='Q')
			{
				 if(isMyPiece(current))
				 {
				 	 int x[8]={0,1,0,-1,1,1,-1,-1};
				 	 int y[8]={1,0,-1,0,1,-1,1,-1};

				 	 for(int k=0;k<8;k++)
				 	 {
						int incx=x[k];
						int incy=y[k];
						int iy=i;
						int jx=j;

						while(inRange(iy+incy,jx+incx) && board[iy+incy][jx+incx]=='-')
						{
							updateMovesArray(j,i,jx+incx,iy+incy);
							iy=iy+incy;
							jx=jx+incx;
						}

						if(inRange(iy+incy,jx+incx) && !isMyPiece(board[iy+incy][jx+incx]))
						{
						 	updateMovesArray(j,i,jx+incx,iy+incy);
						}
					}
				}
			}
		}
	}
}

//Lists the valid king moves available to the player
void AntiChess::updateMovesKing(){
	int kx[8]={1,1,1,-1,-1,-1,0,0};
	int ky[8]={1,-1,0,1,-1,0,1,-1};

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			char current=board[i][j];

			if(current=='k' || current=='K')
			{
				 if(isMyPiece(current))
				 {
				 	int ix,iy;
				 	for(int l=0;l<8;l++)
				 	{
				 		ix=kx[l];
				 		iy=ky[l];
				 	 	if(inRange(i+ix,j+iy) && (board[i+ix][j+iy]=='-' || !isMyPiece(board[i+ix][j+iy])))
				 		{
						 	updateMovesArray(j,i,j+iy,i+ix);
					 	}
					}
				}
			}
		}
	}
}

//Evaluates all moves available to player
void AntiChess::evaluate(){
     updateMovesPawn();
     updateMovesKnight();
     updateMovesBishop();
     updateMovesRook();
     updateMovesQueen();
     updateMovesKing();
}
