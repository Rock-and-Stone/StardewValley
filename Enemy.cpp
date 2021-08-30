#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	_image = IMAGEMANAGER->findImage(imageName);

	_pos.x = position.x;
	_pos.y = position.y;

	_enemyDirection = DOWN;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
}

void Enemy::render()
{
	Draw();
}

void Enemy::Move()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_enemyDirection = DOWN;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_enemyDirection = RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_enemyDirection = UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_enemyDirection = LEFT;
	}
}

void Enemy::Draw()
{
	_frameCount++;
	_image->setFrameX(_frameX);
	_image->setFrameY(_frameY);

	switch (_enemyDirection)
	{
	case DOWN:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case RIGHT:
		_frameY = 1;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case UP:
		_frameY = 2;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case LEFT:
		_frameY = 3;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	}
	_image->frameRender(getMemDC(), _pos.x, _pos.y, _frameX, _frameY);
}

void Enemy::Collision()
{
}
