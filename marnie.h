#pragma once

#include "entity.h"

class CameraManager;

class marnie : public entity
{
private:
	RECT _rc;
	image* _img;
	int _x, _y;   //ÁßÁ¡
	int _idX, _idY;

	CameraManager* _cameraManager;


public:
	marnie();
	~marnie();

	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	virtual int getRenderPosY() { return _y; }
	RECT getRect() { return _rc; }

};

