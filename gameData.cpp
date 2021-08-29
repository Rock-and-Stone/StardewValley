#include "pch.h"
#include "gameData.h"

float gameData::getBGMVolume()
{
	int BGMVolume;
	BGMVolume = INIDATA->loadDataInterger("gameData", "BGM", "volume");
	return BGMVolume;
}

void gameData::setBGMVolume(float volume)
{
	char str[30];
	_BGMVolume = volume;
	sprintf_s(str, "%d", _BGMVolume);
	INIDATA->addData("BGM", "volume", str);
	INIDATA->iniSave("gameData");
}

float gameData::getSFXVolume()
{
	int SFXVolume;
	SFXVolume = INIDATA->loadDataInterger("gameData", "SFX", "volume");
	return SFXVolume;
}

void gameData::setSFXVolume(float volume)
{
	char str[30];
	_SFXVolume = volume;
	sprintf_s(str, "%d", _SFXVolume);
	INIDATA->addData("SFX", "volume", str);
	INIDATA->iniSave("gameData");
}

int gameData::getPlayerSaveHP()
{
	int hp;
	hp = INIDATA->loadDataInterger("gameData", "player", "hp");
	return hp;
}

void gameData::SavePlayerHP(int hp)
{
	char str[30];
	_playerHP = hp;
	sprintf_s(str, "%d", _playerHP);
	INIDATA->addData("player", "hp", str);
	INIDATA->iniSave("gameData");
}

int gameData::getPlayerSaveGP()
{
	int gp;
	gp = INIDATA->loadDataInterger("gameData", "player", "gp");
	return gp;
}

void gameData::SavePlayerGP(int gp)
{
	char str[30];
	_playerGP = gp;
	sprintf_s(str, "%d", _playerGP);
	INIDATA->addData("player", "gp", str);
	INIDATA->iniSave("gameData");
}

int gameData::getSaveCoin()
{
	int coin;
	coin = INIDATA->loadDataInterger("gameData", "player", "coin");
	return coin;
}

void gameData::SaveCoin(int coin)
{
	char str[30];
	_coin = coin;
	sprintf_s(str, "%d", _coin);
	INIDATA->addData("player", "coin", str);
	INIDATA->iniSave("gameData");
}

