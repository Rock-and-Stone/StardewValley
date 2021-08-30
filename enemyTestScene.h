#pragma once
#include "gameNode.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "RockStone.h"
#include "aStarTest.h"

class enemyTestScene : public gameNode
{
private:
	EnemyManager* _em;
	aStarTest* _as;

public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

