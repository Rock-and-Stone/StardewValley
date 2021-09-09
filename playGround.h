#pragma once
#include "gameNode.h"
#include "loadingScene.h"
#include "playerScene.h"
#include "openingScene.h"
#include "loadingScene.h"
#include "mainMenuScene.h"
#include "inventory.h"
#include "Map.h"
#include "enemyTestScene.h"
#include "gameScene.h"




class playGround : public gameNode
{
private:
	POINT  _winSize;
	bool _isChange;
	
	   	

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void SetWindowSize(POINT size);
	void ChangeWindowSize();

	inline BOOL GetChange() { return _isChange; }
	inline void SetChange(bool change) { _isChange = change; }
	inline POINT GetWindowSize() { return _winSize; }
	
};

