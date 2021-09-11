#include "pch.h"
#include "player.h"
#include "playerState.h"
#include "homeMap.h"
#include "CameraManager.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::init(int indX, int indY)
{
	
	_x = indX * TILEWIDTH + (TILEWIDTH / 2),
	_y = indY * TILEHEIGHT + (TILEHEIGHT / 2);

	_frameX = _frameY = 0;

	_leftWalk = new leftWalk;
	_rightWalk = new rightWalk;
	_upWalk = new upWalk;
	_downWalk = new downWalk;
	_playerAxe = new playerAxe;
	_playerCan = new playerCan;
	_playerHoe = new playerHoe;
	_playerPickAxe = new playerPickAxe;
	_playerRod = new playerRod;
	_playerSickle = new playerSickle;
	_playerSword = new playerSword;


	_leftWalk->setPlayer(this);
	_rightWalk->setPlayer(this);
	_upWalk->setPlayer(this);
	_downWalk->setPlayer(this);
	_playerAxe->setPlayer(this);
	_playerCan->setPlayer(this);
	_playerHoe->setPlayer(this);
	_playerPickAxe->setPlayer(this);
	_playerRod->setPlayer(this);
	_playerSickle->setPlayer(this);
	_playerSword->setPlayer(this);
	

	
	_gold = GAMEDATA->getGold();

	_inventory = new inventory;
	_inventory->init();
	_inventory->SetPlayerMemoryLink(this);
	
	_img = IMAGEMANAGER->findImage("player");

	_rc = RectMakeCenter(_x,_y,TILEWIDTH,TILEHEIGHT);
	_isLift = false;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_inventory->update();

	activate();


	//이동 상태 패턴
	if (KEYMANAGER->isStayKeyDown('W') && _direction != PLAYERDIRECTION_ACTIVATE)
	{
		if (!_isLift) { _upWalk->update(); }
		_direction = PLAYERDIRECTION_UP;
		move();
	}

	if (KEYMANAGER->isStayKeyDown('S') && _direction != PLAYERDIRECTION_ACTIVATE)
	{
		if (!_isLift) { _downWalk->update(); }
		_direction = PLAYERDIRECTION_DOWN;
		move();
	}

	if (KEYMANAGER->isStayKeyDown('A') && _direction != PLAYERDIRECTION_ACTIVATE)
	{
		if (!_isLift) { _leftWalk->update(); }
		_direction = PLAYERDIRECTION_LEFT;

		move();
	}

	if (KEYMANAGER->isStayKeyDown('D') && _direction != PLAYERDIRECTION_ACTIVATE )
	{
		if (!_isLift) { _rightWalk->update(); }
		_direction = PLAYERDIRECTION_RIGHT;
		move();
	}

	//움직임이 멈추면 가만히 있는 상태로
	if (KEYMANAGER->isOnceKeyUp('W') && _direction != PLAYERDIRECTION_ACTIVATE) _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('A') && _direction != PLAYERDIRECTION_ACTIVATE) _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('S') && _direction != PLAYERDIRECTION_ACTIVATE) _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('D') && _direction != PLAYERDIRECTION_ACTIVATE) _frameX = 0;

	_rc = RectMakeCenter(_x, _y ,TILEWIDTH, TILEHEIGHT);
	_renderRC = RectMakeCenter(_rendX, _rendY, TILEWIDTH, TILEWIDTH);

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && !_inventory->GetIsMenuOpen() && _direction != PLAYERDIRECTION_ACTIVATE  && _inventory->getPlayerTool() != PLAYERTOOL_NULL)
	{
		if (!_isLift)
		{
			_frameX = 0;
			changePlayerTool();
			_direction = PLAYERDIRECTION_ACTIVATE;
		}

		else if (_isLift)
		{

			switch (_inventory->getCraft())
			{
			case CRAFTBOX:
				_inventory->eraseSelectQuickNum();
				_homeMap->PlaceObject(OBJ_BOX, _tileIndex);
				break;
			case CRAFTFURNANCE:
				_inventory->eraseSelectQuickNum();
				_homeMap->PlaceObject(OBJ_FURNACE, _tileIndex);

				break;
			case CRAFTCROW1:
				_inventory->eraseSelectQuickNum();
				_homeMap->PlaceObject(OBJ_SCARECROW1, _tileIndex);
				break;
			case CRAFTCROW2:
				_inventory->eraseSelectQuickNum();
				_homeMap->PlaceObject(OBJ_SCARECROW2, _tileIndex);

				break;
			}
		}

	}

	liftItem();

}

void player::render()
{
	_img->frameRender(getMemDC(), _rendX - 48,  _rendY  - 84 , _frameX, _frameY);
	_inventory->drawOnThePlayer();

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _renderRC);
		Rectangle(getMemDC(), _intRenderRc);
	}

	char str[25];
	sprintf_s(str, "idx : % d", _idX);
	TextOut(getMemDC(), 300, 300, str, strlen(str));

	sprintf_s(str, "idy : %d", _idY);
	TextOut(getMemDC(), 300, 320, str, strlen(str));

	sprintf_s(str, "tileIdx : %d", _tileIndex);
	TextOut(getMemDC(), 300, 340, str, strlen(str));
}

void player::move()
{
	RECT rcCollision;

	float moveSpeed = 5;


	int tileIndex[2];
	int tileX, tileY;

	rcCollision = _rc;

	switch (_direction)
	{
	case PLAYERDIRECTION_LEFT:
		_x -= moveSpeed;
		_dir = 1;
		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;

	case PLAYERDIRECTION_DOWN:
		_y += moveSpeed;
		_dir = 3;
		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;

	case PLAYERDIRECTION_RIGHT:
		_dir = 0;
		_x += moveSpeed;
		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;

	case PLAYERDIRECTION_UP:
		_dir = 2;
		_y -= moveSpeed;
		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;
	}

	rcCollision.left += 5;
	rcCollision.top += 5;
	rcCollision.right -= 5;
	rcCollision.bottom -= 5;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;

	_idX = tileX;
	_idY = tileY;


	switch (_direction)
	{
	case PLAYERDIRECTION_LEFT:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = tileX + (tileY + 1) * TILEX;

		_tileIndex = tileIndex[0];
		_interectiveRc = _homeMap->getTile()[tileIndex[0]].rc;
		_intRenderRc   = RectMake(_interectiveRc.left - _cameraManager->getCamX(), _interectiveRc.top - _cameraManager->getCamY(), TILEWIDTH, TILEWIDTH);

		break;

	case PLAYERDIRECTION_UP:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = (tileX + 1) + tileY * TILEX;

		_tileIndex = tileIndex[0];
		_interectiveRc = _homeMap->getTile()[tileIndex[0]].rc;
		_intRenderRc = RectMake(_interectiveRc.left - _cameraManager->getCamX(), _interectiveRc.top - _cameraManager->getCamY(), TILEWIDTH, TILEWIDTH);

		break;

	case PLAYERDIRECTION_RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		_tileIndex = tileIndex[0];

		_interectiveRc = _homeMap->getTile()[tileIndex[0]].rc;
		_intRenderRc = RectMake(_interectiveRc.left - _cameraManager->getCamX(), _interectiveRc.top - _cameraManager->getCamY(), TILEWIDTH, TILEWIDTH);

		break;
	case PLAYERDIRECTION_DOWN:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		_tileIndex = tileIndex[0];

		_interectiveRc = _homeMap->getTile()[tileIndex[0]].rc;
	    _intRenderRc = RectMake(_interectiveRc.left - _cameraManager->getCamX(), _interectiveRc.top - _cameraManager->getCamY(), TILEWIDTH, TILEWIDTH);

		break;
	}

	for (int i = 0; i < 2; ++i)
	{
		RECT rc;

		if ((((_homeMap->getAttribute()[tileIndex[i]]) & ATTR_UNMOVE) == ATTR_UNMOVE) &&
			IntersectRect(&rc, &_homeMap->getTile()[tileIndex[i]].rc, &rcCollision))
		{
			switch (_direction)
			{
			case PLAYERDIRECTION_LEFT:
				_rc.left = _homeMap->getTile()[tileIndex[i]].rc.right;
				_rc.right = _rc.left;

				_x = (_rc.left + _rc.right) / 2 + 10;
				break;

			case PLAYERDIRECTION_UP:
				_rc.top = _homeMap->getTile()[tileIndex[i]].rc.bottom ;
				_rc.bottom = _rc.top;
				_y = (_rc.top + _rc.bottom) / 2 + 10;

				break;

			case PLAYERDIRECTION_RIGHT:
				_rc.right = _homeMap->getTile()[tileIndex[i]].rc.left;
				_rc.left = _rc.right;

				_x = (_rc.left + _rc.right) / 2 - 3;
				break;

			case PLAYERDIRECTION_DOWN:
				_rc.bottom = _homeMap->getTile()[tileIndex[i]].rc.top;
				_rc.top = _rc.bottom;
				_y = (_rc.top + _rc.bottom) / 2 -3;
				break;
			}

			return;
		}
	}

	_rc = rcCollision;

	_rc = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
}

//플레이어가 들고 있는 도구를 받아 상태 패턴을 실행하는 함수
void player::changePlayerTool()
{
	switch (_inventory->getPlayerTool())
	{
	case PLAYERTOOL_AXE:
		_playerAxe->update();
		break;

	case PLAYERTOOL_CAN:
		_playerCan->update();
		break;
	case PLAYERTOOL_HOE:
		_playerHoe->update();
		break;

	case PLAYERTOOL_PICKAXE:
		_playerPickAxe->update();
		break;

	case PLAYERTOOL_ROD:
		_playerRod->update();
		break;

	case PLAYERTOOL_SICKLE:
		_playerSickle->update();
		break;

	case PLAYERTOOL_SWORD:
		_playerSword->update();
		break;
	}
}

//플레이어의 행동 함수
void player::activate()
{
	if (_direction == PLAYERDIRECTION_ACTIVATE)
	{
		_count++;
		if (_count % 7 == 6)
		{
			_frameX++;
			_count = 0;
		}

		if (_frameX >= _maxFrameX)
		{
			_count = 0;
			_frameX = 0;
			_direction = PLAYERDIRECTION_IDLE;

			switch (_dir)
			{
			case 0:
				_frameY = 0;
				break;
			case 1:
				_frameY = 1;
				break;
			case 2:
				_frameY = 2;
				break;
			case 3:
				_frameY = 3;
				break;
			}
	
		}
	}
}

void player::InventoryDraw()
{
	_inventory->render();
}

void player::liftItem()
{
	if (_inventory->getPlayerTool() == PLAYERTOOL_ITEMS)
	{
		_isLift = true;

		switch (_dir)  // 0 오 1 왼 2 위 3아래
		{
		case 0:
			_frameY = 22;
			_maxFrameX = 4;
			break;
		case 1:
			_frameY = 21;
			_maxFrameX = 4;
			break;
		case 2:
			_frameY = 23;
			_maxFrameX = 5;

			break;
		case 3:
			_frameY = 20;
			_maxFrameX = 5;
			break;
		}


		if (KEYMANAGER->isStayKeyDown('W') || KEYMANAGER->isStayKeyDown('S') || KEYMANAGER->isStayKeyDown('A') || KEYMANAGER->isStayKeyDown('D')) _count++;

		if (_count % 10 == 5)
		{
			_frameX++;
		}

		if (_frameX > _maxFrameX)
		{
			_frameX = 0;
		}

	
			
	
	}

	else if(_direction != PLAYERDIRECTION_ACTIVATE)
	{
		_isLift = false;
	}
}