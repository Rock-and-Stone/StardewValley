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

RECT entity::getRenderRc()
{
	return RECT();
}

RECT entity::getIntRenderRc()
{
	return RECT();
}


RECT entity::getInterectiveRc()
{
	return RECT();
}

void entity::dialogue()
{
}

int entity::getGold()
{
	return 0;
}

void entity::setX(int x)
{
}

void entity::setY(int y)
{
}

void entity::GoldGet(int gold)
{
}

int entity::getPlayerTile()
{
	return 0;
}

inventory* entity::GetInventory()
{
	return nullptr;
}

void entity::SetPlayerObjectManagerMemoryLink(objectManager* om)
{
}

void entity::SetBoxInvenPlayer(boxInventory* bm)
{
}

void entity::SetBoxInventory(boxInventory* bm)
{
}


void entity::SetHomeMapMemoryLink(homeMap* hm)
{
}

void entity::setCameraMemoryLink(CameraManager* cm)
{
}

void entity::setObjectMemoryLink(objectManager* om)
{
}

int entity::getDialogueNum()
{
	return 0;
}

void entity::setDialogueNum(int num)
{
}

void entity::drawBoxIven()
{
}

void entity::openBox()
{
}

void entity::setPlayerAddressLink(entity* pl)
{
}

void entity::setGold(int gold)
{
}

void entity::setMarniePosition(tagTile* tile)
{
}

bool entity::getIsArrive()
{
	return false;
}

void entity::setIsArrive(bool isArrive)
{
}

int entity::getMarnieIndX()
{
	return 0;
}

int entity::getMarnieIndY()
{
	return 0;
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
