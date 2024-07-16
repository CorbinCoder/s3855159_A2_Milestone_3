#include "LinkedList.h"
#include "GetInput.h"

#include <iostream>
#include <string>  

#define EXIT_SUCCESS 0

void printWelcomeMessage();
void printMenu();
void createNewGame();

int main(void)
{
   LinkedList *list = new LinkedList();
   delete list;

   printWelcomeMessage();
   printMenu();

   return EXIT_SUCCESS;
}

void printWelcomeMessage()
{
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
}

void printMenu()
{
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits" << std::endl;
   std::cout << "4. Quit" << std::endl;

   std::string userChoiceString = getInput(validateUserChoice);
   int userChoiceInteger = std::stoi(userChoiceString);
   switch (userChoiceInteger)
   {
   case 1:
      createNewGame();
      break;
   case 2:
      break;
   case 3:
      break;
   case 4:
      std::cout << "Goodbye" << std::endl;
      break;
   }
}

void createNewGame()
{
   std::cout << std::endl
             << "Starting a New Game" << std::endl;
   std::cout << std::endl
             << "Enter a name for player 1 (uppercase characters only)" << std::endl;
   std::string player1 = getInput(validateName);
   std::cout << std::endl
             << "Enter a name for player 2 (uppercase characters only)" << std::endl;
   std::string player2 = getInput(validateName);

   std::cout << std::endl
             << "Let's Play!" << std::endl;
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
