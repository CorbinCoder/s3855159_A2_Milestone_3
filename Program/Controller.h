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
    void menu();
    void newGame();
    void quit(std::string out);
    void gameplay();
    void qwirkle();
    void endGame();
    void calculateScore();

private:
    // Member vars
    Model *model;
};

#endif