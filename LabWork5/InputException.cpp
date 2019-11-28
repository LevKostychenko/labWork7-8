#include "pch.h"
#include "InputException.h"


InputException::InputException(const char* details, const char* curLang): Exception(details)
{
	this->Code = ConsoleInputException;
	int size = strlen(curLang) + 1;
	this->CurrentLang = new char[size];
	strcpy_s(this->CurrentLang, size, curLang);
}


InputException::~InputException()
{
	delete this->CurrentLang;
}
