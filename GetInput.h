
#ifndef ASSIGN2_GETINPUT_H
#define ASSIGN2_GETINPUT_H

#include <iostream>
#include <string>

std::string getInput(bool (*validateFunc)(std::string &));
bool isInteger(std::string &s);
bool validateUserChoice(std::string &userChoiceString);
bool validateName(std::string &nameString);

#endif // ASSIGN2_GETINPUT_H