#pragma once
#include "gameNode.h"
#include "entity.h"

class CameraManager;
class entity;

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
	void setPlayerMemAddressLink(entity* pl) { _player = pl; }
};

