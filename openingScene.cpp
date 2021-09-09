#include "pch.h"
#include "openingScene.h"


HRESULT openingScene::init()
{
	_opening = MCIWndCreate(_hWnd, NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, "source/intro.wmv");
	MoveWindow(_opening, 0, 0, WINSIZEX, WINSIZEY, NULL);
	MCIWndPlay(_opening);

	SCENEMANAGER->SetVideoPlay(true);

	return S_OK;
}

void openingScene::release()
{
}

void openingScene::update()
{
	if (MCIWndGetLength(_opening) <= MCIWndGetPosition(_opening))
	{
		MCIWndDestroy(_opening);
		SCENEMANAGER->SetVideoPlay(false);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{

		if (SCENEMANAGER->GetVideoPlay())
		{
			MCIWndDestroy(_opening);
			SCENEMANAGER->SetVideoPlay(false);
			SCENEMANAGER->changeScene("loadingScene");

		}
	}
}

void openingScene::render()
{
	
}
