#include "GetInput.h"

// Pass function into a function -> able to call a function inside a function
// Syntax: <return type> (*<function name>)(<parameters' types>)
//         bool          (*validateFunc)   (std::string &, int, bool)
std::string GetInput::getInput(bool (*validateFunc)(std::string))
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

bool GetInput::validateUserChoice(std::string userChoiceString)
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
bool GetInput::validateName(std::string nameString)
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

bool GetInput::validateFileName(std::string fileName)
{
    std::ifstream file(fileName);
    if(!file.good()) 
    {
        return false; // return false if the file doesn't exist or can't be opened
    }
    // After the above check, the file exists and can be opened

    // Read file content
    // Each line is a string
    // We have multiple lines in the file => We should use an array/a vector of strings for the lines
    // Go to each line and do the validation

    // 2. Check that the format of the file is correct. The format for saved games is described in Section 2.3.7
    /*
    <player 1 name>
    <player 1 score>
    <player 1 hand>
    <player 2 name>
    <player 2 score>
    <player 2 hand>
    <Current board shape>
    <Board State>
    <tile bag contents>
    <current player name>

    Example:
    A
    8
    Y5,R5,O2,B1,P6,Y3
    B
    6
    P2,P3,O6,Y4,B2,O3
    6,6
    B4@B2, B6@B3, B5@B4, R4@C2, G5@C4, Y1@D1, Y4@D2, Y2@D3, P4@E2
    P2,B5,.....
    A

    Board: 6x6 26x26
      0 1 2 3 4 5
    A
    B
    C
    D
    E
    F

    The format for each of the items is:
        - Name: ASCII text - upperecase letters. NO spaces, numbers and special charachters.
        - Score: Integer >= 0
        - Player hand and tile bag: comma separated ordered list - each tile is represented by an uppercase letter followed by a positive integer
        - Current board shape: Height,width - comma seperated integers > 0 and <= 26
        - Board State: All tiles currently placed on the board should appear as a list of tile@position. <tile_letter><tile_number>@<row><column>,
            seperated by ", " (a comma followed by a space)
    */

    return true;
}