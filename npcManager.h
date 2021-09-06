#pragma once
#include "gameNode.h"
#include "entity.h"

class CameraManager;

class npcManager : public gameNode
{
private:
	entity* _marnie;
	entity* _wizard;
	CameraManager* _cameraManager;

public:
	npcManager();
	~npcManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setCameraAddressLink(CameraManager* cm) { _cameraManager = cm; }
	void setMarnieCameraLink(CameraManager* cm) { _marnie->setCameraAddressLink(cm); }
	void setWizardCameraLink(CameraManager* cm) { _wizard->setCameraAddressLink(cm); }
};

