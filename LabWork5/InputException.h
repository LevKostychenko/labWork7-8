#pragma once
#include "Exception.h"

class InputException : public Exception
{
public:
	InputException(const char* details = "", const char* curLang = "");
	~InputException();

public: 
	char* CurrentLang;
	int InputCount;
};

