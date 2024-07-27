#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include "LinkedList.h"
#include "Tile.h"


class Bag
{
    public:

    // Contructor(s)/Destructor
    Bag(int numeach);
    Bag(Bag &other);
    ~Bag();

    // Methods
    void New(int numeach);
    Tile* Draw();
    void Shuffle();


    private:

    // Member vars
    LinkedList* tiles;

};

#endif