#pragma once

#include "Item.hpp"
#include "Util.hpp"

class MainCourse : public Item
{
public: // Members for this class


public: // Methods for this class

	std::string ToString()
	{
		// Format the string and return it :)
		return sfmt("%s: £%.2f, %d cal", this->name.c_str(), this->price, this->calories);
	}

};
