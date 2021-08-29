#pragma once
#include "gameNode.h"

#define LOADINGMAX 300

class progressBar;

class loadingScene : public gameNode
{
private:
	progressBar* _loadingBar;
	image* _background;
	image* _loadingImg;

	int _frameX;
	int _count;

public:
	loadingScene();
	~loadingScene();

	int _currentCount;

	HRESULT init();
	void release();
	void update();
	void render();

};

static DWORD CALLBACK threadFunction(LPVOID lpParameter);
