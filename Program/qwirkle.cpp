#include <iostream>
#include <string>

#include "View.h"
#include "Model.h"
#include "Controller.h"

#define EXIT_SUCCESS 0

static Model model = Model();
static View view = View();
static Controller controller = Controller();

int main(void)
{
    while (true)
    {
        view.printWelcomeMessage();
        controller.Menu(view, model);
        return;
    }

    delete &view;
    delete &model;
    delete &controller;

    return EXIT_SUCCESS;
}

// TODO:
// When a new game is started, a special sequence of operations must be conducted:
// 1. Create the ordering for the tile bag
// 2. Set up the initial player hands
// 3. Start with an empty board, with player 1 as the starting player
// You will need to devise your own algorithm to “shuffle” the bag of tiles to create a “random” initial order. This
// is left up to your own invention. The lectures will talk about randomness is C++ programs.
// Then the initial tiles are added to the player’s hands. 6 tiles are drawn from the tile bag and placed in the 1st
// player’s hand. Then 6 tiles are drawn from the tile bag and placed in the 2nd player’s hand.
// Finally, the board starts with no tiles placed, so that when displayed, it should be empty.
