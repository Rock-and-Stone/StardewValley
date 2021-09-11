#include "pch.h"
#include "aStarTest.h"


aStarTest::aStarTest()
{
}

aStarTest::~aStarTest()
{
}

HRESULT aStarTest::init()
{
	setTiles();

	_count = _start = 0;


	return S_OK;
}

void aStarTest::setTiles() // 타일 세팅
{
	_startTile = new tile;
	_startTile->init(4, 12);
	_startTile->setAttribute("start");

	_endTile = new tile;
	_endTile->init(20, 12);
	_endTile->setAttribute("end");

	//현재 타일은 시작타일로 둔다
	_currentTile = _startTile;

	for (int i = 0; i < TILENUMY; ++i) // 열 길이만큼
	{
		for (int j = 0; j < TILENUMX; ++j) // 행 길이만큼
		{
			if (j == _startTile->getIdX() && i == _startTile->getIdY()) // 시작점 노드일경우 색지정후 벡터에 집어넣는다.
			{
				_startTile->setColor(RGB(0, 255, 255));
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY()) // 도착점 노드일경우 색지정후 벡터에 집어넣는다.
			{
				_endTile->setColor(RGB(10, 120, 55));
				_vTotalList.push_back(_endTile);
				continue;
			}

			tile* node = new tile; // 이외에 노드들의 경우 초기화 후 벡터에 집어넣는다.
			node->init(j, i);
			_vTotalList.push_back(node);
		}
	}
}

//갈수있는 길을 추가하는 함수
vector<tile*> aStarTest::addOpenList(tile* currentTile)
{
	//검색 시작점을 상단좌측 노드로 지정
	int startX = currentTile->getIdX() - 1; 
	int startY = currentTile->getIdY() - 1;

	// 자신을 포함한 9칸을 검색
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; ++j)
		{
			tile* node = _vTotalList[(startY * TILENUMX) + startX + j + (i * TILENUMX)]; //노드를 새로생성하여 검색된 노드를 대입

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

			_vOpenList.push_back(node);
		}
	}

	return _vOpenList;
}

//길을 찾아라~
void aStarTest::pathFinder(tile* currentTile)
{
	//비교하기 쉽게 임의의 경로비용을 설정해둔다
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
		_vOpenList[i]->setCostFromStart((getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);

		//총 경로비용 연산
		_vOpenList[i]->setTotalCost(_vOpenList[i]->getCostToGoal() +
									_vOpenList[i]->getCostFromStart());


		//뽑아낸 총 경로비용 중에 가장 작은 비용 검색
		if (tempTotalCost > _vOpenList[i]->getTotalCost())
		{
			tempTotalCost = _vOpenList[i]->getTotalCost();
			tempTile = _vOpenList[i];
		}

		bool addObj = true;
		
		//만약 경로비용이 적은노드가 뽑혔다면 해당 노드는 검색에서 제외함
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

	//도착
	if (tempTile->getAttribute() == "end")
	{
		//최단 경로 색칠
		while (_currentTile->getParentNode() != NULL)
		{
			_currentTile->setColor(RGB(22, 14, 128));
			_currentTile = _currentTile->getParentNode();
		}
		return;
	}

	_vCloseList.push_back(tempTile);

	//추가경로 검색
	for (_viOpenList = _vOpenList.begin(); _viOpenList != _vOpenList.end(); ++_viOpenList)
	{
		if (*_viOpenList == tempTile)
		{
			_viOpenList = _vOpenList.erase(_viOpenList);
			break;
		}
	}

	_currentTile = tempTile;

	//재귀함수
	//재귀함수를 쓰면 코드가 매우 짧아지고 간결해지는 이점이 있으나
	//속도면에서는 느리고
	//또 한 번 호출될때마다 소량의 메모리가 쌓이는데
	//총 1.2메가 이상 쌓이면 터지는데 이걸 스택오버플로우라고 한다.
	//pathFinder(_currentTile);
}

void aStarTest::release()
{
}

void aStarTest::update()
{

	if (KEYMANAGER->isToggleKey(VK_TAB)) _start = false;
	else _start = true;


	if(KEYMANAGER->isOnceKeyDown(VK_SPACE))pathFinder(_currentTile);

	if (_start)
	{
		_count++;
		if (_count % 1 == 0)
		{
			pathFinder(_currentTile);
			_count = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vTotalList.size(); ++i)
		{
			RECT temp = _vTotalList[i]->getRect();
			if (PtInRect(&temp, _ptMouse))
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


}

void aStarTest::render()
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}
}
