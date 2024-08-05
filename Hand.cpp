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
    this->handsize = other.handsize;
    this->tiles = other.tiles;
}

// Destructor
Hand::~Hand()
{
    tiles.clear();
}

// Methods


// Get/Set
Tile* Hand::getTile(Colour colour, Shape shape)
{
    for (int i = 0; i < sizeof(this->tiles); i++)
    {
        if (this->tiles[i].getColour() == colour
        && this->tiles[i].getShape() == shape)
        {
            return &this->tiles[i];
        }
    }
}

void Hand::setTile(Colour colour, Shape shape, Tile* tile)
{
    for (int i = 0; i < sizeof(this->tiles); i++)
    {
        if (this->tiles.at(i).getColour() == colour
        && this->tiles.at(i).getShape() == shape)
        {
            // TODO
            // Assign new tile to position
            // this->tiles.at(i) = tile;
        }
    }
}

int Hand::getHandsize()
{
    return this->handsize;
}

void Hand::setHandsize(int handsize)
{
    this->handsize = handsize;
}