#pragma once
#include "tileNode.h"
#include "gameNode.h"
#include "button.h"



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
	CTRL ctrl;
	string str;
	int page;
};


class Map : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];		//타일
	DWORD _attribute[TILEX * TILEY];	//타일속성

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];

	string _currentSampleString;

	RECT _dragRC;

	image* _background;
	image* _currentSample;

	button* _buttonSave;
	button* _buttonLoad;
	button* _buttonDraw;
	button* _buttonObject;
	button* _buttonErase;
	button* _buttonLeft;
	button* _buttonRight;
	button* _buttonDragMode;

	int _pos[2];
	int _ctrSelect;
	int _ctrPage;

	bool _isPicked;
	bool _isSample;
	bool _isDragMode;
	bool _isStart;

	float _posX, _posY;
	float _rendX, _rendY;
	float _dragStartX, _dragStartY;

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
	
	void RectSensor();

	void DrawTile();
	void DrawObject();

	void SetSample();
	void ChangeSample();
	void PickSample();
	void DrawMap();
	void DragMap(bool isDrag);
	void AutoDraw(tagTile* currentTile);

	static void Button(void* obj);

	tagTile* getTile() { return _tiles; }

	//STEP2
	//타일속성에 대한 접근자도 만들어주어야 할껍니다
	DWORD* getAttribute() { return _attribute; }

	TERRAIN terrainSelect(int frameX, int frameY, int page);
	OBJECT objSelect(int frameX, int frameY, int page);

	//우린 사용하고 있지 않습니다
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	bool getDragMode() { return _isDragMode; }
};

