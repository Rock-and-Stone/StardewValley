#include "pch.h"
#include "npcManager.h"
#include "marnie.h"
#include "wizard.h"
#include "player.h"
#include "CameraManager.h"
#include "homeMap.h"
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

	_marnie->init(70, 17);
	_wizard->init(70, 20);

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
	interact();
}
void npcManager::render()
{
	char str[25];
	sprintf_s(str, "%d , %d , %d", _dialogue,_marnie->getDialogueNum(), _wizard->getDialogueNum());

	TextOut(getMemDC(), WINSIZEX /2 , WINSIZEY /2 , str, strlen(str));

	if (_isDialogue)
	{
		GAMEDATA->setIsPause(true);

		  if(_dialogue == MARNIE) _marnie->dialogue();
		  if(_dialogue == WIZARD) _wizard->dialogue();
	}

}
void npcManager::interact()
{
	RECT rc, rc2, rc3, temp;

	rc = _wizard->getRenderRc();
	rc2 = _player->getIntRenderRc();
	rc3 = _marnie->getRenderRc();

	if (PtInRect(&rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		
		if (IntersectRect(&temp, &rc, &rc2))
		{
			_dialogue = WIZARD;
			_isDialogue = true;
		}
	}



	if (PtInRect(&rc3, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{

		if (IntersectRect(&temp, &rc3, &rc2))
		{
			_dialogue = MARNIE;
			_isDialogue = true;
		}
	}


	if (_marnie->getDialogueNum() <= 0)
	{
		_isDialogue = false;
		GAMEDATA->setIsPause(false);
		_marnie->setDialogueNum(4);
	}

	if (_wizard->getDialogueNum() <= 0)
	{
		_isDialogue = false;
		GAMEDATA->setIsPause(false);
		_wizard->setDialogueNum(4);
	}

}

