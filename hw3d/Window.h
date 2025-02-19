#pragma once
#include <optional>
#include <memory>
#include "ChiliWin.h"
#include "exception.h"
#include "KeyBoard.h"
#include "Mouse.h"
#include "Graphics.h"

class Window {
public:

	class WinException : public Exception {
		using Exception::Exception;
	public:
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
	};
	class HrException : public WinException {
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;

		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public WinException {
	public:
		using WinException::WinException;
		const char* GetType() const noexcept override;
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
	void SetTitle(const std::string& title);
	static std::optional<int> ProcessMessages() noexcept;
	Graphics& Gfx();
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	KeyBoard kbd;
	Mouse mouse;
	
private:
	int width;
	int height;
	HWND hWnd;
	std::unique_ptr<Graphics> pGfx;
};

#define CHWND_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define CHWND_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define CHWND_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )