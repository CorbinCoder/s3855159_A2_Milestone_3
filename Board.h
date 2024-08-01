#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

// Declare the Size type
typedef int Size;

// Declare the Board class
class Board
{
    private:
        // Declare the size field
        Size size;

    public:
        // Declare the constructor
        Board(Size size);

        // Declare the copy constructor
        Board(Board& board);

        // Declare the move constructor
        Board(Board&& board);

        // Declare the destructor
        ~Board();
};

#endif // ASSIGN2_BOARD_H
