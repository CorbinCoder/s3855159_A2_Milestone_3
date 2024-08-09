#ifndef ASSIGN2_VIEW_H
#define ASSIGN2_VIEW_H
#include <iostream>

class View
{
public:
    void printWelcomeMessage();
    void printMenu();
    void displayTurn();
    void printSingleLine(std::string message);
    void printMultiLine(std::string message);

private:
};

#endif