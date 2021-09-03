#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>
#include <string>
#include "Enemy.h"
#include "EnemyManager.h"

#define TILEWIDTH 32
#define TILEHEIGHT 32

#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class EnemyAstar : public gameNode
{
private:
	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;

	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	vector<tile*>			_vPathList;
	vector<tile*>::iterator _viPathList;

	tile* _enemyTile;
	tile* _playerTile;
	tile* _currentTile;

	Enemy* _enemy;
	EnemyManager* _em;

	//aStar 연산하는걸 좀 느리게 보여주려고
	int _count;
	bool _start;

	bool _isFind;
	bool _isMove;

public:
	EnemyAstar();
	~EnemyAstar();

	HRESULT init();

	void setTiles();

	vector<tile*> addOpenList(tile* currentTile);

	void pathFinder(tile* currentTile);

	void release();
	void update();
	void render();

	bool GetIsFind() { return _isFind; }
	bool GetIsMove() { return _isMove; }
};

