#pragma once
#include "entity.h"
#include "playerState.h"
#include "inventory.h"

class homeMap;
class CameraManager;

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
	RECT _rc;
	RECT _renderRC;

	image* _img;

	int _x, _y; // 중점
	int _frameX, _frameY,_maxFrameX;
	bool _isMoving;
	int _rendX, _rendY;
	int _idX, _idY;
	int _dir; // 0 오 1 왼 2 위 3아래
	int _count;

	int _gold, _stamina;

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







	void setPlayerDirection(PLAYERDIRECTION direction) { _direction = direction; }
	void setFrameX(int x) { _frameX = x; }
	void setFrameY(int y) { _frameY = y; }
	void setMaxFrameX(int x) { _maxFrameX = x; }

	image* setPlayerImg(image* img) { _img = img; }

	void setMapAddressLink(homeMap* hm) { _homeMap = hm; }

	int getX() { return _x; }
	int getY() { return _y; }
	int getDir() { return _dir; }
	void setRenderX(int rendX) { _rendX = rendX; }
	void setRenderY(int rendY) { _rendY = rendY; }
	
	int getRenderY() { return _rendY; }


	virtual int getRenderPosY() { return _y + 20; }
	
	void setGold(int gold) { _gold = gold; }
	int getGold() { return _gold; }
	void setStamina(int stamina) { _stamina = stamina; }
	int getStamina() { return _stamina; }

	RECT getRect() { return _rc; }


	void SetInventoryCameraMemoryLink(CameraManager* cm) { _inventory->SetCameraMemoryLink(cm); }
};

