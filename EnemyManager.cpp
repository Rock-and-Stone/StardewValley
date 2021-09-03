#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"

HRESULT EnemyManager::init()
{
	return S_OK;
}

void EnemyManager::release()
{
}

void EnemyManager::update()
{
    for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
    {
        (*_viEnemy)->update();
    }
}

void EnemyManager::render()
{
    for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
    {
        (*_viEnemy)->render();
    }
}

void EnemyManager::SetRockStone()
{
    //int rnd;
    Enemy* rockstone;
    rockstone = new RockStone;
    rockstone->init("RockStone", PointMake(200, WINSIZEY/2));
    rockstone->init();
    _vEnemy.push_back(rockstone);
}

