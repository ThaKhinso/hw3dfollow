#include "SoeTimer.h"

SoeTimer::SoeTimer()
{
	last = std::chrono::steady_clock::now();
}

float SoeTimer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> FrameTime = last - old;
	return FrameTime.count();
}

float SoeTimer::Peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now()-last).count();
}
