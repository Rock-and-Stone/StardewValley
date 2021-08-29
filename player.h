#pragma once
#include "entity.h"
#include "playerState.h"


class player : public entity
{
private:

	int _x, _y; // ÁßÁ¡
	RECT _rc;
	image* _img;
	int _frameX, _frameY;

	playerState* _playerState;
	leftWalk* _leftwalk;
	rightWalk* _rightWalk;
	upWalk* _upWalk;
	downWalk* _downWalk;

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void setPlayer();
	void setFrameX(int x) { _frameX = x; }
	void setFrameY(int y) { _frameX = y; }
};

