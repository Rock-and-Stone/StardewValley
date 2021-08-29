#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include "button.h"

//타일 셋 가로 20줄 세로 9줄
#define SAMPLEOBJECTX 13
#define SAMPLEOBJECTY 18


enum CTRL
{
	CTRL_SAVE,			//세이브		버튼
	CTRL_LOAD,			//로드		버튼
	CTRL_TERRAINDRAW,	//지형		버튼
	CTRL_OBJDRAW,		//오브젝트	버튼
	CTRL_ERASER,		//지우개		버튼
	CTRL_END
};

struct tagCurrentTile
{
	int x;
	int y;
};


class Map : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//타일
	DWORD _attribute[TILEX * TILEY];	//타일속성

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];

	button* _buttonSave;
	button* _buttonLoad;
	button* _buttonDraw;
	button* _buttonObject;
	button* _buttonErase;

	button* _buttonLeft;
	button* _buttonRight;

	int _pos[2];
	int _ctrSelect;
	bool _isPicked;

	float _posX, _posY;
	float _rendX, _rendY;

public:
	Map();
	~Map();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void save();
	void load();

	void Movement();

	void SetSample(int select, string str);
	void PickSample();
	void DrawMap();
	void AutoDraw(tagTile* currentTile);

	static void Button(void* obj);

	tagTile* getTile() { return _tiles; }


	//STEP2
	//타일속성에 대한 접근자도 만들어주어야 할껍니다
	DWORD* getAttribute() { return _attribute; }

	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	//우린 사용하고 있지 않습니다
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	
};

