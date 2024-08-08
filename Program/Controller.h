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
    void Menu(View view);
    void NewGame(View view);
    void Quit(std::string out);

private:
    // Member vars
    Model* model;
};

#endif