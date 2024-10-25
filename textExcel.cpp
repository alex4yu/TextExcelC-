#include <iostream>
#include <string>
#include "SpreadSheet.h"


int main()
{
    // Create a Spreadsheet object
    SpreadSheet spreadsheet;

    // Create a string to hold user input
    std::string input;

    // Get the first line of input from the user
    std::getline(std::cin, input);

    // Command loop
    while (input != "quit")
    {
        // Check if input is empty (like in your original code)
        if (input.empty())
        {
            // Do nothing, just skip the loop iteration
        }
        else
        {
            // Process the input command
            std::string result = spreadsheet.processCommand(input);
            // Output the result
            std::cout << result << std::endl;
        }

        // Get the next line of input
        std::getline(std::cin, input);
    }

    return 0;
}
