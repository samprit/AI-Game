#ifndef NODE_H
#define NODE_H 


#include "common.h"
#include "stdio.h"
namespace game {
class Node
{
public:
	int value;
	int x,y;
	OccupiedType whoOccupy;
	Node *next[4]; //order{left,right,top,bottom}

	Node()
	{
		value=0;
		whoOccupy=UNOCCUPIED;
		for (int i = 0; i < 4; ++i)
		{
			next[i]=NULL;
		}
	}

	Node(int x, int y, int value,OccupiedType whoOccupy=UNOCCUPIED)
	{
		this->value = value;
		this->x = x;
		this->y = y;
		this->whoOccupy = whoOccupy;
		for (int i = 0; i < 4; ++i)
		{
			next[i]=NULL;
		}
	}

	Node operator=(const Node b)
	{
		this->value = b.value;
		this->x = b.x;
		this->y = b.y;
		this->whoOccupy = b.whoOccupy;
		for (int i = 0; i < 4; ++i)
		{
			next[i]=b.next[i];
		}
	}
	/* data */
};
}
#endif
