#pragma once

#include "ItemList.hpp"

class Order : public ItemList
{
public: // Members for this class

	float total;


public: // Methods for this class


	std::string toString();
};


std::string Order::toString()
{
	// Output string
	std::string output;

	// Used to calculate the order total
	float total = 0.0f;

	// Used to handle the two-for-one counter
	int tfo_count = 0;

	// 2-4-1 bool check
	bool tfo = false;

	// Used to track how much money was saved
	float saved = 0.0f;

	// Loop through items
	for (auto item : this->items)
	{
		// Add total to counter
		total += item->price;

		// Check for appetiser type
		if (!(item->type == Type::Appetiser)) continue;

		// Cast item to an appetiser
		Appetiser* ap = static_cast<Appetiser*>(item);

		// Check for two for one
		if (!ap->twoForOne) continue;

		// Check if we should apply two for one
		if (tfo)
		{

			// Add saved amt to total saved
			saved += item->price;

			// Disable two for one
			tfo = !tfo;
		}
		else tfo = !tfo;
	}

	// Loop through items in the list.
	for (int i = 0; i < this->items.size(); i++)
	{
		// Get item ptr
		Item* item = this->items[i];

		// Append current item
		output += sfmt("(%d) %s: %.2f, %d cal", i, item->name.c_str(), item->price, item->calories);

		// Check for appetiser and add 2-4-1 status if needed
		if (item->type == Type::Appetiser && static_cast<Appetiser*>(item)->twoForOne) output += " (2-4-1)";

		// Add newline delimiter
		output += "\n";
	}

	// Subtract savings
	total -= saved;

	// Append the total price to the string.
	output += sfmt("Total: %.2f\n", total);

	// Check if 2-4-1 was applied and add the total saved to output.
	if (saved > 0.0f) output += sfmt("2-4-1 applied. Total saved: %.2f\n", saved);

	// Return the output string.
	return output;
}