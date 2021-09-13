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
	
	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT + 32);

	_img = IMAGEMANAGER->findImage("marnie");

	_dialogueNum = 4;

	_count = _frameX = 0;

	_isArrive = false;

	_direction = STOP;

	return S_OK;
}

void marnie::release()
{
}

void marnie::update()
{
	
	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT + 32);

	_renderRc = RectMakeCenter(_x - _cameraManager->getCamX() + 16, _y - _cameraManager->getCamY() + 32, TILEWIDTH, TILEHEIGHT + 32);

	marnieMove();
}

void marnie::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _renderRc);
	}
}

void marnie::dialogue()
{

	
	IMAGEMANAGER->findImage("dialogueBox")->render(getMemDC(), WINSIZEX / 2 - 300, WINSIZEY - 250);

	char str[256];

	switch (_dialogueNum)
	{
	case 4:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue1", "marnie"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;
		break;
	case 3:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue2", "marnie"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;
		break;
	case 2:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue3", "marnie"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;
		break;
	case 1:
		shop();
		break;
	}

	

	TextOut(getMemDC(), WINSIZEX / 2 - 200, WINSIZEY - 200 , str, strlen(str));

}

void marnie::shop()
{


	RECT rc = RectMake(640 - 300 , WINSIZEY  /2, 640, 64);
	RECT rc2 = RectMake(640 - 300, WINSIZEY / 2 -64, 640,64);

	IMAGEMANAGER->findImage("shopBox")->render(getMemDC(), rc.left, rc.top);
	IMAGEMANAGER->findImage("shopBox")->render(getMemDC(), rc2.left, rc2.top);
	IMAGEMANAGER->findImage("craftItems")->frameRender(getMemDC(),rc.left + 10, rc.top+20, 2, 0);
	IMAGEMANAGER->findImage("craftItems")->frameRender(getMemDC(),rc.left + 10, rc.top-44, 3, 0);

	char str[48];
	sprintf_s(str, "일반 허수아비                       300");
	TextOut(getMemDC(), WINSIZEX / 2 - 70, WINSIZEY / 2 + 12, str, strlen(str));
	sprintf_s(str, "귀여운 고양이 허수아비               500");
	TextOut(getMemDC(), WINSIZEX / 2 - 70, WINSIZEY / 2 - 52, str, strlen(str));

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) )
	{
		if (PtInRect(&rc, _ptMouse)) 
		{
			_player->GetInventory()->AddItem(_player->GetInventory()->GetCrow1());
			_player->setGold(_player->getGold() - 300);
		}

		if (PtInRect(&rc2, _ptMouse))
		{
			_player->GetInventory()->AddItem(_player->GetInventory()->GetCrow2());
			_player->setGold(_player->getGold() - 500);
		}
	}

	if(KEYMANAGER->isOnceKeyDown('E')) _dialogueNum--;
}

void marnie::marnieMove()
{
	RECT rcCollision;	//가상의 충돌판정렉트를 하나 생성
	//가상의 판정렉트에 현재 렉트를 대입해주자
	rcCollision = _rc;

	float moveSpeed  = 2.0f;
	

	if (_count % 30 == 5) _frameX++;
	if (_frameX >= 5) _frameX = 0;

	switch (_direction)
	{
	case LEFT:
		_img->setFrameX(_frameX);
		_img->setFrameY(3);
		_count++;
		_x -= moveSpeed;
		rcCollision = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT + 32);

		break;
	case UP:
		_img->setFrameX(_frameX);
		_img->setFrameY(0);
		_count++;
		_y -= moveSpeed;

		rcCollision = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT + 32);

		break;
	case RIGHT:
		_img->setFrameX(_frameX);
		_img->setFrameY(2);
		_count++;

		_x += moveSpeed;

		rcCollision = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT + 32);

		break;
	case DOWN:

		_img->setFrameX(_frameX);
		_img->setFrameY(1);
		_y += moveSpeed;
		_count++;
		rcCollision = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT + 32);

		break;
	}

	if (_isArrive == true) _direction = STOP;
}

void marnie::setMarniePosition(tagTile* tile)
{
	if (_x < tile->rc.left) _direction = RIGHT;
	else if (_x > tile->rc.left) _direction = LEFT;
	else if (_y > tile->rc.top) _direction = UP;
	else if (_y < tile->rc.top) _direction = DOWN;

	if (_direction == RIGHT && _x >= tile->rc.left) _isArrive = true;
	if (_direction == LEFT && _x < tile->rc.left) _isArrive = true;
	if (_direction == UP && _y < tile->rc.top)   _isArrive = true;
	if (_direction == DOWN && _y >= tile->rc.top) _isArrive = true;
}