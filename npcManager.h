#pragma once
#include "gameNode.h"
#include "entity.h"
#include <vector>
#include "tileNode.h"

class CameraManager;
class entity;
class homeMap;
#define TILEWIDTH 32
#define TILEHEIGHT 32

enum DIALOGUE
{
	MARNIE,
	WIZARD
};

class npcManager : public gameNode
{
private:
	entity* _marnie;
	entity* _wizard;
	entity* _player;

	CameraManager* _cameraManager;
	homeMap* _homeMap;

	DIALOGUE _dialogue;
	bool _isDialogue;

public:
	npcManager();
	~npcManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void interact();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	void setMarnieCameraLink(CameraManager* cm) { _marnie->setCameraAddressLink(cm); }
	void setWizardCameraLink(CameraManager* cm) { _wizard->setCameraAddressLink(cm); }
	void setNPCPlayerLink(entity* pl) { _marnie->setPlayerAddressLink(pl); _wizard->setPlayerAddressLink(pl); }
	void setPlayerMemAddressLink(entity* pl) { _player = pl; }
	void setHomeMapMemAddressLink(homeMap* hm) { _homeMap = hm; }
};

