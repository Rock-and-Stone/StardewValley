#include "pch.h"
#include "RenderManager.h"
#include "entity.h"

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

HRESULT RenderManager::init()
{
	return S_OK;
}

void RenderManager::release()
{
	_vRender.clear();
}

void RenderManager::update()
{
	selectionSort();

	for (int i = 0; i < _vRender.size(); i++)
	{
		if (_vRender[i]->getReleased()) removeRender(i);
	}
}

void RenderManager::render(HDC hdc)
{
	char str[128];
	int i = 0;

	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
	{
		(*_viRender)->render();
	}
}


void RenderManager::selectionSort()
{
	int minIndex;
	int i, j;

	for (i = 0; i < _vRender.size() - 1; i++)
	{
		minIndex = i;
		for (j = i+1; j < _vRender.size(); j++)
			if (_vRender[j]->getRenderPosY() < _vRender[minIndex]->getRenderPosY()) //렌더의 Y값을 가져와서 비교하여 스왑.
				minIndex = j;
		swap(&_vRender[i], &_vRender[minIndex]);
	}
}

void RenderManager::addRender(entity* obj)
{
	_vRender.push_back(obj);
}

void RenderManager::removeRender(int arrNum)
{
	_vRender.erase(_vRender.begin() + arrNum);
}

void RenderManager::swap(entity** a, entity** b)
{
	entity* temp = *a;
	*a = *b;
	*b = temp;
}
