#include "stdafx.h"
#include "iostream"
#include "Grid.h"
#include "Node.h"
using namespace std; 

namespace game {
int runMinMax(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing=true );
int runAlphaBeta(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing,int alpha=-1e7, int beta=1e7 );
void game();

int Main(int argc, char const *argv[])
{
	//cout<<t;
	//cout<<!1;
	game();
	return 0;
}

void game()
{
	Grid board;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			//board.cell[i][j].value=(6*(i)+(j));
			board.cell[i][j].value=((i+j)%2==0)?1:9;
		}
	}
	board.calculateTotalValue();
	PlayerType p1 = BLUE;
	PlayerType p2 = GREEN;
	MoveType move;
	Point pt;
	cout<<board;
	for (int i = 0; i < 18; ++i)
	{
		cout<<"Move "<<i+1<<endl;
		cout<<"P1:\n";
		//runMinMax( board,p1, treeDepthMin, move, pt, true );
		//cout<<"bEFORE UPDATE\n"<<board;
		board.cell[pt.x][pt.y].whoOccupy = p1;
		if(move == BLITZ) board.doBlitz(pt.x,pt.y);
		cout<<board;
		cout<<"P2:\n";	
		//runMinMax( board,p2, treeDepthMin, move, pt, true );
		//cout<<"bEFORE UPDATE\n"<<board;
		board.cell[pt.x][pt.y].whoOccupy = p2;
		if(move == BLITZ) board.doBlitz(pt.x,pt.y);
		cout<<board;
	}
	cout<<"Total:\n";
	cout<<"P1: "<< "\033[34m"<<board.calculatePlayerValue(p1)<<"\033[0m\n";
	cout<<"P2: "<< "\033[32m"<<board.calculatePlayerValue(p2)<<"\033[0m\n";
}

PlayerType operator!(const PlayerType p)
{
	if(p==BLUE) return GREEN;
	if(p==GREEN) return BLUE;
	return UNOCCUPIED;
}
}