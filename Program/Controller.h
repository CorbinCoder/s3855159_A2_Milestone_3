#ifndef ASSIGN2_CONTROLLER_H
#define ASSIGN2_CONTROLLER_H

#include "../Model/LinkedList.h"
#include "../Utilities/GetInput.h"
#include "../Utilities/FileHandler.h"
#include "../Model/Model.h"
#include "View.h"

class Controller
{
public:
    // Contructors/destructor
    Controller();
    ~Controller();

    // Methods
    void menu(View view);
    void newGame(View view);
    void quit(std::string out);
    void gameplay();
    void displayTurn();
    void qwirkle();
    void endGame();
    void calculateScore();

private:
    // Member vars
    Model *model;
};

#endif