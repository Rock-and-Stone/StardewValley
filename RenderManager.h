#pragma once
#include "singletonBase.h"

#include <vector>


#define ARRSIZE 10


class entity;

class RenderManager :  public singletonBase<RenderManager>
{
private:

	typedef vector<entity*>					arrRender;
	typedef vector<entity*>::iterator		iterRender;

	int _arr[ARRSIZE] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 }; // 테스트용 배열

private:
	arrRender _vRender;
	iterRender _viRender;

public:
	RenderManager();
	~RenderManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void swap(entity** a, entity** b);
	void selectionSort();
	void addRender(entity* obj); // 다른 객체에서 자신을 렌더매니저에 등록시킬때 사용됨.
	void removeRender(int arrNum);
};

