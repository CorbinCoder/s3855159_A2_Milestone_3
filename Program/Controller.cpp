#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::menu(View view)
{
    view.printMenu();
    std::string userChoiceString = GetInput::getInput(GetInput::validateUserChoice);
    int userChoiceInteger = std::stoi(userChoiceString);

    switch (userChoiceInteger)
    {
    case 1:
        newGame(view);
        break;
    case 2:
        FileHandler::loadGame();
    case 3:
        break;
    case 4:
        quit("OUT URL");
        break;
    }
}

void Controller::newGame(View view)
{
    std::cout << std::endl
              << "Starting a New Game" << std::endl;

    model.getBoard().New(11, 11);
    model.getBag().New(4);
    model.getBag().Shuffle();

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

// the gameplay loop
void Controller::gameplay()
{
}

void Controller::displayTurn()
{
}

void Controller::qwirkle()
{
}

//
void Controller::endGame()
{
}

//updates score at the end of every turn
void Controller::calculateScore()
{
}

void Controller::quit(std::string out)
{
    // Save game state to file
    // Save();

    std::cout << "Goodbye" << std::endl;
}
