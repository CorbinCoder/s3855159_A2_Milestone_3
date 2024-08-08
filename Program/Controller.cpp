#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Menu(View view)
{
    view.printMenu();
    std::string userChoiceString = GetInput::getInput(GetInput::validateUserChoice);
    int userChoiceInteger = std::stoi(userChoiceString);

    switch (userChoiceInteger)
    {
    case 1:
        NewGame(view);
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

void Controller::NewGame(View view)
{
    std::cout << std::endl
              << "Starting a New Game" << std::endl;

    // model.getBoard().New(11, 11);
    // model.getBag().New(4);
    // model.getBag().Shuffle();

    std::cout << std::endl
              << "Enter a name for player 1 (uppercase characters only)" << std::endl;
    
    std::string player1Name = GetInput::getInput(GetInput::validateName);
    
    // model.drawHand(1);

    std::cout << std::endl
              << "Enter a name for player 2 (uppercase characters only)" << std::endl;
    std::string player2Name = GetInput::getInput(GetInput::validateName);

    this->model = new Model(player1Name, player2Name);

    std::cout << std::endl
              << "Let's Play!" << std::endl;
}

void Controller::Quit(std::string out)
{
    // Save game state to file
    // Save();

    std::cout << "Goodbye" << std::endl;
}
