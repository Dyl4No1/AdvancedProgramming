// Menu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Header/Menu.hpp"
#include "Header/Order.hpp"
#include "Header/Item.hpp"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string user_command;
    vector <string> parameters;

    // Create a menu object from a CSV file, change directory when marking
    Menu menu = Menu("C:\\Users\\dylan\\source\\repos\\Takeaway\\Menu\\Debug\\menu.csv");

    // Create an order object
    Order order = Order();

    // Log commands.
    printf("menu - display the menu to the user\n");
    printf("add[INDEX] - add an item to the order by numeric index in the menu(starting at 1)\n");
    printf("remove[INDEX] - remove item from order by numeric index in the order(starting at 1)\n");
    printf("checkout - display the items in the user’s order, the price, and discount savings\n");
    printf("help - display a help menu for the user with the available options\n");
    printf("exit - terminate the program gracefully\n");


    // Loop until the user exitings )))
    while (user_command != "exit")
    {
        getline(cin, user_command);
        char* cstr = new char[user_command.length() + 1];
        strcpy(cstr, user_command.c_str());

        char* token;
        token = strtok(cstr, " ");

        while (token != NULL)
        {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        string command = parameters[0];

        if (command.compare("menu") == 0) {
            cout << menu.ToString() << endl;
        }
        else if (command.compare("add") == 0)
        {
            // Check that data was passed
            if (parameters[1] == "")
            {
                // Log an error message
                printf("Please provide an item index.\n");

                // Skip this input
                continue;
            }

            // Convert to a number
            int value = stoi(parameters[1]);

            // Check the index
            if (value > menu.items.size())
            {
                // Log an error message
                printf("Please provide a valid item index.\n");

                // Skip this input
                continue;
            }

            // Get the item from the list
            Item* item = menu.items[value];

            // Store the item ptr in the order object.
            order.items.push_back(item);

            // Log that the item was added
            printf("%s added to order!\n", item->name.c_str());
        }
        else if (command.compare("remove") == 0)
        {
            // Check that data was passed
            if (parameters[1] == "")
            {
                // Log an error message
                printf("Please provide an item index.\n");

                // Skip this input
                continue;
            }

            // Convert to a number
            int value = stoi(parameters[1]);

            // Check the index
            if (value > order.items.size())
            {
                // Log an error message
                printf("Please provide a valid item index.\n");

                // Skip this input
                continue;
            }

            // Get item at order index
            Item* item = order.items[value];

            // Remove the item from the list
            order.items.erase(order.items.begin() + value);

            // Log that the item was removed
            printf("%s removed from the order!\n", item->name.c_str());

        }
        else if (command.compare("checkout") == 0)
        {
            // Print out the checkout line
            printf("======= Checkout ========\n");

            // Get and print out the order string
            printf("%s\n", order.toString().c_str());

            // Ask the user if they want to place their order
            printf("Do you want to place your order?\n");
            printf("Type 'y' to confirm, or 'n' to go back and modify it\n");

            // Loop until user command is 'n'
            while (!(user_command == "n"))
            {
                // Read the user's input
                getline(cin, user_command);
                char* cstr = new char[user_command.length() + 1];
                strcpy(cstr, user_command.c_str());

                // Check for 'y' as user command
                if (user_command == "y")
                {
                    // Log that the user is saving
                    printf("You have opted to checkout. Writing receipt to receipt.txt\n\n");

                    // Create an output file string to receipt.txt
                    ofstream out("receipt.txt");

                    // Write receipt to file
                    out << order.toString();

                    // Close the output stream
                    out.close();
                }
                else if (user_command != "n")
                {
                    // Log an error message.
                    printf("Please enter either 'y' or 'n'.\n\n");
                }
                else
                {
                    // Log status.
                    printf("You have opted not to checkout. Returning to menu\n\n");
                }

            }

           

        }
        else if (command.compare("help") == 0)
        {
            printf("menu - display the menu to the user\n");
            printf("add[INDEX] - add an item to the order by numeric index in the menu(starting at 1)\n");
            printf("remove[INDEX] - remove item from order by numeric index in the order(starting at 1)\n");
            printf("checkout - display the items in the user’s order, the price, and discount savings\n");
            printf("help - display a help menu for the user with the available options\n");
            printf("exit - terminate the program gracefully\n");
        }

        parameters.clear();

    }

    cout << "Press any key to quit...";
    getchar();

}