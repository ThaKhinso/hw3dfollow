#define	__WIN64
#include "Window.h"
#include "App.h"
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//	static WindowMessageMap mm;
//	OutputDebugStringA(mm(msg, lParam, wParam).c_str());
//	switch (msg)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(69);
//		break;
//	case WM_KEYDOWN:
//		if (wParam == 'F') {
//			SetWindowText(hWnd, L"နစ်ဂါမသား");
//		}
//		break;
//	case WM_KEYUP:
//		if (wParam == 'F') {
//			SetWindowText(hWnd, L"ပူစီ");
//		}
//		break;
//	/*case WM_CHAR:
//		{
//		static std::string title;
//		title.push_back(wParam);
//		SetWindowTextA(hWnd, title.c_str());
//		}*/
//	case WM_LBUTTONDOWN:
//	{
//		POINTS pt = MAKEPOINTS(lParam);
//		std::ostringstream oss;
//		oss << "(" << pt.x << "," << pt.y << ")";
//		SetWindowTextA(hWnd, oss.str().c_str());
//	}
//	}
//	return DefWindowProcW(hWnd, msg, wParam, lParam);
//};

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int nCmdShow
) {	
	try
	{
		return App{}.Go();
		
	}
	catch (const Window::WinException& e) {
		//OutputDebugStringA(e.what());
		//MessageBox(nullptr, L"win exception", L"this is a win exception", MB_OK | MB_ICONEXCLAMATION);
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL);
	}
	catch (const std::exception& e) {
		//OutputDebugStringA(e.what());
		MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL);
		
	}
	catch (...) {
		MessageBox(nullptr, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
	 
}