#pragma once
#include "entity.h"

class CameraManager;

class wizard : public entity
{
private:
	RECT _rc;
	image* _img;
	int _x, _y;   //ÁßÁ¡
	int _idX, _idY;

	CameraManager* _cameraManager;
public:
	wizard();
	~wizard();
	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	virtual int getRenderPosY() { return _y; }
	RECT getRect() { return _rc; }

};

