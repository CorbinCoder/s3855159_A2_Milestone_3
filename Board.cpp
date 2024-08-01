#include "Board.h"

// Define the constructor
Board::Board(Size size)
{
    this->size = size;
}

// Define the destructor
Board::~Board()
{    
}

// Define the copy constructor
Board::Board(Board& board)
{
    this->size = board.size;
}

// Define the move constructor
Board::Board(Board&& board)
{
    this->size = board.size;
}
