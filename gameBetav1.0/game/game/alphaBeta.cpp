#include "stdafx.h"
#include "Node.h"
#include "Grid.h"
#include "common.h"
#include "queue"

namespace game {
	int runAlphaBeta(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing,int &nodesExpanded,int alpha=-1e7, int beta=1e7 )
	{
		if(depth==0 || board.cellsOccupied == gridSize * gridSize)
		{
			nodesExpanded++;
			return board.calculateDifference(player);
		}

		Node* bestNode;
		PlayerType currPlayer = isMaximizing?player:!player;
		int count=0;
	//	int bestVal= isMaximizing?-board.sumValue:board.sumValue;
		for (int i = 0; i < gridSize; ++i)
		{
			for (int j = 0; j < gridSize; ++j)
			{
			
				if(board.cell[i][j].whoOccupy==UNOCCUPIED)
				{
					nodesExpanded++;
					count++;
					MoveType currMove = PARADROP; 
					board.cell[i][j].whoOccupy=currPlayer;				
					for (int k = 0; k < 4; ++k)
					{
							if(board.cell[i][j].next[k]!=NULL && board.cell[i][j].next[k]->whoOccupy==currPlayer)
							{
								currMove = BLITZ;
								break;
							}
					}
					std::queue<Point*> *blitzNode ;
					if(currMove==BLITZ )blitzNode=board.doBlitz(i,j);
					//int currVal =board.calculatePlayerValue(player);
				
					MoveType dummy;
					Point dummyPt;
					int currVal = runAlphaBeta(board,player,depth-1,dummy,dummyPt,!isMaximizing,nodesExpanded,alpha,beta);
					if(isMaximizing)
					{
						if(currVal>alpha)
						{
							alpha = currVal;
							move=currMove;
							pt.x = i;
							pt.y = j;
						}
						if(beta<=alpha)
						{
							if(currMove==BLITZ) board.undoBlitz(blitzNode);
							board.cell[i][j].whoOccupy = UNOCCUPIED;
					 		return alpha;
						}
					}
					else
					{
						if(currVal<beta)
						{
							beta=currVal;
							move=currMove;
							pt.x = i;
							pt.y = j;
						}
						if(beta<=alpha)
						{
							if(currMove==BLITZ) board.undoBlitz(blitzNode);
							board.cell[i][j].whoOccupy = UNOCCUPIED;
					 		return beta;
						}
					}
					if(currMove==BLITZ) board.undoBlitz(blitzNode);
					board.cell[i][j].whoOccupy = UNOCCUPIED;
				}
			}
		}
		if(count==0)
		{
			return board.calculateDifference(player);
			pt.x = -1;
			pt.y = -1;
		}
		return (isMaximizing)?alpha:beta;
	}
}