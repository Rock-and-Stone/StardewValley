#pragma once
#include "entity.h"
#include "playerState.h"

enum PLAYERDIRECTION
{
	PLAYERDIRECTION_LEFT,
	PLAYERDIRECTION_UP,
	PLAYERDIRECTION_RIGHT,
	PLAYERDIRECTION_DOWN
};

class player : public entity
{
private:

	PLAYERDIRECTION	_direction;

	int _x, _y; // ÁßÁ¡
	RECT _rc;
	image* _img;
	int _frameX, _frameY;
	int _tileX;

	playerState* _playerState;
	leftWalk* _leftwalk;
	rightWalk* _rightWalk;
	upWalk* _upWalk;
	downWalk* _downWalk;


public:
	player();
	~player();

	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void setPlayer();
	void tileSearch();
	void setFrameX(int x) { _frameX = x; }
	void setFrameY(int y) { _frameX = y; }
	image* setPlayerImg(image* img) { _img = img; }
};

