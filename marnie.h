#pragma once
#include "entity.h"
#include "tileNode.h"
#include "tile.h"

class CameraManager;
class entity;

enum MARNIE_DIRECTION
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	STOP
};

class marnie : public entity
{
private:
	RECT _rc,_renderRc;
	image* _img;
	int _x, _y;   //ÁßÁ¡
	int _dialogueNum;
	int _count,_frameX;
	bool _isArrive;

	CameraManager* _cameraManager;
	entity* _player;

	RECT crow1rc,crow2rc;
	image* shopSelectImg;

	MARNIE_DIRECTION _direction;
	
public:
	marnie();
	~marnie();

	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	void setPlayerAddressLink(entity* pl) { _player = pl; }
	virtual int getRenderPosY() { return _y; }
	RECT getRect() { return _rc; }
	RECT getRenderRc() { return _renderRc; }
	void dialogue();
	void shop();
	void marnieMove();
	void setMarniePosition(tagTile* tile);
	int getDialogueNum() { return _dialogueNum; }
	void setDialogueNum(int num) { _dialogueNum = num; }

	bool getIsArrive() { return _isArrive; }
	void setIsArrive(bool isArrive) { _isArrive = isArrive; }
};

