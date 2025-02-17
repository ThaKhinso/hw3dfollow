#include "SoeTimer.h"

SoeTimer::SoeTimer() noexcept
{
	last = std::chrono::steady_clock::now();
}

float SoeTimer::Mark() noexcept
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> FrameTime = last - old;
	return FrameTime.count();
}

float SoeTimer::Peek() const noexcept
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now()-last).count();
}
