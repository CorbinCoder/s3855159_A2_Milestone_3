#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H

#include "Tile.h"
#include <vector>

class Hand
{
    public:

    // Constructor(s)/Destructor
    Hand(int handsize);
    Hand(Hand &other);
    ~Hand();

    // Methods

    // Get/Set
    Tile *getTile(Colour colour, Shape shape);
    int getHandsize();
    void setTile(Colour colour, Shape shape, Tile *tile);
    void setHandsize(int handsize);

    private:

    // Member vars
    std::vector<Tile> tiles;
    int handsize;
};

#endif