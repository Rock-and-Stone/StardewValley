#include "pch.h"
#include "enemyTestScene.h"

HRESULT enemyTestScene::init()
{
	/*_em = new EnemyManager;
	_em->init();
	_em->SetRockStone();*/
	_fs = new Fishing;
	_fs->init();
	return S_OK;
}

void enemyTestScene::update()
{
	//_em->update();
	_fs->update();
}

void enemyTestScene::release()
{
}

void enemyTestScene::render()
{
	//_em->render();
	_fs->render();
}
