#pragma once

class player;

class playerState
{
private:
public:
	playerState();
	~playerState();

	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;
	virtual void setPlayer(player* player) = 0;
};

class leftWalk : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	leftWalk();
	~leftWalk();

	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	void setFrameY();
	virtual void setPlayer(player* player) override { _player = player; }
};

class rightWalk : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;


public:
	rightWalk();
	~rightWalk();

	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class upWalk : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;


public:
	upWalk();
	~upWalk();

	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class downWalk : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;


public:
	downWalk();
	~downWalk();

	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerSword : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerSword();
	~playerSword();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerHoe : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerHoe();
	~playerHoe();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerAxe : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerAxe();
	~playerAxe();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerCan : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerCan();
	~playerCan();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerPickAxe : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerPickAxe();
	~playerPickAxe();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerRod : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerRod();
	~playerRod();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};

class playerSickle : public playerState
{
private:
	player* _player;
	int _frameX, _frameY, _count;
public:
	playerSickle();
	~playerSickle();
	virtual HRESULT init() override;
	virtual void release()override;
	virtual void update() override;
	virtual void render(HDC hdc) override;
	virtual void setPlayer(player* player) override { _player = player; }
};