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
#pragma region IMAGES

	IMAGEMANAGER->addImage("background", "source/Sprite/background.bmp", 2560, 2080, false, RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("FloorTiles", "source/Sprite/TileSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ObjectTiles", "source/Sprite/ObjectSheet.bmp", 416, 576, SAMPLEOBJECTX, SAMPLEOBJECTY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Tree", "source/Sprite/Tree.bmp", 288, 192, SAMPLETREEX, SAMPLETREEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("SaveButton", "source/Sprite/Save_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LoadButton", "source/Sprite/Load_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DrawButton", "source/Sprite/Draw_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ObjectButton", "source/Sprite/Object_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EraseButton", "source/Sprite/Erase_Button.bmp", 74, 116, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("LeftButton", "source/Sprite/LeftArrow_Button.bmp", 44, 20, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RightButton", "source/Sprite/RightArrow_Button.bmp", 44, 20, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DragButton", "source/Sprite/DragMode_Button.bmp", 48, 48, 2, 2, true, RGB(255, 0, 255));

#pragma endregion

	_buttonSave		= new button;
	_buttonLoad		= new button;
	_buttonDraw		= new button;
	_buttonObject	= new button;
	_buttonErase	= new button;
	_buttonLeft		= new button;
	_buttonRight	= new button;
	_buttonDragMode	= new button;

	_posX = 0;
	_posY = 0;

	_dragStartX, _dragStartY = 0;
	_ctrPage = 0;

	_buttonSave->init("SaveButton", WINSIZEX/2 + 75, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonLoad->init("LoadButton", WINSIZEX/2 + 155, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonDraw->init("DrawButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 260, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonObject->init("ObjectButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 180, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonErase->init("EraseButton", WINSIZEX/2 + 110, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
	_buttonLeft->init("LeftButton", WINSIZEX / 2 + 250, WINSIZEY - 120, PointMake(1, 0), PointMake(0, 0), Button, this);
	_buttonRight->init("RightButton", WINSIZEX / 2 + 300, WINSIZEY - 120, PointMake(1, 0), PointMake(0, 0), Button, this);
	_buttonDragMode->init("DragButton", WINSIZEX / 2 + 300, WINSIZEY - 90, PointMake(1, 0), PointMake(0, 0), Button, this);

	_background = IMAGEMANAGER->findImage("background");
	_isPicked = false;
	_isDragMode = false;
	
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
		_tiles[i].terrainFrameX = 0;
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
	_buttonDragMode->update();


	RectSensor();

	if(_isStart)
	_dragRC = RectMake(_dragStartX, _dragStartY, _ptMouse.x - _dragStartX, _ptMouse.y - _dragStartY);

	if (!_isDragMode)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)
			&& _buttonSave->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonLoad->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonDraw->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonObject->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonErase->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonDragMode->getBtnDir() != BUTTONDIRECTION_DOWN)
		{
			if (!_isPicked)PickSample();
			if (!_isSample && !_isDragMode)DrawMap();
		}
	}
	
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) 
			&& _buttonSave->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonLoad->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonDraw->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonObject->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonErase->getBtnDir() != BUTTONDIRECTION_DOWN
			&& _buttonDragMode->getBtnDir() != BUTTONDIRECTION_DOWN)
		{
			DragMap(true);
			if (!_isPicked)PickSample();
			if (!_isSample && !_isDragMode)DrawMap();
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_isPicked = false;
		_isStart = false;
		if(_isDragMode)DragMap(false);
	}

	if (KEYMANAGER->isStayKeyDown('W')) _posY -= 5;
	if (KEYMANAGER->isStayKeyDown('S')) _posY += 5;
	if (KEYMANAGER->isStayKeyDown('A')) _posX -= 5;
	if (KEYMANAGER->isStayKeyDown('D')) _posX += 5;

	Movement();
}

void Map::render()
{

	char str[128];
	int type = 0;
	int obj = 0;

	//지형 그리기
	SetBkMode(getMemDC(), TRANSPARENT);

	sprintf_s(str, "Cursor Tile NUM : NONE");

	_background->alphaRender(getMemDC(), -_posX,- _posY, 100);

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].rc.left > WINSIZEX || _tiles[i].rc.top > WINSIZEY) continue;
		if (_tiles[i].rc.left + 32 < 0 || _tiles[i].rc.top + 32 < 0) continue;
		IMAGEMANAGER->frameRender("FloorTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);

		if (PtInRect(&_tiles[i].rc, _ptMouse))
		{
			sprintf_s(str, "Cursor Tile NUM : %d", i);
			type = _tiles[i].terrain;
		}
	}

	TextOut(getMemDC(), 20, 20, str, strlen(str));

	switch (type)
	{
	case TR_GRASS:
		sprintf_s(str, "Cursor Tile TYPE : GRASS");
		break;
	case TR_DIRT:
		sprintf_s(str, "Cursor Tile TYPE : DIRT");
		break;
	case TR_DIRT_WET:
		sprintf_s(str, "Cursor Tile TYPE : DIRT_WET");
		break;
	case TR_WATER:
		sprintf_s(str, "Cursor Tile TYPE : WATER");
		break;
	case TR_WOOD:
		sprintf_s(str, "Cursor Tile TYPE : WOOD");
		break;
	case TR_NULL:
		sprintf_s(str, "Cursor Tile TYPE : NULL");
		break;
	}

	TextOut(getMemDC(), 20, 40, str, strlen(str));

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].rc.left > WINSIZEX || _tiles[i].rc.top > WINSIZEY) continue;
		if (_tiles[i].rc.left + 32 < 0 || _tiles[i].rc.top + 32 < 0) continue;
		//오브젝트 속성이 아니면 그리지마라 (지우개로 지울때 쓰려고)
		if (_tiles[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("Tree", getMemDC(),
			_tiles[i].rc.left-32, _tiles[i].rc.top - 160,
			_tiles[i].objFrameX, _tiles[i].objFrameY);

		if (PtInRect(&_tiles[i].rc, _ptMouse))
		{
			sprintf_s(str, "Cursor Object NUM : %d", i);
			obj = _tiles[i].obj;
		}
	}

	TextOut(getMemDC(), 20, 60, str, strlen(str));

	if (_ctrSelect == CTRL_TERRAINDRAW)IMAGEMANAGER->render("FloorTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("FloorTiles")->getWidth(), 0);

	else if (_ctrSelect == CTRL_OBJDRAW && _ctrPage == 0)IMAGEMANAGER->render("ObjectTiles", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("ObjectTiles")->getWidth(), 0);
	else if (_ctrSelect == CTRL_OBJDRAW && _ctrPage == 1)IMAGEMANAGER->render("Tree", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("Tree")->getWidth(), 0);


	_buttonSave->render();
	_buttonLoad->render();
	_buttonDraw->render();
	_buttonObject->render();
	_buttonErase->render();
	_buttonLeft->render();
	_buttonRight->render();




	switch (obj)
	{
	case OBJ_WALL:
		sprintf_s(str, "Cursor OBJECT TYPE : WALL");
		break;
	case OBJ_TREE:
		sprintf_s(str, "Cursor OBJECT TYPE : TREE");
		break;
	case OBJ_BUILD:
		sprintf_s(str, "Cursor OBJECT TYPE : BUILD");
		break;
	case OBJ_PROP:
		sprintf_s(str, "Cursor OBJECT TYPE : PROP");
		break;
	case OBJ_POND:
		sprintf_s(str, "Cursor OBJECT TYPE : POND");
		break;
	case OBJ_NONE:
		sprintf_s(str, "Cursor OBJECT TYPE : NONE");
		break;
	}

	TextOut(getMemDC(), 20, 90, str, strlen(str));


	_buttonDragMode->render(_isDragMode);

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 20, 20));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), hpen);
	if (_isDragMode) LineRectangle(getMemDC(), _dragRC);
	SelectObject(getMemDC(),oldPen);
	DeleteObject(hpen);

	if(_isDragMode)sprintf_s(str, "Drag Mode : True");
	else sprintf_s(str, "Drag Mode : false");
	
	TextOut(getMemDC(), 20, 110, str, strlen(str));
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
		if (_tiles[i].obj == OBJ_WALL) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_POND) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BUILD) _attribute[i] |= ATTR_UNMOVE;
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


void Map::DragMap(bool isDrag)
{
	if (isDrag == true)
	{
		_dragStartX = _ptMouse.x;
		_dragStartY = _ptMouse.y;
		_isStart = true;
	}
	
	else
	{
		RECT temp;
		for (int i = 0; i < TILEX * TILEY; ++i)
		{
			if (IntersectRect(&temp, &_tiles[i].rc, &_dragRC))
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
			}
		}
		_dragRC = RectMake(0,0,0,0);
	}
}


void Map::RectSensor()
{
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; ++i)
	{
		if (PtInRect(&_sampleTile[i].rcTile, _ptMouse))
		{
			_isSample = true;
			break;
		}

		else _isSample = false;
	}
}

void Map::SetSample(int select, string str)
{
	_ctrSelect = select;

	//char numX[128];
	//char numY[128];

	for (int i = 0; i < SAMPLETILEY; ++i)
	{
		for (int j = 0; j < SAMPLETILEX; ++j)
		{
			//sprintf_s(numX, "%d", j);
			//sprintf_s(numY, "%d", i);

			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;

			SetRect(&_sampleTile[i * SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findImage(str)->getWidth()) + j * TILESIZE,
				i * TILESIZE,
				(WINSIZEX - IMAGEMANAGER->findImage(str)->getWidth()) + j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);

			//if (i == 16 && j > 4 && j < 11)
			//{
			//	INIDATA->addData(numY, numX, "5");
			//	INIDATA->iniSave("OBJECT");
			//}

		}
	}
	
}

void Map::ChangeSample(int page)
{
	_ctrPage += page;
	if (_ctrPage < 0) _ctrPage = 0;
	else if (_ctrPage > 1) _ctrPage = 1;

	if (_ctrSelect == CTRL_TERRAINDRAW)
	{
		switch (_ctrPage)
		{
		case 0:  
			SetSample(CTRL_TERRAINDRAW, "FloorTiles");
			break;
		case 1:
			SetSample(CTRL_TERRAINDRAW, "FloorTiles");
			break;
		}
	}
	else if(_ctrSelect == CTRL_OBJDRAW)
	{
		switch (_ctrPage)
		{
		case 0:
			SetSample(CTRL_OBJDRAW, "ObjectTiles");
			break;
		case 1:
			SetSample(CTRL_OBJDRAW, "Tree");
			break;
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
	if (map->_buttonDragMode->getBtnDir() == BUTTONDIRECTION_UP) map->_isDragMode = !map->getDragMode();
	if (map->_buttonRight->getBtnDir() == BUTTONDIRECTION_UP) map->ChangeSample(1);
	if (map->_buttonLeft->getBtnDir() == BUTTONDIRECTION_UP) map->ChangeSample(-1);;

}

TERRAIN Map::terrainSelect(int frameX, int frameY)
{
	char strX[128];
	char strY[128];
	sprintf_s(strX, "%d", frameX);
	sprintf_s(strY, "%d", frameY);

	return (TERRAIN)INIDATA->loadDataInterger("TERRAIN", strY, strX);
}

OBJECT Map::objSelect(int frameX, int frameY)
{
	char strX[128];
	char strY[128];
	sprintf_s(strX, "%d", frameX);
	sprintf_s(strY, "%d", frameY);

	return (OBJECT)INIDATA->loadDataInterger("OBJECT", strY, strX);
}
