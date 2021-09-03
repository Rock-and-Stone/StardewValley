#pragma once
#include "gameNode.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "RockStone.h"
#include "EnemyAstar.h"

class enemyTestScene : public gameNode
{
private:
	EnemyManager* _em;
	EnemyAstar* _ea;

public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

