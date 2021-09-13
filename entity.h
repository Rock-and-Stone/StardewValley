#pragma once
#include "gameNode.h"
#include "homeMap.h"
#include "CameraManager.h"
#include "inventory.h"
#include "objectManager.h"
#include "boxInventory.h"
#include "tile.h"

class entity : public gameNode
{
public:
	entity();
	~entity();

	virtual HRESULT init();
	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void render(int camX, int camY);
	virtual void InventoryDraw();

	virtual int getRenderPosY();
	virtual bool getReleased();
	virtual void setMapAddressLink(homeMap* hm);
	virtual void setCameraAddressLink(CameraManager* cm);
	virtual void SetInventoryCameraMemoryLink(CameraManager* cm);


	virtual int getX();
	virtual int getY();
	virtual void setRenderX(int rendX);
	virtual void setRenderY(int rendY);
	virtual RECT getRect();
	virtual RECT getRenderRc();
	virtual RECT getIntRenderRc();
	virtual RECT getInterectiveRc();
	virtual void dialogue();
	virtual int getGold();
	virtual void setX(int x), setY(int y);
	void GoldGet(int gold);
	virtual int getPlayerTile();
	virtual inventory* GetInventory();
	virtual void SetPlayerObjectManagerMemoryLink(objectManager* om);
	virtual void SetBoxInvenPlayer(boxInventory* bm);
	virtual void SetBoxInventory(boxInventory* bm);
	virtual void SetHomeMapMemoryLink(homeMap* hm);
	virtual void setCameraMemoryLink(CameraManager* cm);
	virtual void setObjectMemoryLink(objectManager* om);
	virtual int getDialogueNum();
	virtual void setDialogueNum(int num);
	virtual void drawBoxIven();
	virtual void openBox();
	virtual void setPlayerAddressLink(entity* pl);
	virtual void setGold(int gold);
	virtual void setMarniePosition(tagTile* tile);
	virtual bool getIsArrive();
	virtual void setIsArrive(bool isArrive);
	virtual int getMarnieIndX();
	virtual int getMarnieIndY();
};