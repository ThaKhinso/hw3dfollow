#pragma once
#include "Window.h"
#include "SoeTimer.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	SoeTimer timer;
};

