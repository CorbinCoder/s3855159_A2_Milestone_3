
#ifndef ASSIGN2_GETINPUT_H
#define ASSIGN2_GETINPUT_H

#include "../Model/Tile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class GetInput
{
public:
    static std::string getInput(bool (*validateFunc)(std::string));
    static bool validateUserChoice(std::string userChoiceString);
    static bool validateName(std::string nameString);
    static bool validateFileName(std::string fileName);
    bool GetInput::validatePlaceCommand(std::string command);
    bool GetInput::validateReplaceCommand(std::string command);

private:
    static bool isInteger(std::string &s);
    static std::vector<std::string> readFileLines(std::string fileName);
    static bool validateScore(std::string scoreString);
    static bool validatePlayerHand(std::string playerHand);
    static std::vector<int> validateBoardSizes(std::string boardSizes);
    static bool validateBoardState(std::string boardState, int width, int height);
};

#endif // ASSIGN2_GETINPUT_H
