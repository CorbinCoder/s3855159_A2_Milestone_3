
#ifndef ASSIGN2_GETINPUT_H
#define ASSIGN2_GETINPUT_H

#include <iostream>
#include <string>
#include <fstream>

class GetInput
{
public:
    static std::string getInput(bool (*validateFunc)(std::string));
    static bool validateUserChoice(std::string userChoiceString);
    static bool validateName(std::string nameString);
    static bool validateFileName(std::string fileName);

private:
    static bool isInteger(std::string &s);
};

#endif // ASSIGN2_GETINPUT_H
