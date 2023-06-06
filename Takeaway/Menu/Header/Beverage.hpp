#pragma once

#include "Item.hpp"
#include "Util.hpp"

class Beverage : public Item
{
public: // Members for this class

	float abv;
	int volume;


public: // Methods for this class

	std::string ToString()
	{
		// Format the string and return it :)
		return sfmt("%s: £%.2f, %d cal (%dml, %.2f abv)", this->name.c_str(), this->price, this->calories, this->volume, this->abv);
	}

};