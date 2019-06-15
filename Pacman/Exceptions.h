#pragma once
#include <exception>
#include <string>
#include <winuser.h>

void ErrorMsg(std::string error, std::string title)
{
	MessageBoxA(NULL, error.c_str(), title.c_str(), MB_ICONERROR | MB_OK);
}


class NoTextureLoadedException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to load texture!";
	}
};

class FileOperationException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to process file operations!";
	}
};
