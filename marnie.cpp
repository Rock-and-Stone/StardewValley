#include "pch.h"
#include "marnie.h"
#include "CameraManager.h"

marnie::marnie()
{
}

marnie::~marnie()
{
}

HRESULT marnie::init(int indX, int indY)
{

	_x = indX * TILESIZE + (TILESIZE / 2),
	_y = indY * TILESIZE + (TILESIZE / 2);

	_rc = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);

	_img = IMAGEMANAGER->findImage("marnie");

	return S_OK;
}

void marnie::release()
{
}

void marnie::update()
{
	_rc = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	int tileX, tileY;

	RECT rcCollision;
	rcCollision = _rc;

	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;

	_idX = tileX;
	_idY = tileY;
}

void marnie::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());
}

//갈수있는 길을 추가하는 함수
vector<tile*> marnie::addOpenList(tile* currentTile)
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
				if (j == 0 || j == 2)continue;
			}

			tile* node = _vTotalList[(startY * TILEX) + startX + j + (i * TILEY)];

			//예외처리
			if (!node->getIsOpen()) continue;
			if (node->getAttribute() == "start") continue;
			if (node->getAttribute() == "wall") continue;



			//현재 타일 갱신해준다
			node->setParentNode(_currentTile);

			bool addObj = true;

			for (int i = 0; i < _vOpenList.size(); i++)
			{
				//이미 있는 애면
				if (_vOpenList[i] == node)
				{
					addObj = false;
					break;
				}
			}


			if (node->getAttribute() != "end") node->setColor(RGB(255, 0, 0));

			//이미 체크된 애면
			if (!addObj) continue;

			//뒤로 넘어가지 않게 하기위한 예외 처리
			if (node->getIdX() <= 0) continue;
			if (node->getIdX() >= TILEX) continue;
			if (node->getIdY() <= 0) continue;
			if (node->getIdY() >= TILEY) continue;

			_vOpenList.push_back(node);
		}

	}
	return _vOpenList;
}

void marnie::pathFinder(tile* currentTile)
{
	//비교하기 쉽게 임의의 경로비용을 설정해웁시둡시다
	float tempTotalCost = 5000;
	tile* tempTile = nullptr;

	//오픈리스트 벡터 안에서 가장 빠른 경로를 뽑아낸다
	for (int i = 0; i < addOpenList(currentTile).size(); ++i)
	{
		//H 값 연산
		_vOpenList[i]->setCostToGoal(
			(abs(_endTile->getIdX() - _vOpenList[i]->getIdX()) +
				abs(_endTile->getIdY() - _vOpenList[i]->getIdY())) * 10);

		POINT center1 = _vOpenList[i]->getParentNode()->getCenter();
		POINT center2 = _vOpenList[i]->getCenter();

		//G 값 연산
		//4 방향일 경우 14를 곱할 이유가 없어진다.
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
		_mitsuketa = true;

		//최단 경로는 색칠해웁시줍시다
		while (_currentTile->getParentNode() != nullptr)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_vGoList.push_back(_currentTile);
			_currentTile = _currentTile->getParentNode();
		}
		return;

	}


	_vCloseList.push_back(tempTile);

	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	for (int i = 0; i < _vCloseList.size(); i++)
	{
		_vCloseList[i]->setColor(RGB(255, 0, 255));
	}

	_currentTile = tempTile;

	if (_vOpenList.size() == 0) //남아있는 오픈리스트가 없다면 함수종료.
	{
		_start = false;
		return;
	}

	//재귀함수
	//재귀함수를 쓰면 코드가 매우 짧아지고 간결해지는 이점이 있으나
	//속도면에서는 느리고
	//또 한 번 호출될때마다 소량의 메모리가 쌓이는데
	//총 1.2메가 이상 쌓이면 터지는데 이걸 스택오버플로우라고 한다.
	//pathFinder(_currentTile);
}