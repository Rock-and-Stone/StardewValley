#pragma once
#include "entity.h"
#include "RockStone.h"
#include <vector>
#include "CameraManager.h"

class EnemyManager :
    public entity
{
private:
	typedef vector<Enemy*>				 vEnemy;
	typedef vector<Enemy*>::iterator	 viEnemy;

private:
	vEnemy	_vEnemy;
	viEnemy _viEnemy;
	CameraManager* _cm;
	Enemy* _enemy;

	int _rockStoneNum;
	
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void SetRockStone();

	vector<Enemy*> GetVEnemy() { return _vEnemy; }
	vector<Enemy*>::iterator GetVIEnemy() { return _viEnemy; }
};
