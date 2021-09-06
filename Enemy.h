#pragma once
#include "entity.h"
#include "tile.h"
#include <vector>
#include <string>
#include "CameraManager.h"
#include "tileNode.h"

enum ENEMYDIRECTION
{
	DOWN, RIGHT, UP, LEFT, STOP
};

enum ENEMYSTATEMENT
{
	IDLE, CHASE, ATTACK, DEAD
};

class Enemy : public entity
{
protected:
	//aStar!!
	

	

	ENEMYSTATEMENT _enemyStatement;
	ENEMYDIRECTION _enemyDirection;
	CameraManager* _cm;	
	image* _image;		
	RECT _rc;			
	POINT _pos;			//절대좌표
	POINT _rend;		//렌더좌표
	int _posX, _posY;	//절대좌표
	int _idX, _idY;		//에너미 인덱스 좌표

	int _fullHP;		//전체체력
	int _currentHP;		//현재체력

	int _frameCount = 0;	//에너미 이미지 프레임카운트
	int _frameX = 0;		//에너미 이미지 프레임X
	int _frameY = 0;		//에너미 이미지 프레임Y



public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void SwitchImage() = 0;

#pragma region ASTAR!!!
protected:
	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;

	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	vector<tile*>			_vGoList;
	vector<tile*>::iterator _viGoList;

	tile* _startTile;
	tile* _endTile;
	tile* _currentTile;

	int _i;
	int _count;							//시작노드, 종료노드를 한번씩만 선택하기 위한 변수
	float _speed = 5.0f;
	bool _isFind;						//길 찾았냐?
	bool _isMove;						//움직이냐?
	bool _start;
	bool _isArrive;
	bool _isCheck;

public:
	void setTiles();
	vector<tile*> addOpenList(tile* currentTile);
	void pathFinder(tile* currentTile);
	void setEnemyPosition(tile* tile);
#pragma endregion

	void Move();
	void Draw();
	void Collision();

public:
	//frame 값 접근,설정자
	int GetEnemyFrameX() { return _frameX; }
	void SetEnemyFrameX(int frameX) { _frameX = frameX; }
	int GetEnemyFrameY() { return _frameY; }
	void SetEnemyFrameY(int frameY) { _frameY = frameY; }

	//pos 값 접근,설정자
	int GetEnemyPosX() { return _posX; }
	void SetEnemyPosX(int posX) { _posX = posX; }
	int GetEnemyPosY() { return _posY; }
	void SetEnemyPosY(int posY) { _posY = posY; }

	//index 값 접근,설정자
	int GetEnemyIdX() { return _idX; }
	void SetEnemyIdX(int idX) { _idX = idX; }
	int GetEnemyIdY() { return _idY; }
	void SetEnemyIdY(int idY) { _idY = idY; }

	//aStar 접근자
	bool GetIsArrive() { return _isArrive; }
	void SetIsArrive(bool arrive) { _isArrive = arrive; }
	vector<tile*> getVectorTile() { return _vOpenList; }
	tile* getCurrentTile() { return _currentTile; }
	vector<tile*> getGoTile() { return _vGoList; }

};
