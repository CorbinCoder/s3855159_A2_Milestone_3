#include "GetInput.h"

// Pass function into a function -> able to call a function inside a function
// Syntax: <return type> (*<function name>)(<parameters' types>)
//         bool          (*validateFunc)   (std::string &, int, bool)
std::string GetInput::getInput(bool (*validateFunc)(std::string &))
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
bool GetInput::isInteger(std::string &s)
{
    std::string::iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

bool GetInput::validateUserChoice(std::string &userChoiceString)
{
    // Validate if the userChoiceString displays an integer
    if (GetInput::isInteger(userChoiceString))
    {
        int userChoiceInteger = std::stoi(userChoiceString);
        if (userChoiceInteger >= 1 && userChoiceInteger <= 4)
        {
            return true;
        }
    }

    return false;
}

// Validate upperecase letters. NO spaces, numbers and special charachters.
bool GetInput::validateName(std::string &nameString)
{
    // For every character in the nameString
    for (char c : nameString)
    {
        if (!(c >= 'A' && c <= 'Z')) // Check if the character is not an uppercase letter, which isn't between 'A' and 'Z'
        {
            return false;
        }
    }

    return true;
}