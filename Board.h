#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

// Declare the board dimension types
typedef int Height;
typedef int Width;

// Declare the Board class
class Board
{
    private:
        // Declare the board dimension fields
        Height height;
        Width width;

    public:
        // Declare the constructor
        Board(Height height, Width Width);

        // Declare the copy constructor
        Board(Board& board);

        // Declare the move constructor
        Board(Board&& board);

        // Declare the destructor
        ~Board();
};

#endif // ASSIGN2_BOARD_H
