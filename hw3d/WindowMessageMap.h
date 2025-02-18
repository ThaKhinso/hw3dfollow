#pragma once
#include <unordered_map>
#include <Windows.h>

#include <string>

class WindowMessageMap {
public:
	WindowMessageMap() noexcept;
	
	std::string operator()(DWORD msg, LPARAM lp, WPARAM wp) const noexcept;
private:
	std::unordered_map<DWORD, std::string>map;
};