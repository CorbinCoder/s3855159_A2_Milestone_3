#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Menu(View view, Model model)
{
    view.printMenu();
    std::string userChoiceString = GetInput::getInput(GetInput::validateUserChoice);
    int userChoiceInteger = std::stoi(userChoiceString);
    switch (userChoiceInteger)
    {
    case 1:
        NewGame(model, view);
        break;
    case 2:
        FileHandler::loadGame();
    case 3:
        break;
    case 4:
        Quit("OUT URL");
        break;
    }
}

void Controller::NewGame(Model model, View view)
{
    std::cout << std::endl
              << "Starting a New Game" << std::endl;

    std::cout << std::endl
              << "Enter a name for player 1 (uppercase characters only)" << std::endl;
    model.getPlayer(1).init(GetInput::getInput(GetInput::validateName), Hand(6), 0, 1);

    std::cout << std::endl
              << "Enter a name for player 2 (uppercase characters only)" << std::endl;
    model.getPlayer(2).init(GetInput::getInput(GetInput::validateName), Hand(6), 0, 2);

    std::cout << std::endl
              << "Let's Play!" << std::endl;
}

void Controller::Quit(std::string out)
{
    // Save game state to file
    // Save();

    std::cout << "Goodbye" << std::endl;
}