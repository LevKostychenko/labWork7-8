#pragma once

#include <iostream>
#include <cstring>
#include "InputException.h"

class InputValidator
{
public:

	static bool IsInputCorrect(std::istream &in, char* buffer);
	static bool IsNumberInputCorrect(std::istream &in, int min, int max, int& buff);
};

