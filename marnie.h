#pragma once

#include "entity.h"
#include "homeMap.h"
#include "tile.h"
#include "tileNode.h"
#include <vector>
#include <string>


class CameraManager;

class marnie : public entity
{
private:
	RECT _rc;
	image* _img;
	int _x, _y;   //ÁßÁ¡
	int _idX, _idY;

	CameraManager* _cameraManager;

	vector<tile*>			_vTotalList;
	vector<tile*>::iterator _viTotalList;

	vector<tile*>			_vOpenList;
	vector<tile*>::iterator _viOpenList;

	vector<tile*>			_vCloseList;
	vector<tile*>::iterator _viCloseList;

	vector<tile*>			_vGoList;
	vector<tile*>::iterator _viGoList;

	tile* _startTile;
	tile* _endTile;
	tile* _currentTile;


	int _count;
	int _i;
	bool _start;
	bool _mitsuketa;
	bool _isCheck;

public:
	marnie();
	~marnie();

	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();

	vector<tile*> addOpenList(tile* currentTile);

	void pathFinder(tile* currentTile);

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	virtual int getRenderPosY() { return _y; }
	RECT getRect() { return _rc; }

};

