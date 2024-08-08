#include "FileHandler.h"

void FileHandler::loadGame()
{
    // TODO: load game
    std::cout << std::endl;
    std::cout << "Enter the filename from which load a game" << std::endl;
    std::string fileName= GetInput::getInput(GetInput::validateFileName);
    return;
}

void FileHandler::saveGame()
{
    // TODO: save game
    return;
}