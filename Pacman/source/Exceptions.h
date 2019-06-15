#pragma once
#include <exception>

class NoTextureLoadedException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to load texture!";
	}
};

class NoFontLoadedException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to load font!";
	}
};

class FileOperationException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to process file operations!";
	}
};

class NoBackgroundPictureException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to load background texture!";
	}
};

class NoSoundLoadedException : public std::exception
{
public:
	virtual const char* what() noexcept {
		return "Unable to load soundsfiles!";
	}
};
