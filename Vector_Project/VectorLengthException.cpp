#include "VectorLengthException.h"

VectorLengthException::VectorLengthException()
{
}

const char* VectorLengthException::what() const throw()
{
	std::string temp = "The vector length is zero!";
	char* res = new char[strlen(temp.c_str()) + 1];
	strcpy_s(res, strlen(temp.c_str()) + 1, temp.c_str());
	return res;
}
