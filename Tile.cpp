#include "Tile.h"

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

// deconstuctor
Tile::~Tile()
{
}

// Copy Constructor
Tile::Tile(Tile &other)
{
}

// Move Constructor
Tile::Tile(Tile &&other)
{
}

Colour Tile::getColour()
{
    return this->colour;
}

Shape Tile::getShape()
{
    return this->shape;
}
