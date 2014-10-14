#ifndef GRID_H
#define GRID_H 

#include "iostream"
#include "common.h"
#include "Node.h"
#include "queue"
using namespace std; 
namespace game{
	class Grid
	{
	public:
		int sumValue;
		int cellsOccupied;
		Node cell[gridSize][gridSize];

		Grid()
		{
			for (int i = 0; i < gridSize; ++i)
			{
				for (int j = 0; j < gridSize; ++j)
				{
					cell[i][j].x=i;
					cell[i][j].y=j;
					if(i-1>=0)	cell[i][j].next[0] = &cell[i-1][j];
					if(j-1>=0)	cell[i][j].next[1] = &cell[i][j-1];
					if(i+1<gridSize)	cell[i][j].next[2] = &cell[i+1][j];
					if(j+1<gridSize)	cell[i][j].next[3] = &cell[i][j+1];
				
				}
			}
		}

		int calculatePlayerValue(PlayerType player) const
		{
			int sum=0;
			for (int i = 0; i < gridSize; ++i)
			{
				for (int j = 0; j < gridSize; ++j)
				{
					if(cell[i][j].whoOccupy==player) sum+=cell[i][j].value;
				}
			}
			return sum;
		}

		int calculateDifference(PlayerType player) const
		{
		
			return calculatePlayerValue(player)-calculatePlayerValue(!player);
		}
		void updateCell(int x, int y, OccupiedType player)
		{
			//TODO
		}
	
		void calculateTotalValue()
		{
			sumValue=0;
			for (int i = 0; i < gridSize; ++i)
			{
				for (int j = 0; j < gridSize; ++j)
				{
					sumValue+=cell[i][j].value;
				}
			}
		}

		std::queue<Point*> *doBlitz( int i, int j)
		{
			queue<Point*> *p = new queue<Point*>;
			if(cell[i][j].whoOccupy==UNOCCUPIED) return p;
			PlayerType opponent = !cell[i][j].whoOccupy;
			for (int k = 0; k < 4; ++k)
			{
				if(cell[i][j].next[k]!=NULL && cell[i][j].next[k]->whoOccupy==opponent)
				{
					Point* pt = new Point();
					pt->x=cell[i][j].next[k]->x;
					pt->y=cell[i][j].next[k]->y;
					(p)->push(pt);
					cell[i][j].next[k]->whoOccupy=cell[i][j].whoOccupy;
					// cellsOccupied++;
				}
			}
			return p;
		}

		void undoBlitz( std::queue<Point*> *pts)
		{
			while(pts->size()>0)
			{
				Point *pt = pts->front();
				cell[pt->x][pt->y].whoOccupy =(OccupiedType)!cell[pt->x][pt->y].whoOccupy;
				pts->pop();
				delete pt;
				// cellsOccupied--;
			}
			delete pts;
		}
		friend ostream &operator<<(ostream &out, const Grid &c)     //output
		{
			for (int i = 0; i < gridSize; ++i)
			{
        		for (int j = 0; j < gridSize; ++j)
        		{
        			if(c.cell[i][j].whoOccupy==BLUE) out << "\033[34m"<<c.cell[i][j].value<<"\033[0m ";
        			else if(c.cell[i][j].whoOccupy==GREEN) out << "\033[32m"<<c.cell[i][j].value<<"\033[0m ";
        			else out<<c.cell[i][j].value<<" ";
        		}
        		out<<"\n";
			}
			return out;
		}
		friend istream &operator>>(istream &in,  Grid &c)     
		{
			for (int i = 0; i < gridSize; ++i)
			{
        		for (int j = 0; j < gridSize; ++j)
        		{
        			in>>c.cell[i][j].value; 
        		}
			}
			return in;
		}

	};
}
#endif