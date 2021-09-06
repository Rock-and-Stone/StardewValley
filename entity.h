#pragma once
#include "gameNode.h"
#include "homeMap.h"
#include "CameraManager.h"

class entity : public gameNode
{
public : 
	entity();
	~entity();

	virtual HRESULT init();
	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void render(int camX, int camY);
	
	virtual int getRenderPosY();
	virtual bool getReleased();
	virtual void setMapAddressLink(homeMap* hm);
	virtual void setCameraAddressLink(CameraManager* cm);

	virtual int getX();
	virtual int getY();
	virtual void setRenderX(int rendX);
	virtual void setRenderY(int rendY);
	RECT getRect();
};