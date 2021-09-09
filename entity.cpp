#include "pch.h"
#include "entity.h"


int entity::getRenderPosY()
{
	return 0;
}

bool entity::getReleased()
{
	return false;
}

void entity::setMapAddressLink(homeMap* hm)
{
}

void entity::setCameraAddressLink(CameraManager* cm)
{
}

void entity::SetInventoryCameraMemoryLink(CameraManager* cm)
{
}

int entity::getX()
{
	return 0;
}

int entity::getY()
{
	return 0;
}

void entity::setRenderX(int rendX)
{
}

void entity::setRenderY(int rendY)
{
}

RECT entity::getRect()
{
	return RECT();
}

entity::entity()
{
}

entity::~entity()
{
}

HRESULT entity::init()
{
	return S_OK;
}

HRESULT entity::init(int camX, int camY)
{
	return S_OK;
}

void entity::release()
{
}

void entity::update()
{
}

void entity::render()
{
}

void entity::render(int x, int y)
{
}

void entity::InventoryDraw()
{
}
