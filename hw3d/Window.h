#pragma once
#include "ChiliWin.h"
#include "exception.h"
#include "KeyBoard.h"
class Window {
public:

	class WinException : public Exception {
	public:
		WinException(int line, const char* file, HRESULT Hr) noexcept;
		const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;
	private:
		HRESULT hr;
	};
private:
	class WindowClass {
	public:
		static const wchar_t* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
		
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const wchar_t* wndClassName = L"Engine Window3d";
		static WindowClass wndClass;
		HINSTANCE hInst;

	};
public:
	Window(int width, int height, const wchar_t* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	KeyBoard kbd;
private:
	int width;
	int height;
	HWND hWnd;
};

#define CHWND_EXCEPT(hr) Window::WinException(__LINE__, __FILE__, hr)
#define CHWND_LAST_EXCEPT() Window::WinException(__LINE__, __FILE__, GetLastError())