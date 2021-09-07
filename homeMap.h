#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

#define TILEHEIGHT 32
#define TILEWIDTH 32

class CameraManager;

class homeMap : public  gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//타일
	DWORD _attribute[TILEX * TILEY];	//타일속성

	CameraManager* _cameraManager;

	int _pos[2];

	typedef vector<tagTile>			  _vTile;
	typedef vector<tagTile>::iterator _viTile;

public:
	homeMap();
	~homeMap();

	HRESULT init();
	void release();
	void update();
	void render();
	
	
	void load();


	tagTile* getTile() { return _tiles; }

	//STEP2
	//타일속성에 대한 접근자도 만들어주어야 할껍니다
	DWORD* getAttribute() { return _attribute; }

	//우린 사용하고 있지 않습니다
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	void setCameraLink(CameraManager* cm) { _cameraManager = cm; }
};

