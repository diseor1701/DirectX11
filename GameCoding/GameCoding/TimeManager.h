#pragma once


class TimeManager
{
public:
	void Init();
	void Update();

	// 몇 프레임으로 실행되고있는지
	uint32 GetFps() { return _fps; }

	// 매 프레임마다 얼마만큼의 시간이 경과되었는지 리턴
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64	_frequency = 0;
	uint64	_prevCount = 0;
	float	_deltaTime = 0.f;

private:
	uint32	_frameCount = 0;
	float	_frameTime = 0.f;
	uint32	_fps = 0;
};

