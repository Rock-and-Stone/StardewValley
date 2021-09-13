#pragma once
#include "entity.h"

class CameraManager;
class entity;

class wizard : public entity
{
private:
	RECT _rc,_renderRc;
	image* _img;
	int _x, _y;   //ÁßÁ¡
	int _idX, _idY;
	int _dialogueNum;
	CameraManager* _cameraManager;
	entity* _player;

public:
	wizard();
	~wizard();
	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	void setPlayerAddressLink(entity* pl) { _player = pl; }
	virtual int getRenderPosY() { return _y; }
	RECT getRect() { return _rc; }
	RECT getRenderRc() { return _renderRc; }
	void setX(int x) { _x = x; }
	void dialogue();
	void shop();
	int getDialogueNum() { return _dialogueNum; }
	void setDialogueNum(int num) { _dialogueNum = num; }
};

