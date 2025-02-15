#pragma once
#include <chrono>

class SoeTimer
{
public:
	SoeTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

