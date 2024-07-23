#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

// destructor
Tile::~Tile()
{
}

// Copy Constructor
Tile::Tile(Tile &other)
{
    colour = other.colour;
    shape = other.shape;
}

// Move Constructor
Tile::Tile(Tile &&other)
{
    colour = other.colour;
    shape = other.shape;
}

Colour Tile::getColour()
{
    return this->colour;
}

Shape Tile::getShape()
{
    return this->shape;
}
