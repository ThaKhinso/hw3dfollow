#include "exception.h"
#include <sstream>

Exception::Exception(int line, const char* file) noexcept
	:line(line), file(file)
{

}

const char* Exception::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << "\n"
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* Exception::GetType() const noexcept
{
	return "Nigger Exception";
}

int Exception::GetLine() const noexcept
{
	return line;
}

const std::string& Exception::GetFile() const noexcept
{
	return file;
	// TODO: insert return statement here
}

std::string Exception::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << "\n"
		<< "[Line] " << line;
	return oss.str();
}

