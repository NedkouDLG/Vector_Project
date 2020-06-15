#pragma once
#include<stdexcept>
class VectorLengthException :public std::exception
{
public:
	VectorLengthException();
	virtual const char* what()const throw();
};

