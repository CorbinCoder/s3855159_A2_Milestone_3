#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H

#include "Tile.h"
#include "LinkedList.h"
#include <vector>

class Hand
{
public:
    // Constructor(s)/Destructor
    Hand();
    Hand(int handsize);
    Hand(Hand &other);
    ~Hand();

    // Methods

    // Get/Set
    Tile *getTile(Colour colour, Shape shape);
    int getHandsize();
    void removeTile(Tile *tile);
    void addTile(Tile *tile);
    void drawHand(Tile *bagTiles[]);
    void setTile(Colour colour, Shape shape, Tile *tile);
    void setHandsize(int handsize);

private:
    // Member vars
    LinkedList tiles;
    int handsize;
};

#endif
