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
// Hand::Hand(Hand &other)
// {
//     this->handsize = other.handsize;
//     this->tiles = other.tiles;
// }

// Destructor
// Hand::~Hand()
// {
//     tiles.clear();
// }

// Methods

// Get/Set

Tile *Hand::getTile(Colour colour, Shape shape)
{
    for (unsigned int i = 0; i < this->tiles.size(); i++)
    {
        if (this->tiles.at(i)->getColour() == colour && this->tiles.at(i)->getShape() == shape)
        {
             return this->tiles.at(i);
        }
    }

    return NULL;
}

void Hand::setTile(Colour colour, Shape shape, Tile *newtile)
{
    for (unsigned int i = 0; i < this->tiles.size(); i++)
    {
        if (this->tiles.at(i)->getColour() == colour && this->tiles.at(i)->getShape() == shape)
        {
            // Assign new tile to position

            this->tiles.replace(i, this->tiles.at(i));
        }
    }
}

void Hand::removeTile(Tile *tile)
{
    // find the position tile is at
    for (int i = 0; i < sizeof(this->tiles); i++)
    {
        if (this->tiles.at(i)->getColour() == tile->getColour() && this->tiles.at(i)->getShape() == tile->getShape())
        {
            tiles.remove(i);
        }
    }
}

void Hand::drawHand(Tile *bagTiles[])
{
    // loops through array and adds tiles to linkedList
    for (int i = 0; i < sizeof(*bagTiles) / sizeof(bagTiles[0]); ++i)
    {
        tiles.addBack(bagTiles[i]);
    }
}

void Hand::addTile(Tile *tile)
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
