#pragma once

#include "Item.hpp"
#include "Util.hpp"

class Appetiser : public Item
{
public: // Members for this class

	bool shareable;
	bool twoForOne;


public: // Methods for this class

	std::string ToString()
	{
		// Append string for specials
		std::string append;

		// Add 2-4-1 if needed
		if (this->twoForOne) append += "(2-4-1)";

		// Add shareable if needed
		if (this->shareable) append += "(shareable)";

		// Format the string and return it :)
		return sfmt("%s: £%.2f, %d cal, %s", this->name.c_str(), this->price, this->calories, append.c_str());
	}

};
