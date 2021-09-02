#include "pch.h"
#include "itemManager.h"

itemManager::itemManager()
{
}

itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
    _axe = new itemAxe;
    _pickAxe = new itemPickAxe;
    _axe->init();
    _pickAxe->init();

    return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
}
