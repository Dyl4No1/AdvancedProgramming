#pragma once


#include "Item.hpp"
#include <vector>
#include <string>

class ItemList
{
public: // Members for this class

	std::vector<Item*> items;


public: // Methods for this class

	virtual std::string toString() { return ""; }

};
