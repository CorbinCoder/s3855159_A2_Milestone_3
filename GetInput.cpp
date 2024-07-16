#include "GetInput.h"

// Pass function into a function -> able to call a function inside a function
// Syntax: <return type> (*<function name>)(<parameters' types>)
//         bool          (*validateFunc)   (std::string &, int, bool)
std::string getInput(bool (*validateFunc)(std::string &))
{
    bool isValidInput = false; // false initalially to keep the loop runs at least once
    std::string resultString;  // Convert this variable to integer after validation
    

    while (!isValidInput)
    {
        std::cout << "> ";
        std::getline(std::cin, resultString); // The program inputs resultString, even if the string is empty

        // Check for EOF
        if (std::cin.eof())
        {
            std::cout << "Goodbye" << std::endl;
            break;
        }

        bool isValid = validateFunc(resultString);
        if (isValid)
        {
            isValidInput = true;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }

    return resultString;
}


// Function to check if user input is integer
bool isInteger(std::string &s) {
    std::string::iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool validateUserChoice(std::string &userChoiceString)
{
    // Validate if the userChoiceString displays an integer
    if (isInteger(userChoiceString))
    {
        int userChoiceInteger = std::stoi(userChoiceString);
        if (userChoiceInteger >= 1 && userChoiceInteger <= 4)
        {
            return true;
        }
    }

    return false;
}

bool validateName(std::string &nameString)
{
    // TODO: Validate upperecase letters. NO spaces, numbers and special charachters.
    return true;
}