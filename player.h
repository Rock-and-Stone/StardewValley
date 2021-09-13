#pragma once
#include "entity.h"
#include "playerState.h"
#include "inventory.h"
#include "boxInventory.h"
#include <vector>

class homeMap;
class CameraManager;
class objectManager;

enum PLAYERDIRECTION
{
	PLAYERDIRECTION_LEFT,
	PLAYERDIRECTION_UP,
	PLAYERDIRECTION_RIGHT,
	PLAYERDIRECTION_DOWN,
	PLAYERDIRECTION_IDLE,
	PLAYERDIRECTION_ACTIVATE
};

class player : public entity
{
private:

	PLAYERDIRECTION	_direction;
	RECT _rc,_interectiveRc;
	RECT _renderRC,_intRenderRc;

	image* _img;

	int _x, _y; // 중점
	int _frameX, _frameY,_maxFrameX;
	int _rendX, _rendY;
	int _idX, _idY;
	int _dir; // 0 오 1 왼 2 위 3아래
	int _count;
	int _tileIndex,_interectiveIndex;
	int _HP, _gold, _stamina;
	bool _isLift,_isWalk;

	playerState* _playerState;
	leftWalk* _leftWalk;
	rightWalk* _rightWalk;
	upWalk* _upWalk;
	downWalk* _downWalk;

	playerAxe* _playerAxe;
	playerCan* _playerCan;
	playerHoe* _playerHoe;
	playerPickAxe* _playerPickAxe;
	playerRod* _playerRod;
	playerSickle* _playerSickle;
	playerSword* _playerSword;

	homeMap* _homeMap;
	inventory* _inventory;
	CameraManager* _cameraManager;
	objectManager* _objectManager;
	boxInventory* _boxInventory;

	vector<boxInventory*>			  _vBoxIv;
	vector<boxInventory*>::iterator  _viBoxIv;

public:
	player();
	~player();

	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void changePlayerTool();
	void activate();
	void InventoryDraw();

	void liftItem();

	void walkSound();

	void makeInterectiveRc();

	void openBox();

	void drawBoxIven();

	void LbuttonAcvite();

	void setPlayerDirection(PLAYERDIRECTION direction) { _direction = direction; }
	void setFrameX(int x) { _frameX = x; }
	void setFrameY(int y) { _frameY = y; }
	void setMaxFrameX(int x) { _maxFrameX = x; }

	image* setPlayerImg(image* img) { _img = img; }

	void setMapAddressLink(homeMap* hm) { _homeMap = hm; }

	int getX() { return _x; }
	int getY() { return _y; }
	int getDir() { return _dir; }
	int getPlayerTile() { return _tileIndex; }
	void setRenderX(int rendX) { _rendX = rendX; }
	void setRenderY(int rendY) { _rendY = rendY; }
	int getRenderX() { return _rendX; }
	int getRenderY() { return _rendY; }


	virtual int getRenderPosY() { return _y + 20; }
	
	virtual void setGold(int gold) { _gold = gold; }
	virtual int getGold() { return _gold; }
	virtual void setStamina(int stamina) { _stamina = stamina; }
	virtual int getStamina() { return _stamina; }
	
	void GoldGet(int gold) { _gold += gold; };

	RECT getRect() { return _rc; }
	RECT getRenderRc() { return _renderRC; }
	RECT getInterectiveRc() { return _interectiveRc; }
	RECT getIntRenderRc() { return _intRenderRc; }

	inventory* GetInventory() { return _inventory; }

	void SetInventoryCameraMemoryLink(CameraManager* cm) { _inventory->SetCameraMemoryLink(cm); }
	void SetPlayerObjectManagerMemoryLink(objectManager* om) { _inventory->SetObjectManagerMemoryLink(om); }

	void SetBoxInvenPlayer(boxInventory* bm) { _boxInventory = bm; }
	void SetBoxInventory(boxInventory* bm) { _inventory->SetBoxInventory(bm); }
	void SetHomeMapMemoryLink(homeMap* hm) { _homeMap = hm; }
	void setCameraMemoryLink(CameraManager* cm) { _cameraManager = cm; }
	void setObjectMemoryLink(objectManager* om) { _objectManager = om; }
};

