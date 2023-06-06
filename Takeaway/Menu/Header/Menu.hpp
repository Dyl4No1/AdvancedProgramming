#pragma once


#include "ItemList.hpp"
#include <fstream>
#include <string>
#include <sstream>

// Types used in this file
#include "Appetiser.hpp"
#include "Beverage.hpp"
#include "MainCourse.hpp"
#include "Util.hpp"

class Menu : public ItemList
{
public: // Members for this class

	Menu(const char* path);

public: // Methods for this class

	std::string ToString();

};


// Implementation for Menu constructor
Menu::Menu(const char* path)
{
	// Create a stream object for the file
	std::ifstream file;

	// Open the given file
	file.open(path);

	// Check that the fstream is open
	if (!file.is_open()) return;

	// Will store the current line being read
	std::string line;

	// Loop and read the file
	while (std::getline(file, line))
	{
		// Open a stringstream for the line.
		std::stringstream ss_line(line);

		// Will store the data for the current item
		std::vector<std::string> data;

		// Loop while it is good
		for (int i = 0; i < 8; i++)
		{
			// Will store the current data
			std::string substr;

			// Get the current comma-delimited item
			getline(ss_line, substr, ',');


			// Convert 'y' and 'n' to '1' and '0'
			if		(substr == "y") substr = "1";
			else if (substr == "n") substr = "0";
			else if (substr == "")	substr = "0";

			// Store the data
			data.push_back(substr);
		}

		// Check for appetiser
		if (data[0] == "a")
		{
			// Convert item to an appetiser
			Appetiser* ap = new Appetiser;

			// Store data for the appetiser
			ap->price = std::stof(data[2]);
			ap->name = data[1];
			ap->calories = std::stoi(data[3]);
			ap->shareable = std::stoi(data[4]);
			ap->twoForOne = std::stoi(data[5]);
			ap->type = Type::Appetiser;

			// Store the item in the list
			this->items.push_back(ap);

		}

		// Check for beverage
		else if (data[0] == "b")
		{
			// Convert item to a beverage
			Beverage* bev = new Beverage;

			// Store data for the beverage
			bev->price = std::stof(data[2]);
			bev->name = data[1];
			bev->calories = std::stoi(data[3]);
			bev->volume = std::stoi(data[6]);
			bev->abv	= std::stof(data[7]);
			bev->type	= Type::Beverage;

			// Store the item in the list
			this->items.push_back(bev);
		}

		// Check for Main course
		else
		{
			// Convert item to a main course
			MainCourse* mc = new MainCourse;

			// Store the item type
			mc->price = std::stof(data[2]);
			mc->name = data[1];
			mc->calories = std::stoi(data[3]);
			mc->type = Type::MainCourse;

			// Store the item in the list
			this->items.push_back(mc);
		}
	}
}

// Implementation for Menu::ToString
std::string Menu::ToString()
{
	// Current menu index
	int menu_idx = 0;

	// Output string
	std::string output;

	// Log that we are in the appetisers category
	output += ("------------------Appetisers-------------\n");

	// Loop through item and print names
	for (int i = 0; i < items.size(); i++)
	{
		// Check for Appetisers and skip if not
		if (items[i]->type != Type::Appetiser) continue;

		// Print out the item
		output += sfmt("(%d) %s\n", menu_idx, items[i]->ToString().c_str());

		// Increment menu index
		menu_idx++;
	}

	// Log that we are in the Main Dishes category
	output += ("\n------------------Main Dishes-------------\n");

	// Loop through item and print names
	for (int i = 0; i < items.size(); i++)
	{
		// Check for Appetisers and skip if not
		if (items[i]->type != Type::MainCourse) continue;

		// Print out the item
		output += sfmt("(%d) %s\n", menu_idx, items[i]->ToString().c_str());

		// Increment menu index
		menu_idx++;
	}

	// Log that we are in the Main Dishes category
	output += ("\n------------------Beverages-------------\n");

	// Loop through item and print names
	for (int i = 0; i < items.size(); i++)
	{
		// Check for Appetisers and skip if not
		if (items[i]->type != Type::Beverage) continue;

		// Print out the item
		output += sfmt("(%d) %s\n", menu_idx, items[i]->ToString().c_str());

		// Increment menu index
		menu_idx++;
	}

	// Return the output.
	return output;
}