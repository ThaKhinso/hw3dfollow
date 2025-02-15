#include "App.h"
#include <sstream>
App::App()
	:wnd(800,600,L"Nigger")
{
}

int App::Go()
{
	MSG msg;
	BOOLEAN gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		/*static int i = 0;
		while (!wnd.mouse.IsEmpty()) {
			const auto e = wnd.mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::WheelUp:
				i++;
				{
					std::ostringstream oss;
					oss << "Up: " << i;
					wnd.SetTitle(oss.str());
				}
				break;
			case Mouse::Event::Type::WheelDown:
				i--;
				{
					std::ostringstream oss;
					oss << "Down: " << i;
					wnd.SetTitle(oss.str());
				}
				break;
			}
		}*/
		DoFrame();
	}
	if (gResult == -1) {
		CHWND_LAST_EXCEPT();
	}
	return msg.wParam;
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed" << "\n";
	wnd.SetTitle(oss.str());
}