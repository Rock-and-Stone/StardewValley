#pragma once
#include "entity.h"
#include "playerState.h"

class homeMap;

enum PLAYERDIRECTION
{
	PLAYERDIRECTION_LEFT,
	PLAYERDIRECTION_UP,
	PLAYERDIRECTION_RIGHT,
	PLAYERDIRECTION_DOWN,
	PLAYERDIRECTION_IDLE
};

class player : public entity
{
private:

	PLAYERDIRECTION	_direction;
	RECT _rc;
	RECT _renderRC;

	image* _img;

	int _x, _y; // ÁßÁ¡
	int _frameX, _frameY;
	int _tileX;
	bool _isMoving;
	int _rendX, _rendY;
	int _idX, _idY;

	playerState* _playerState;
	leftWalk* _leftWalk;
	rightWalk* _rightWalk;
	upWalk* _upWalk;
	downWalk* _downWalk;


	homeMap* _homeMap;

public:
	player();
	~player();

	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void setPlayerDirection(PLAYERDIRECTION direction) { _direction = direction; }
	void setFrameX(int x) { _frameX = x; }
	void setFrameY(int y) { _frameX = y; }
	image* setPlayerImg(image* img) { _img = img; }

	void setMapAddressLink(homeMap* hm) { _homeMap = hm; }

	int getX() { return _x; }
	int getY() { return _y; }

	void setRenderX(int rendX) { _rendX = rendX; }
	void setRenderY(int rendY) { _rendY = rendY; }

	virtual int getRenderPosY() { return _y + 20; }

	RECT getRect() { return _rc; }
};

