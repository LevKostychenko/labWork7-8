#pragma once
#include <stdio.h>
#include <cstring>
#include "ExceptionsCode.h"
#include <exception>

class Exception : public std::exception
{
public:
	Exception(const char* details = "");
	virtual ~Exception();

public:
	double Code;
	char* Description;
};

