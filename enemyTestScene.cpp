#include "pch.h"
#include "enemyTestScene.h"

HRESULT enemyTestScene::init()
{
	_as = new aStarTest;
	_as->init();
	_em = new EnemyManager;
	_em->init();
	_em->SetRockStone({ WINSIZEX / 2, WINSIZEY / 2 }, 1);
	return S_OK;
}

void enemyTestScene::update()
{
	_as->update();
	_em->update();
}

void enemyTestScene::release()
{
}

void enemyTestScene::render()
{
	_as->render();
	_em->render();
}
