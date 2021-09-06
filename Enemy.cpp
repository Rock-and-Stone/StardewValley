#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
	
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	

	_image = IMAGEMANAGER->findImage(imageName);
	_count = _start = _i = 0;
	_posX = position.x;
	_posY = position.y;
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
	
	_enemyDirection = STOP;
	_speed = 5.0f;	
	setTiles();
	_vGoList.push_back(_endTile);
	_isFind = false;
	_isCheck = false;

	
	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{

}

void Enemy::render()
{
	
}

void Enemy::setTiles()
{
	_startTile = new tile;
	_startTile->init(_idX, _idY);
	_startTile->setAttribute("start");

	_endTile = new tile;
	_endTile->init(20, 20);
	_endTile->setAttribute("end");

	//현재 타일은 시작타일로 둔다
	_currentTile = _startTile;

	for (int i = 0; i < 22; ++i)
	{
		for (int j = 0; j < 40; ++j)
		{
			if (j == _startTile->getIdX() && i == _startTile->getIdY())
			{
				_startTile->setColor(RGB(0, 255, 255));
				_vTotalList.push_back(_startTile);
				continue;
			}
			if (j == _endTile->getIdX() && i == _endTile->getIdY())
			{
				_endTile->setColor(RGB(10, 120, 55));
				_vTotalList.push_back(_endTile);
				continue;
			}

			tile* node = new tile;

			node->init(j, i);

			_vTotalList.push_back(node);
		}
	}
}

vector<tile*> Enemy::addOpenList(tile* currentTile)
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

			tile* node = _vTotalList[(startY * 40) + startX + j + (i * 40)];

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

void Enemy::pathFinder(tile* currentTile)
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
		_isFind = true;

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
	pathFinder(_currentTile);
}

void Enemy::setEnemyPosition(tile* tile)
{
	tile->setColor(RGB(0, 0, 0));

	if (_idX < tile->getIdX()) _enemyDirection = RIGHT;
	else if (_idX > tile->getIdX()) _enemyDirection = LEFT;
	else if (_idY > tile->getIdY()) _enemyDirection = UP;
	else if (_idY < tile->getIdY()) _enemyDirection = DOWN;

	if (_enemyDirection == RIGHT && _idX >= tile->getIdX()) _isArrive = true;
	if (_enemyDirection == LEFT && _idX < tile->getIdX()) _isArrive = true;
	if (_enemyDirection == UP && _idY < tile->getIdY())   _isArrive = true;
	if (_enemyDirection == DOWN && _idY >= tile->getIdY()) _isArrive = true;
}

void Enemy::Move()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _posX += _speed;
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_start = true;
	}

	if (_start)
	{
		pathFinder(_currentTile);

		if (_i >= _vGoList.size())
		{
			_isFind = false;
		}

		if (_idX == _endTile->getIdX() && _idY == _endTile->getIdY()) _enemyDirection = STOP;
	}

	if (_isFind)
	{
		setEnemyPosition(_vGoList[_vGoList.size() - 1 - _i]);

		if (_isArrive && !_isCheck)
		{
			_isCheck = true;

			SetIsArrive(false);

			_i++;
		}

		else if (!GetIsArrive()) _isCheck = false;
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
	//여기가 제일 중요한 부분이지 싶슴다
	RECT rcCollision;	//가상의 충돌판정렉트를 하나 생성

	int tileIndex[2];	//타일 검출에 필요한 인덱스
	int tileX, tileY;	//플레이어가 밟고 있는 타일의 인덱스

	//가상의 판정렉트에 현재 렉트를 대입해주자
	rcCollision = _rc;

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * _speed;

	switch (_enemyDirection)
	{
	case LEFT:
		_posX -= moveSpeed;
		break;
	case UP:
		_posY -= moveSpeed;
		break;
	case RIGHT:
		_posX += moveSpeed;
		break;
	case DOWN:
		_posY += moveSpeed;
		break;
	case STOP:
		_posX += 0;
		_posY += 0;
		break;
	}
	rcCollision = RectMakeCenter(_posX, _posY, _image->getFrameWidth(), _image->getFrameHeight());
	//STEP3
	//가상의 판정렉트를 사알짝 깍아주자
	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	//STEP4
	//가장 메인이 아닐까 싶으요
	tileX = rcCollision.left / TILESIZE;
	tileY = rcCollision.top / TILESIZE;

	_idX = tileX;
	_idY = tileY;

	switch (_enemyDirection)
	{

	case LEFT:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case UP:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = (tileX + 1) + tileY * TILEX;
		break;
	case RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		break;
	case DOWN:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	}

	_rc = rcCollision;

	_rc = RectMakeCenter(_posX, _posY, _image->getFrameWidth(), _image->getFrameHeight());
}

void Enemy::Draw()
{
	for (int i = 0; i < _vTotalList.size(); ++i)
	{
		_vTotalList[i]->render();
	}

#pragma region Frame
	_frameCount++;
	_image->setFrameX(_frameX);
	_image->setFrameY(_frameY);

	switch (_enemyDirection)
	{
	case DOWN:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case RIGHT:
		_frameY = 1;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case UP:
		_frameY = 2;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case LEFT:
		_frameY = 3;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	case STOP:
		_frameY = 0;
		if (_frameCount % 10 == 0)
		{
			_frameX++;
			if (_frameX >= _image->getMaxFrameX()) _frameX = 0;
		}
		break;
	}
#pragma endregion

	_image->frameRender(getMemDC(), _posX, _posY, _frameX, _frameY);
}

void Enemy::Collision()
{
}
