#include "pch.h"
#include "MouseSetting.h"

MouseSetting::MouseSetting()
{
}

MouseSetting::~MouseSetting()
{
}

HRESULT MouseSetting::init()
{
	_mouse = IMAGEMANAGER->addFrameImage("mouse", "source/images/mainScene/Cursor.bmp", 144, 96, 3, 2, true, MAGENTA);
	_frameX = 0;
	_frameY = 1;


	

	// X,Y 값 기준으로 마우스 이미지
	// 0,0 기본 갈색 마우스
	// 0,1 다이얼로그 마우스
	// 0,2 NPC 호감도 마우스
	// 1,0 가위 모양 마우스
	// 1,1 보 모양 마우스

	ShowCursor(false);
	return S_OK;
}

void MouseSetting::release()
{
}

void MouseSetting::update()
{
	//씬을 통해 마우스를 설정해줄 수 있음
	if (SCENEMANAGER->isCurrentScene("mainMenuScene"))
	{
		//ShowCursor(true);
	}

}

void MouseSetting::render()
{
	_mouse->frameRender(getMemDC(), _ptMouse.x, _ptMouse.y, _frameX, _frameY);
}
