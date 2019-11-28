#include "pch.h"
#include "Exception.h"


Exception::Exception(const char* details)
{
	int size = strlen(details) + 1;
	this->Description = new char[size];
	strcpy_s(this->Description, size, details);
}


Exception::~Exception()
{
	delete this->Description;
}
