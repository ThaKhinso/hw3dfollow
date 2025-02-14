#include "KeyBoard.h"

bool KeyBoard::KeyIsPressed(unsigned char keycode) const noexcept
{
    return keystates[keycode];
}

KeyBoard::Event KeyBoard::ReadKey() noexcept
{
	if (keyBuffer.size() > 0u)
	{
		KeyBoard::Event e = keyBuffer.front();
		keyBuffer.pop();
		return e;
	}
    return KeyBoard::Event();
}

bool KeyBoard::KeyIsEmpty() const noexcept
{
	return keyBuffer.empty();
}

void KeyBoard::FlushKey() noexcept
{
	keyBuffer = std::queue<Event>();
}

char KeyBoard::ReadChar() noexcept
{
	if (charBuffer.size() > 0u) {
		unsigned char charcode = charBuffer.front();
		charBuffer.pop();
		return charcode;
	}
	else 
	{
		return 0;
	}
}

bool KeyBoard::CharIsEmpty() const noexcept
{
	return charBuffer.empty();
}

void KeyBoard::FlushChar() noexcept
{
	charBuffer = std::queue<char>();
}

void KeyBoard::Flush() noexcept
{
	FlushKey();
	FlushChar();
}

void KeyBoard::EnableAutoRepeat() noexcept
{
	autoRepeatEnabled = true;
}

void KeyBoard::DisableAutoRepeat() noexcept
{
	autoRepeatEnabled = false;
}

bool KeyBoard::AutoRepeatIsEnabled() const noexcept
{
	return autoRepeatEnabled;
}

void KeyBoard::OnKeyPressed(unsigned char keycode) noexcept
{
	keystates[keycode] = true;
	keyBuffer.push(KeyBoard::Event(KeyBoard::Event::Type::Press, keycode));
	TrimBuffer(keyBuffer);
}

void KeyBoard::OnKeyReleased(unsigned char keycode) noexcept
{
	keystates[keycode] = true;
	keyBuffer.push(KeyBoard::Event(KeyBoard::Event::Type::Release, keycode));
	TrimBuffer(keyBuffer);
}

void KeyBoard::OnChar(char character) noexcept
{
	charBuffer.push(character);
	TrimBuffer(charBuffer);
}

void KeyBoard::ClearState() noexcept
{
	keystates.reset();
}




