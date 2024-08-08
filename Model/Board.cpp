#include <vector>
#include "Board.h"

// Define the constructor
Board::Board(Height height, Width Width)
{
    this->height = height;
    this->width = width;
}

// Define the destructor
Board::~Board()
{
}

// Define the copy constructor
Board::Board(Board &board)
{
    this->height = board.height;
    this->width = board.width;
}

// Define the move constructor
Board::Board(Board &&board)
{
    this->height = board.height;
    this->width = board.width;
}

// Define the add tile method
void addTile(Tile tile, int col, int row)
{
    // TODO
}

// Define the display board method
void displayBoard()
{
    // TODO
}