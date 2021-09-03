#include "pch.h"
#include "EnemyAstar.h"
#include "RockStone.h"

EnemyAstar::EnemyAstar()
{
}

EnemyAstar::~EnemyAstar()
{
}

HRESULT EnemyAstar::init()
{
	_enemy = new RockStone;
	_em = new EnemyManager;
	_em->init();
	_em->SetRockStone();

	setTiles();

	_count = _start = 0;


	return S_OK;
}

void EnemyAstar::setTiles()
{
	_enemyTile = new tile;
	for (int i = 0; i < _em->GetVEnemy().size(); i++)
	{
		_enemyTile->init(_em->GetVEnemy()[i]->GetEnemyIdX(), _em->GetVEnemy()[i]->GetEnemyIdY());
	}
	_enemyTile->setAttribute("start");

	_playerTile = new tile;
	_playerTile->init(4, 4);
	_playerTile->setAttribute("end");

	//현재 타일은 시작타일로 둔다
	_currentTile = _enemyTile;

	for (int i = 0; i < TILENUMY; ++i)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			if (j == _enemyTile->getIdX() && i == _enemyTile->getIdY())
			{
				_enemyTile->setColor(RGB(0, 255, 255));
				_vTotalList.push_back(_enemyTile);
				continue;
			}
			if (j == _playerTile->getIdX() && i == _playerTile->getIdY())
			{
				_playerTile->setColor(RGB(10, 120, 55));
				_vTotalList.push_back(_playerTile);
				continue;
			}

			tile* node = new tile;
			node->init(j, i);
			_vTotalList.push_back(node);
		}
	}
}

vector<tile*> EnemyAstar::addOpenList(tile* currentTile)
{
	int startX = currentTile->getIdX() - 1;
	int startY = currentTile->getIdY() - 1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 0)
			{
				if (j == 0 || j == 2) continue;
			}
			else if (i == 1 && j == 1) continue;
			else if (i == 2)
			{
				if (j == 0 || j == 2) continue;
			}

			tile* node = _vTotalList[(startY * TILENUMX) + startX + j + (i * TILENUMX)];

			//예외처리
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if (node->getAttribute() == "wall") continue;

			//현재 타일 갱신해준다
			node->setParentNode(_currentTile);

			bool addObj = true;

			for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
			{
				//이미 있는 애면
				if (*_viOpenList == node)
				{
					addObj = false;
					break;
				}
			}

			if (node->getAttribute() != "end") node->setColor(RGB(128, 64, 28));

			//이미 체크된 애면
			if (!addObj) continue;

			if (node->getIdX() < 0) continue;
			if (node->getIdX() >= TILENUMX) continue;
			if (node->getIdY() < 0) continue;
			if (node->getIdY() >= TILENUMY) continue;

			_vOpenList.push_back(node);
		}
	}

	return _vOpenList;
}

void EnemyAstar::pathFinder(tile* currentTile)
{
	//비교하기 쉽게 임의의 경로비용을 설정해웁시둡시다
	float tempTotalCost = 5000;
	tile* tempTile = nullptr;

	//오픈리스트 벡터 안에서 가장 빠른 경로를 뽑아낸다
	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		//H 값 연산
		_vOpenList[i]->setCostToGoal(
			(abs(_playerTile->getIdX() - _vOpenList[i]->getIdX()) +
				abs(_playerTile->getIdY() - _vOpenList[i]->getIdY())) * 10);


		POINT center1 = _vOpenList[i]->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();
		//G 값 연산
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);

		//총 경로비용 연산
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
			_vOpenList[i]->getCostFromStart());


		//뽑아낸 총 경로비용 중에 가장 작은 비용인 애를 찾자
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();
			tempTile = _vOpenList[i];
		}

		bool addObj = true;

		for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
		{
			if (*_viOpenList == tempTile)
			{
				addObj = false;
				break;
			}
		}

		_vOpenList[i]->setIsOpen(false);
		if (!addObj) continue;

		_vOpenList.push_back(tempTile);
		
	}

	//도착했다
	if (tempTile->getAttribute() == "end")
	{

		_isFind = true;
		_isMove = true;
		//최단 경로는 색칠해웁시줍시다
		while (_currentTile->getParentNode() != NULL)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_currentTile = _currentTile->getParentNode();
		}
		return;
	}
	else _isFind = false;

	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	//이거는 사방이 막혀있을 때 안터지게 하기 위한 용도.
	if (_vOpenList.size() == 0) _start = false;

	_currentTile = tempTile;
}

void EnemyAstar::release()
{
}

void EnemyAstar::update()
{
	if (KEYMANAGER->isOnceKeyDown('S')) _start = true;

	if (_start)
	{
		_count++;
		if (_count % 2 == 0)
		{
			pathFinder(_currentTile);
			_count = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vTotalList.size(); ++i)
		{
			RECT rc = _vTotalList[i]->getRect();

			if (PtInRect(&rc, _ptMouse))
			{
				if (_vTotalList[i]->getAttribute() == "start") continue;
				if (_vTotalList[i]->getAttribute() == "end") continue;
				
				_vTotalList[i]->setIsOpen(false);
				_vTotalList[i]->setAttribute("wall");
				_vTotalList[i]->setColor(RGB(230, 140, 200));
				break;
			}
		}
	}

	_em->update();
}

void EnemyAstar::render()
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}

	_em->render();

	char str[256];
	for (int i = 0; i < _em->GetVEnemy().size(); i++)
	{
		sprintf_s(str, "%d %d", _em->GetVEnemy()[i]->GetEnemyIdX(), _em->GetVEnemy()[i]->GetEnemyIdY());
		TextOut(getMemDC(), 100, 100 * (i+1), str, strlen(str));
	}
	
}

