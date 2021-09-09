#include "pch.h"
#include "npcManager.h"
#include "marnie.h"
#include "wizard.h"
#include "player.h"
#include "CameraManager.h"

npcManager::npcManager()
{
}

npcManager::~npcManager()
{
}

HRESULT npcManager::init()
{
	_marnie = new marnie;
	_wizard = new wizard;

	_marnie->init(10, 10);
	_wizard->init(10, 20);

	RENDERMANAGER->addRender(_marnie);
	RENDERMANAGER->addRender(_wizard);

	return S_OK;
}

void npcManager::release()
{
}

void npcManager::update()
{
	_wizard->update();
	_marnie->update();

	dialogue();


}

void npcManager::render()
{
	char str[25];
	sprintf_s(str, "%d, %d,%d", _marnie->getRenderPosY(), _wizard->getRenderPosY(), _player->getRenderPosY());
	TextOut(getMemDC(), WINSIZEX /2 , WINSIZEY /2 , str, strlen(str));
}

void npcManager::dialogue()
{
	RECT rc, rc2, temp;

	rc = _wizard->getRenderRc();
	rc2 = _player->getIntRenderRc();

	if (PtInRect(&rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (IntersectRect(&temp, &rc, &rc2))
		{
			///위자드 다이얼로그 발생
		}
	}

	rc = _marnie->getRenderRc();

	if (PtInRect(&rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (IntersectRect(&temp, &rc, &rc2))
		{
			///위자드 다이얼로그 발생
		}
	}
}