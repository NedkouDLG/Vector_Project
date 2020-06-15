#pragma once
#include<stdexcept>
class EqualPointException:public std::exception
{
private:
	std::string error_points;
public:
	EqualPointException(std::string);
	virtual const char* what()const throw();
};

