#pragma once
#include "singletonBase.h"

class gameData : public singletonBase<gameData>
{ 
private:
	int _BGMVolume;
	int _SFXVolume;

	int _playerHP = getPlayerSaveHP();
	int _playerSM = getPlayerSaveSM();
	int _gold = getSaveGold();

	float _playerPosX = 200;
	float _playerPosY = 800;

	bool _isPause = false;

public:
	float getBGMVolume();
	void setBGMVolume(float volume);

	float getSFXVolume();
	void setSFXVolume(float volume);

	int getPlayerSaveHP();
	void SavePlayerHP(int hp);

	int getPlayerSaveSM();
	void SavePlayerSM(int sm);

	int getSaveGold();
	void SaveGold(int gold);

	int getPlayerHP() { return _playerHP; }
	void setPlayerHP(int hp) { _playerHP = hp; }

	int getPlayerSM() { return _playerSM; }
	void setPlayerSM(int sm) { _playerSM = sm; }

	int getGold() { return _gold; }
	void setGold(int gold) { _gold = gold; }

	float getPlayerPosX() { return _playerPosX; }
	void setPlayerPosX(float x) { _playerPosX = x; }
	float getPlayerPosY() { return _playerPosY; }
	void setPlayerPosY(float y) { _playerPosY = y; }

	void SaveData(int hp, int sm, int gold) { SavePlayerHP(hp); SavePlayerSM(sm); SaveGold(gold); }

	bool getIsPause() { return _isPause; }
	void setIsPause(bool isPause) { _isPause = isPause; }
};

