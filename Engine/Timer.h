#pragma once


class Timer
{
public:
	void Init();
	void Update();

	uint32 GetFps() { return _fps; }
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64	_frequency = 0;
	uint64	_prevCount = 0;
	float	_deltaTime = 0.f;

private:
	// 프레임을 계산하기 위한 용도
	uint32	_frameCount = 0;
	float	_frameTime = 0.f;
	uint32	_fps = 0; // 1초마다 갱신된 값을
};

