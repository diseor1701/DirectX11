#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// 현재 시스템의 Performance Counter에 대한 발생 빈도(Frequency) 값을 얻는 함수
	// Queryperformance Counter 함수로 얻은 값을 발생 빈도로 나누면 
	// Counter 값을 초 단위 시간 값으로 사용할 수 있다. 
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU 클럭
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime > 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}