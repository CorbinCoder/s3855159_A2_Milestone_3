#ifndef ASSIGN2_CONTROLLER_H
#define ASSIGN2_CONTROLLER_H


#include "LinkedList.h"
#include "GetInput.h"
#include "FileHandler.h"
#include "Model.h"
#include "View.h"

class Controller
{
    public:

    // Contructors/destructor
    Controller();
    ~Controller();

    // Methods
    void Menu(View view, Model model);
    void NewGame(Model model, View view);
    void Quit(std::string out);

    private:
    // Member vars

};

#endif