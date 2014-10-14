#include "stdafx.h"
#include "Node.h"
#include "Grid.h"
#include "common.h"
#include "queue"

namespace game {

	int evalFunction2(Grid board, PlayerType player){
		//return board.calculateDifference(player);
		return board.calculatePlayerValue(player);
	}

	int runMinMax2(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing )
	{
		if(depth==0 || board.cellsOccupied == gridSize * gridSize)
		{
			return evalFunction2(board, player);
		}

		int bestVal= isMaximizing?-board.sumValue:board.sumValue;
		int count=0;
		for (int i = 0; i < gridSize; ++i)
		{
			for (int j = 0; j < gridSize; ++j)
			{
				if(board.cell[i][j].whoOccupy==UNOCCUPIED)
				{
					count++;
					MoveType currMove = PARADROP; 
					board.cell[i][j].whoOccupy=player;

					//DO PARADROP
					MoveType dummy;
					Point dummyPt;
					int currValPara = runMinMax2(board,!player,depth-1,dummy,dummyPt,!isMaximizing);

					for (int k = 0; k < 4; ++k)
					{	
						if(board.cell[i][j].next[k]!=NULL && board.cell[i][j].next[k]->whoOccupy==player)
						{
							currMove = BLITZ;
							break;
						}
					}
					std::queue<Point*> *blitzNode ;
					int currValBlitz = bestVal;
					if(currMove==BLITZ ){
						blitzNode=board.doBlitz(i,j);
						currValBlitz = runMinMax2(board,!player,depth-1,dummy,dummyPt,!isMaximizing);
						board.undoBlitz(blitzNode);
					}
					board.cell[i][j].whoOccupy = UNOCCUPIED;
					if(isMaximizing)
					{
						if(currValBlitz>bestVal && currValBlitz>=currValPara)
						{
							bestVal=currValBlitz;
							move=BLITZ;
							pt.x = i;
							pt.y = j;
						}else if(currValPara>bestVal && currValBlitz<=currValPara)
						{
							bestVal=currValPara;
							move=PARADROP;
							pt.x = i;
							pt.y = j;
						}
					}
					else
					{
						if(currValBlitz<bestVal && currValBlitz<=currValPara)
						{
							bestVal=currValBlitz;
							move=BLITZ;
							pt.x = i;
							pt.y = j;
						}else if(currValPara<bestVal && currValBlitz>=currValPara)
						{
							bestVal=currValPara;
							move=PARADROP;
							pt.x = i;
							pt.y = j;
						}
					}
				}
			}
		}
		if(count==0)
		{
			pt.x = -1;
			pt.y = -1;
			return evalFunction2(board, player);
		}
		return bestVal;
	}
}