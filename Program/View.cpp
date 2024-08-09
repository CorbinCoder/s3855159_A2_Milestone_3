#include "View.h"

void View::printWelcomeMessage()
{
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
}

void View::printMenu()
{
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

void View::displayTurn()
{

    // std::cout << currentPlayer->getName() + ", it's your turn" << std::endl;
    // std::cout <<"Score for" Player1->getName() + ": " + Player1->getScore() << std::endl;
    // std::cout << "Score for" Player2->getName() + ": " + Player2->getScore() << std::endl;
    //  board.displayboard

    // std::cout << Your hand is:<< std::endl;
    // std::cout << currentPlayer->getHand() << std::endl
}

void View::printSingleLine(std::string message)
{
    std::cout << message << std::endl;
}

void View::printMultiLine(std::string message)
{
    std::cout << message;
}