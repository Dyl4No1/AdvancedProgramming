#pragma once

#include <string>

enum class Type
{
	Beverage	= 0,
	MainCourse  = 1,
	Appetiser   = 2
};

class Item
{
public: // Members for this class
	
	int				calories;
	std::string		name;
	float			price;
	Type			type;


public: // Methods for this class


	/**
	* 
	*/
	virtual std::string ToString() { return ""; };

};
