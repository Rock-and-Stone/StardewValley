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
	AstarInit();
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	_image = IMAGEMANAGER->findImage(imageName);

	_posX = position.x;
	_posY = position.y;
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
	_enemyDirection = DOWN;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	_idX = _posX / TILEWIDTH;
	_idY = _posY / TILEHEIGHT;
}

void Enemy::render()
{
	Draw();
}

void Enemy::AstarInit()
{
	//노드 초기화
	_startNode = NULL;
	_endNode = NULL;
	_curNode = NULL;

	//전체노드 초기화
	for (int y = 0; y < TILEY; y++)
	{
		for (int x = 0; x < TILEX; x++)
		{
			//새로운 노드와 렉트위치 설정
			_totalNode[x][y] = new node(x, y);
			_totalNode[x][y]->rc = RectMake(x * 32, y * 32, 32, 32);
		}
	}

	//첫클릭이 짝수가 되게 하기 위해서 -1로 초기화
	_count = -1;
	//길 찾았냐?
	_isFind = false;

	//리스타트용
	_openList.clear();
	_closeList.clear();
	_finalList.clear();
}

void Enemy::StartSearchPlayer(int playerIdX, int playerIdY)
{
	if (_startNode && _endNode) return;

	_totalNode[_idY][_idX]->nodeState = NODE_START;
	_startNode = _totalNode[_idY][_idX];
	cout << "setStartNode" << endl;

	_totalNode[playerIdY][playerIdX]->nodeState = NODE_END;
	_endNode = _totalNode[playerIdY][playerIdX];
	cout << "setEndNode" << endl;
}

void Enemy::SearchPlayer(int playerIdX, int playerIdY)
{
	_openList.clear();
	_closeList.clear();
	_finalList.clear();

	_totalNode[_idY][_idX]->nodeState = NODE_START;
	_startNode = _totalNode[_idY][_idX];

	_totalNode[playerIdY][playerIdX]->nodeState = NODE_END;
	_endNode = _totalNode[playerIdY][playerIdX];
}

void Enemy::pathFinding()
{
	_openList.clear();
	_closeList.clear();
	_finalList.clear();

	//종료노드가 없는 경우 길찾기 못함
	if (!_endNode) return;
	cout << "startFind" << endl;

	_openList.push_back(_startNode);

	while (_openList.size() > 0)
	{
		_curNode = _openList[0];

		for (int i = 1; i < _openList.size(); i++)
		{
			if (_openList[i]->F <= _curNode->F && _openList[i]->H < _curNode->H)
			{
				_curNode = _openList[i];
			}
		}

		//클로즈 리스트에 넣어둔다
		for (int i = 0; i < _openList.size(); i++)
		{
			if (_curNode == _openList[i])
			{
				this->delOpenList(i);
				_closeList.push_back(_curNode);
			}
		}

		//현재노드가 마지막 노드와 같냐? (길찾았다)
		if (_curNode == _endNode)
		{
			node* endNode = _endNode;
			vector<node*> tempNode;
			//마지막 노드로부터 시작노드까지 부모노드를 벡터에 담는다
			while (endNode != _startNode)
			{
				tempNode.push_back(endNode);
				endNode = endNode->parentNode;
			}

			for (int i = tempNode.size() - 1; i > 0; i--)
			{
				_finalList.push_back(tempNode[i]);
			}

			_isFind = true;
			_isMove = true;
			//종료하고 빠져 나온다
			return;
		}

		//상하좌우 (순서는 상관없음 - 어짜피 주변 4개의 노드를 모두 오픈리스트에 담아서 검사할 예정임)
		addOpenList(_curNode->idX, _curNode->idY - 1);	//상
		addOpenList(_curNode->idX, _curNode->idY + 1);	//하
		addOpenList(_curNode->idX - 1, _curNode->idY);	//좌
		addOpenList(_curNode->idX + 1, _curNode->idY);	//우

		//추후에 대각 4방향도 추가하면 대각선 이동 처리도 가능함
		//우상, 좌상, 우하, 좌하
		//예외처리만 잘해주면 된다
		//벽사이로 막가 안되도록 처리한다
	}
}

void Enemy::addOpenList(int idx, int idy)
{
	//예외처리 인덱스 범위안에서 추가할 수 있어야 한다
	if (idx < 0 || idx >= TILEX || idy < 0 || idy >= TILEX) return;

	//벽은 오픈리스트에 담을 수 없다
	if (_totalNode[idx][idy]->nodeState == NODE_WALL) return;

	//클로즈리스트(지나온길)에 있다면 오픈리스트에 담으면 안된다
	for (int i = 0; i < _closeList.size(); i++)
	{
		if (_totalNode[idx][idy] == _closeList[i]) return;
	}

	//여기까지 왔으면 문제가 없으니 이제 오픈리스트에 추가를 하자
	//현재노드의 4방향 노드를 이웃노드라고 하고 직선10, 대각은 14비용을 추가한다
	node* neighborNode = _totalNode[idx][idy];
	int moveCost = _curNode->G + ((_curNode->idX - idx == 0 || _curNode->idY - idy == 0) ? 10 : 14);

	//오픈리스트안에 이웃노드가 있으면 안된다
	for (int i = 0; i < _openList.size(); i++)
	{
		if (_openList[i] == neighborNode) return;
	}

	//마지막으로 오픈리스트에도 없는경우
	//G, H, ParentNode 설정후 오픈리스트에 추가
	//F = G + H
	//G = 시작에서 현재
	//H = 현재에서 종료
	neighborNode->G = moveCost;
	neighborNode->H = (abs(neighborNode->idX - _endNode->idX) + abs(neighborNode->idY - _endNode->idY)) * 10;
	neighborNode->F = neighborNode->G + neighborNode->H;
	neighborNode->parentNode = _curNode;
	_openList.push_back(neighborNode);
}

void Enemy::delOpenList(int index)
{
	_openList.erase(_openList.begin() + index);
}

void Enemy::setNodeColor(node* node, COLORREF color)
{
	/*HBRUSH brush = CreateSolidBrush(color);
	FillRect(getMemDC(), &node->rc, brush);
	DeleteObject(brush);
	FrameRect(getMemDC(), node->rc, RGB(0, 0, 0));*/
}

void Enemy::Move()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_enemyDirection = DOWN;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_enemyDirection = RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_enemyDirection = UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_enemyDirection = LEFT;
	}
}

void Enemy::Draw()
{
	if (_isFind)
	{
		for (int i = 0; i < _finalList.size(); i++)
		{
			setNodeColor(_finalList[i], RGB(255, 255, 0));
		}
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
	}
#pragma endregion

	_image->frameRender(getMemDC(), _posX, _posY, _frameX, _frameY);
}

void Enemy::Collision()
{
}
