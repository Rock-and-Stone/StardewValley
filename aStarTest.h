#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>
#include <string>

#define TILEWIDTH 32
#define TILEHEIGHT 32

#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class aStarTest : public gameNode
{
private:
	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;

	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	tile* _startTile;
	tile* _endTile;
	tile* _currentTile;

	//aStar 연산하는걸 좀 느리게 보여주려고
	int _count;
	bool _start;

public:
	aStarTest();
	~aStarTest();

	HRESULT init();

	void setTiles();

	vector<tile*> addOpenList(tile* currentTile);

	void pathFinder(tile* currentTile);
	   
	void release();
	void update();
	void render();
};

