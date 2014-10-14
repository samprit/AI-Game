#ifndef COMMON_H
#define COMMON_H 

namespace game {
enum OccupiedType {BLUE, GREEN, UNOCCUPIED};
enum MoveType {PARADROP,BLITZ};
const int gridSize = 6;
const int treeDepthAlpha=3, treeDepthMin = 4;
typedef OccupiedType PlayerType ;
typedef struct Point
{
	int x,y;
}Point;
PlayerType operator!(const PlayerType p);
}
#endif
