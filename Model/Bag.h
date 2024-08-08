#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include "LinkedList.h"
#include "Tile.h"

class Bag
{
public:
    // Contructor(s)/Destructor
    Bag();
    Bag(int numeach);
    // Bag(Bag &other);
    //~Bag();

    // Methods
    void New(int numeach); // Creates a new, ordered bag of tiles
    Tile *Draw();          // Draw a tile from the bag, and remove it from the bag
    void Shuffle();        // Shuffle the contents of the bag

private:
    // Member vars
    LinkedList tiles;
};

#endif