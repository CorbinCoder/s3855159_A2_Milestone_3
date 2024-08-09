#include "Controller.h"

static View view = View();

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::menu()
{
    view.printWelcomeMessage();
    view.printMenu();
    std::string userChoiceString = GetInput::getInput(GetInput::validateUserChoice);
    int userChoiceInteger = std::stoi(userChoiceString);

    switch (userChoiceInteger)
    {
    case 1:
        newGame();
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

void Controller::newGame()
{
    std::cout << std::endl
              << "Starting a New Game" << std::endl;

    // model.getBoard().New(11, 11);
    // model.getBag().New(4);
    // model.getBag().Shuffle();

    std::cout << std::endl
              << "Enter a name for player 1 (uppercase characters only)" << std::endl;

    std::string player1Name = GetInput::getInput(GetInput::validateName);

    std::cout << std::endl
              << "Enter a name for player 2 (uppercase characters only)" << std::endl;
    std::string player2Name = GetInput::getInput(GetInput::validateName);

    this->model = new Model(player1Name, player2Name);

    // model.drawHand(1);
    // model.drawHand(2);

    std::cout << std::endl
              << "Let's Play!" << std::endl;
}

// the gameplay loop
void Controller::gameplay()
{
    bool inGame = true;

    while (inGame)
    {
        // keeps track of current players turn

        // view.displayTurn();

        // std::string command = GetInput::getInput();

        // if (command contains 'save' ){
        // getInput.ValidateSaveCommand
        // saveFile()
        // inGame = false;
        //}
        // else {
        // if (command contains 'at') {
        // validate place tile command
        // getInput.ValidatePlaceCommand()
        // player.placeTile()
        // Board.addTile()
        // calculateScore
        //}
        // else{
        // getInput.ValidateReplaceCommand()
        // replaceTile
        //}
        // draw tile from bag
        // Check if end conditions are satisfied
        //}
    }
}

// called when a player scores a qwirkle
void Controller::qwirkle()
{
    view.printSingleLine("QUIRKLE!!");
    // award current player 6 points
}

// prints scores and who won
void Controller::endGame()
{
    std::string endStr = "";
}

// updates score at the end of every turn
void Controller::calculateScore()
{
    // has to keep track of player, recently placed tile, path and score

    // check the adjacent tiles on top bottom left right

    //left and right are one line

    //top and bottom are another

    //basically implement the pathsolver

    //if line length = 6
    qwirkle();
}

void Controller::quit(std::string out)
{
    // Save game state to file
    // Save();

    std::cout << "Goodbye" << std::endl;
}
