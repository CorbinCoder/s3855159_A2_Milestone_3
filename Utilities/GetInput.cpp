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
        int scoreInteger = std::stoi(userChoiceString);
        if (scoreInteger >= 1 && scoreInteger <= 4)
        {
            return true;
        }
    }

    return false;
}

// Validate upperecase letters. NO spaces, numbers and special charachters.
bool GetInput::validateName(std::string nameString)
{
    if (nameString.empty())
        return false;

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

std::vector<std::string> GetInput::readFileLines(std::string fileName)
{
    std::ifstream file(fileName); // Read the file with path "fileName" and assign the content to variable "file";
    std::vector<std::string> lines;

    // We know that the file is good
    std::string currentLine; // The current line that we are reading
    while (std::getline(file, currentLine))
    { // read the current line
        lines.push_back(currentLine);
    }

    // After finishing reading the whole file, we need to close the file
    file.close();
    return lines;
}

bool GetInput::validateScore(std::string scoreString)
{
    if (GetInput::isInteger(scoreString))
    {
        int scoreInteger = std::stoi(scoreString);
        if (scoreInteger < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool GetInput::validatePlayerHand(std::string playerHand)
{
    //  Player hand: comma separated ordered list - each tile is represented by an uppercase letter followed by a positive integer
    // Step 1: read the playHand and seperate the string by the comma and put the result into a vector of string
    //          Y5,R5,O2,B1,P6,Y3 => ["Y5", ...]
    // https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
    std::vector<std::string> tiles;
    std::stringstream ss(playerHand); // Y5,R5,O2,B1,P6,Y3
    std::string tile;
    while (ss.good())
    {
        std::getline(ss, tile, ',');
        tiles.push_back(tile);
    }

    for (std::string tile : tiles)
    {
        // std::cout << tile << std::endl;

        if (!Tile::validateTile(tile))
        {
            return false;
        }
    }

    return true;
}

std::vector<int> GetInput::validateBoardSizes(std::string boardSizes)
{
    // Current board shape: Height,width - comma seperated integers > 0 and <= 26
    std::vector<std::string> sizes;
    std::stringstream ss(boardSizes); // 6,6
    std::string size;
    while (ss.good())
    {
        std::getline(ss, size, ',');
        sizes.push_back(size);
    }

    if (sizes.size() != 2)
    {
        return std::vector<int>();
    }

    std::vector<int> boardSizesInt;
    for (std::string size : sizes)
    {
        if (!GetInput::isInteger(size))
        {
            return std::vector<int>();
        }

        int sizeInteger = std::stoi(size);
        if (sizeInteger <= 0 || sizeInteger > 26)
        {
            return std::vector<int>();
        }

        boardSizesInt.push_back(sizeInteger);
    }

    return boardSizesInt;
}

bool GetInput::validatePlaceCommand(std::string command)
{
}

bool GetInput::validateReplaceCommand(std::string command)
{
}

bool GetInput::validateBoardState(std::string boardState, int width, int height)
{
    // Board State: All tiles currently placed on the board should appear as a list of tile@position. <tile_letter><tile_number>@<row><column>,
    // seperated by ", " (a comma followed by a space)
    // B4@B2, B6@B3, B5@B4, R4@C2, G5@C4, Y1@D1, Y4@D2, Y2@D3, P4@E2
    std::vector<std::string> states;
    std::string delimiter = ", ";
    unsigned int position = 0;
    while ((position = boardState.find(delimiter)) != std::string::npos)
    {
        states.push_back(boardState.substr(0, position));
        boardState.erase(0, position + delimiter.length());
    }

    states.push_back(boardState);

    for (std::string state : states)
    {
        std::vector<std::string> stateParts;
        std::stringstream ss(state);
        std::string statePart;
        while (ss.good())
        {
            std::getline(ss, statePart, '@');
            stateParts.push_back(statePart);
        }

        if (stateParts.size() != 2)
        {
            return false;
        }

        if (!Tile::validateTile(stateParts[0]) || !Tile::validateTilePosition(stateParts[1], width, height))
        {
            return false;
        }
    }

    return true;
}

bool GetInput::validateFileName(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.good())
    {
        return false; // return false if the file doesn't exist or can't be opened
    }
    // After the above check, the file exists and can be opened

    // Read file content
    // Each line is a string
    // We have multiple lines in the file => We should use an array/a vector of strings for the lines
    // Go to each line and do the validation
    std::vector<std::string> lines = GetInput::readFileLines(fileName);
    if (lines.size() != 10)
    {
        return false;
    }

    if (!GetInput::validateName(lines[0]))
    {
        return false;
    }

    if (!GetInput::validateScore(lines[1]))
    {
        return false;
    }

    if (!GetInput::validatePlayerHand(lines[2]))
    {
        return false;
    }

    if (!GetInput::validateName(lines[3]))
    {
        return false;
    }

    if (!GetInput::validateScore(lines[4]))
    {
        return false;
    }

    if (!GetInput::validatePlayerHand(lines[5]))
    {
        return false;
    }

    std::vector<int> boardSizes = GetInput::validateBoardSizes(lines[6]);
    if (boardSizes.size() != 2)
    {
        return false;
    }

    if (!GetInput::validateBoardState(lines[7], boardSizes[0], boardSizes[1]))
    {
        return false;
    }

    if (!GetInput::validatePlayerHand(lines[8]))
    {
        return false;
    }

    if (lines[9] != lines[0] && lines[9] != lines[3])
    {
        return false;
    }

    std::cout << std::endl
              << "Qwirkle game successfully loaded" << std::endl;
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