#include "pch.h"
#include "Map.h"

Map::Map()
{
}


Map::~Map()
{
}

HRESULT Map::init()
{

	IMAGEMANAGER->addFrameImage("FloorTiles", "Source/Sprite/TileSheet.bmp", 480, 128, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ObjectTiles", "Source/Sprite/ObjectSheet.bmp", 416, 576, SAMPLEOBJECTX, SAMPLEOBJECTY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SaveButton", "Source/Sprite/Save_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LoadButton", "Source/Sprite/Load_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DrawButton", "Source/Sprite/Draw_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ObjectButton", "Source/Sprite/Object_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EraseButton", "Source/Sprite/Erase_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LeftButton", "Source/Sprite/LeftArrow_Button.bmp", 44, 20, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RightButton", "Source/Sprite/RightArrow_Button.bmp", 44, 20, 2, 1, true, RGB(255, 0, 255));

	_buttonSave		= new button;
	_buttonLoad		= new button;
	_buttonDraw		= new button;
	_buttonObject	= new button;
	_buttonErase	= new button;
	_buttonLeft		= new button;
	_buttonRight	= new button;

	_posX = 0;
	_posY = 0;

	_buttonSave->init("SaveButton", WINSIZEX/2 + 75, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonLoad->init("LoadButton", WINSIZEX/2 + 155, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonDraw->init("DrawButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 260, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonObject->init("ObjectButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 180, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonErase->init("EraseButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonLeft->init("LeftButton", WINSIZEX / 2 + 250, WINSIZEY - 120, PointMake(1, 0), PointMake(0, 0), Button, this);
	_buttonRight->init("RightButton", WINSIZEX / 2 + 300, WINSIZEY - 120, PointMake(1, 0), PointMake(0, 0), Button, this);

	_isPicked = false;

	SetSample(CTRL_TERRAINDRAW, "FloorTiles");


	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			SetRect(&_tiles[i * TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].terrainFrameX = 3;
		_tiles[i].terrainFrameY = 0;
		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;
		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJ_NONE;
		_tiles[i].posX = _tiles[i].rc.left;
		_tiles[i].posY = _tiles[i].rc.top;
	}

	//load();

	return S_OK;
}

void Map::release()
{

}

void Map::update()
{
	_buttonSave->update();
	_buttonLoad->update();
	_buttonDraw->update();
	_buttonObject->update();
	_buttonErase->update();
	_buttonLeft->update();
	_buttonRight->update();

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if(!_isPicked)PickSample();
		DrawMap();
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) _isPicked = false;

	if (KEYMANAGER->isStayKeyDown('W')) _posY -= 5;
	if (KEYMANAGER->isStayKeyDown('S')) _posY += 5;
	if (KEYMANAGER->isStayKeyDown('A')) _posX -= 5;
	if (KEYMANAGER->isStayKeyDown('D')) _posX += 5;

	Movement();
}

void Map::render()
{
	//지형 그리기
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		IMAGEMANAGER->frameRender("FloorTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		//오브젝트 속성이 아니면 그리지마라 (지우개로 지울때 쓰려고)
		if (_tiles[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("ObjectTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].objFrameX, _tiles[i].objFrameY);
	}

	if (_ctrSelect == CTRL_TERRAINDRAW)IMAGEMANAGER->render("FloorTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("FloorTiles")->getWidth(), 0);

	else IMAGEMANAGER->render("ObjectTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("ObjectTiles")->getWidth(), 0);


	_buttonSave->render();
	_buttonLoad->render();
	_buttonDraw->render();
	_buttonObject->render();
	_buttonErase->render();
	_buttonLeft->render();
	_buttonRight->render();

}

void Map::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileMapSave.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

	CloseHandle(file);
}

void Map::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileMapSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	memset(_pos, 0, sizeof(int) * 2);

	//STEP 1
	//타일을 불러와서 해당 타일에 속성값을 부여한다
	//물 타일, 또는 오브젝트 등은 갈수없는 타일이다

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].terrain == TR_WATER) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK1) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCK3) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BLOCKS) _attribute[i] |= ATTR_UNMOVE;
	}

	CloseHandle(file);
}

void Map::Movement()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].rc = RectMake(_tiles[i].posX - _posX, _tiles[i].posY - _posY, TILESIZE, TILESIZE);
	}
}

void Map::SetSample(int select, string str)
{
	_ctrSelect = select;

	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findImage(str)->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findImage(str)->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}
}

void Map::PickSample()
{
	//타일셋에서 내가 어떤 타일을 클릭했다!
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			_currentTile.x = _sampleTile[i].terrainFrameX;
			_currentTile.y = _sampleTile[i].terrainFrameY;
			_isPicked = true;
			break;
		}
	}
}

void Map::DrawMap()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (PtInRect(&_tiles[i].rc, _ptMouse))
		{

			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_tiles[i].objFrameX = _currentTile.x;
				_tiles[i].objFrameY = _currentTile.y;

				_tiles[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].objFrameX = NULL;
				_tiles[i].objFrameY = NULL;
				_tiles[i].obj = OBJ_NONE;
			}

			InvalidateRect(_hWnd, NULL, false);
			break;
		}
	}

}

void Map::AutoDraw(tagTile* currentTile)
{
	int startX = currentTile->terrainFrameX - 1;
	int startY = currentTile->terrainFrameY - 1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			//_tiles[(startY * TILESIZEX) + startX + j + (i * TILESIZEX)].terrain = 
			
		}
	}
}

void Map::Button(void* obj)
{
	Map* map = (Map*)obj;

	if (map->_buttonSave->getBtnDir() == BUTTONDIRECTION_UP) map->save();
	if (map->_buttonLoad->getBtnDir() == BUTTONDIRECTION_UP) map->load();
	if (map->_buttonDraw->getBtnDir() == BUTTONDIRECTION_UP) map->SetSample(CTRL_TERRAINDRAW, "FloorTiles");
	if (map->_buttonObject->getBtnDir() == BUTTONDIRECTION_UP) map->SetSample(CTRL_OBJDRAW, "ObjectTiles");
	if (map->_buttonErase->getBtnDir() == BUTTONDIRECTION_UP) map->_ctrSelect = CTRL_ERASER;
}

TERRAIN Map::terrainSelect(int frameX, int frameY)
{
	if (frameX >= 0 && frameX < 4 && frameY == 0)
	{
		return TR_GRASS_0;
	}
	else if (frameX < 3 && frameY > 0)
	{
		return TR_DIRT;
	}
	else if (frameX > 2 && frameX < 6 && frameY > 0)
	{
		return TR_GRASS_1;
	}
	else if (frameX > 5 && frameX < 9 && frameY > 0)
	{
		return TR_DIRT_WET;
	}
	else if (frameX > 13 && frameY == 0)
	{
		return TR_WATER;
	}

	return TR_GRASS_0;
}

OBJECT Map::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0) return OBJ_TANK1;
	else if (frameX == 0 && frameY == 8) return OBJ_TANK2;
	else if (frameX == 0 && frameY == 1) return OBJ_BLOCK1;
	else if (frameX == 0 && frameY == 2) return OBJ_BLOCK3;
	else if (frameX == 15 && frameY == 3) return OBJ_BLOCKS;

	return OBJ_BLOCK1;
}
