#include "EqualPointException.h"

EqualPointException::EqualPointException(std::string error_points)
{
	this->error_points = error_points;
}

const char* EqualPointException::what() const throw()
{
	std::string temp = " are equal points!";
	std::string result;
	result = error_points + temp;
	char* res = new char[strlen(result.c_str())+1];
	strcpy_s(res, strlen(result.c_str()) + 1, result.c_str());
	return res;
}
