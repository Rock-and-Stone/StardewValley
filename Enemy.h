#pragma once
#include "entity.h"
#include "CameraManager.h"

enum ENEMYDIRECTION
{
	DOWN, RIGHT, UP, LEFT
};

enum ENEMYSTATEMENT
{
	IDLE, CHASE, ATTACK, DEAD
};

class Enemy : public entity
{
protected:
	ENEMYSTATEMENT _enemyStatement;
	ENEMYDIRECTION _enemyDirection;
	CameraManager* _cm;	
	image* _image;		
	RECT _rc;			
	POINT _pos;			//절대좌표
	POINT _rend;		//렌더좌표

	int _fullHP;		//전체체력
	int _currentHP;		//현재체력

	int _frameCount = 0;	//에너미 이미지 프레임카운트
	int _frameX = 0;		//에너미 이미지 프레임X
	int _frameY = 0;		//에너미 이미지 프레임Y



public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void SwitchImage() = 0;


	void Move();
	void Draw();
	void Collision();

public:
	//frame 값 접근,설정자
	int GetEnemyFrameX() { return _frameX; }
	void SetEnemyFrameX(int frameX) { _frameX = frameX; }
	int GetEnemyFrameY() { return _frameY; }
	void SetEnemyFrameY(int frameY) { _frameY = frameY; }

	//pos 값 접근,설정자
	int GetEnemyPosX() { return _pos.x; }
	void SetEnemyPosX(int posX) { _pos.x = posX; }
	int GetEnemyPosY() { return _pos.y; }
	void SetEnemyPosY(int posY) { _pos.y = posY; }

};
