#include "Hand.h"

// Default constructor
Hand::Hand()
{
}

// Constructor
Hand::Hand(int handsize)
{
    this->handsize = handsize;
}

// Copy constructor
Hand::Hand(Hand &other)

{
    this->handsize = handsize;
}

// Copy constructor
// Hand::Hand(Hand &other)
// {
//     this->handsize = other.handsize;
//     this->tiles = other.tiles;
// }

// Destructor
Hand::~Hand()
{
    tiles.clear();
}

// Methods

// Get/Set

Tile *Hand::getTile(Colour colour, Shape shape)
{
    for (unsigned int i = 0; i < sizeof(this->tiles); i++)
    {
        // if (this->tiles[i].getColour() == colour && this->tiles[i].getShape() == shape)
        // {
        //     return &this->tiles[i];
        // }
    }

    return NULL;
}

void Hand::setTile(Colour colour, Shape shape, Tile* tile)
{
    for (unsigned int i = 0; i < sizeof(this->tiles); i++)
    {
        if (this->tiles.at(i)->getColour() == colour && this->tiles.at(i)->getShape() == shape)
        {
            // Assign new tile to position

            this->tiles.replace(i, this->tiles.at(i));
        }
    }
}

void Hand::removeTile(Tile* tile)
{
    // loops through array and adds tiles to linkedList
    for (int i = 0; i < sizeof(tiles); ++i)
    {
        tiles.addBack(this->tiles.at(i));
    }
}

void Hand::addTile(Tile* tile)
{
    this->tiles.addBack(tile);
}

int Hand::getHandsize()
{
    return this->handsize;
}

void Hand::setHandsize(int handsize)
{
    this->handsize = handsize;
}
