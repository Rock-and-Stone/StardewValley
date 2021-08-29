#pragma once

class gameData
{
private:
	int _BGMVolume;
	int _SFXVolume;

	int _playerHP = getPlayerSaveHP();
	int _playerGP = getPlayerSaveGP();
	int _coin = getSaveCoin();

	float _playerPosX = 200;
	float _playerPosY = 800;

public:
	float getBGMVolume();
	void setBGMVolume(float volume);

	float getSFXVolume();
	void setSFXVolume(float volume);

	int getPlayerSaveHP();
	void SavePlayerHP(int hp);

	int getPlayerSaveGP();
	void SavePlayerGP(int gp);

	int getSaveCoin();
	void SaveCoin(int coin);

	int getPlayerHP() { return _playerHP; }
	void setPlayerHP(int hp) { _playerHP = hp; }

	int getPlayerGP() { return _playerGP; }
	void setPlayerGP(int gp) { _playerGP = gp; }

	int GetCoin() { return _coin; }
	void setCoin(int coin) { _coin = coin; }

	float getPlayerPosX() { return _playerPosX; }
	void setPlayerPosX(float x) { _playerPosX = x; }
	float getPlayerPosY() { return _playerPosY; }
	void setPlayerPosY(float y) { _playerPosY = y; }

	void SaveData(int hp, int gp, int coin) { SavePlayerHP(hp); SavePlayerGP(gp); SaveCoin(coin); }
};

