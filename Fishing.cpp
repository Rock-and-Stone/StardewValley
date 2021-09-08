#include "pch.h"
#include "Fishing.h"

HRESULT Fishing::init()
{
	_fishFrame.image = IMAGEMANAGER->addImage("FishingFrame", "source/Images/mainScene/Fishing.bmp", 151, 597, true, MAGENTA);
	_icon.image = IMAGEMANAGER->addImage("FishIcon", "source/Images/mainScene/FishIcon.bmp", 36, 38, true, MAGENTA);
	_check.image = IMAGEMANAGER->addImage("Check", "source/Images/mainScene/Check.bmp", 36, 63, true, MAGENTA);
	_check.x = 870;
	_check.y = 540;
	_check.rc = RectMake(_check.x, _check.y, _check.image->getWidth(), _check.image->getHeight());
	_icon.x = 870;
	_icon.y = 540;
	_icon.rc = RectMake(_icon.x, _icon.y, _icon.image->getWidth(), _icon.image->getHeight());
	_fishFrame.x = 800;
	_fishFrame.y = 40;
	_isStart = true;
	_currentGauge = 0;
	_maxGauge = 100;
	progressbarInit(930, -240 , 17 , 576);
	setGauge(_currentGauge, _maxGauge);
	return S_OK;
}

void Fishing::release()
{
}

void Fishing::update()
{
	_rndCount++;
	
	if (_rndCount % 20 == 0)
	{
		_rndCountNum++;
		_isRandom = true;
	}
	if (_isRandom)
	{
		if (_rndCountNum % 2 == 0)
		{
			_isRandom = false;
			_rndSpeed = RND->getFromIntTo(-3, 3);
		}
	}
	else if (_icon.y > WINSIZEY || _icon.y < 0 )
	{
		_isRandom = false;
	}

	if (_icon.y >= 55 && _icon.y < 620)
	{
		_icon.y += _rndSpeed;
	}
	else if (_icon.y < 55 && _rndSpeed < 0)
	{
		_icon.y -= _rndSpeed;
	}
	


	if (KEYMANAGER->isStayKeyDown(VK_SPACE) && _check.rc.top > 105)
	{
		_isJump = true;
		_jumpPower = 4.0f;
		_gravity = 0.18f;
	}

	if (_isJump && _check.y <= 520)
	{
		_check.y -= _jumpPower;
		_jumpPower -= _gravity;
	}
	else if (_check.y > 520)
	{
		_check.y = 520;
		_isJump = false;
		_jumpPower = 0;
		_gravity = 0;
	}


	Collision();

	_check.rc = RectMake(_check.x, _check.y, _check.image->getWidth(), _check.image->getHeight());
	_icon.rc = RectMake(_icon.x, _icon.y, _icon.image->getWidth(), _icon.image->getHeight());

	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(),
		_progressBarTop->getHeight());
}

void Fishing::render()
{
	_fishFrame.image->render(getMemDC(), _fishFrame.x, _fishFrame.y);
	_check.image->render(getMemDC(), _check.x, _check.y);
	_icon.image->render(getMemDC(), _icon.x, _icon.y);
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _check.rc);
		Rectangle(getMemDC(), _icon.rc);
	}
	char str[256];
	sprintf_s(str, "%d %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), 50, 50, str, strlen(str));

	sprintf_s(str, "%d", _check.y);
	TextOut(getMemDC(), 50, 70, str, strlen(str));

	sprintf_s(str, "_rndSpeed %f", _rndSpeed);
	TextOut(getMemDC(), 50, 90, str, strlen(str));

	sprintf_s(str, "_rndCount %d", _rndCount);
	TextOut(getMemDC(), 50, 110, str, strlen(str));
	sprintf_s(str, "_rndCountNum %d", _rndCountNum);
	TextOut(getMemDC(), 50, 130, str, strlen(str));

	IMAGEMANAGER->render("backBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _height);
}

void Fishing::progressbarInit(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "source/Images/mainScene/frontBar.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "source/Images/mainScene/backBar.bmp", width, height, true, RGB(255, 0, 255));

	_height = _progressBarBottom->getHeight();
}

void Fishing::setGauge(float currentGauge, float maxGauge)
{
	_height = (currentGauge / maxGauge) * _progressBarBottom->getHeight();
}

void Fishing::Collision()
{
	RECT temp;
	if (IntersectRect(&temp, &_icon.rc, &_check.rc) && !_isCollide)
	{
		_isCollide = true;
		_currentGauge++;
	}
	else _isCollide = false;

	if (!_isCollide)
	{
		_currentGauge--;
	}
	setGauge(_currentGauge, _maxGauge);

	//게이지 다 차면
	if (_currentGauge == _maxGauge)
	{
		_currentGauge = 0;
	}
}

