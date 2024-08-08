#include "../Model/Tile.h"

Tile::Tile()
{
}

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

bool Tile::validateTile(std::string tileString)
{
    // Input: Y5
    if (tileString.size() != 2)
    {
        return false;
    }

    bool correctColour = false;
    for (Colour colour : TILE_COLOURS)
    {
        if (colour == tileString[0])
        {
            correctColour = true;
            break;
        }
    }

    bool correctShape = false;
    for (Shape shape : TILE_SHAPES)
    {
        // int('5') = collated value - 53
        // int('0') = 48
        // '5' - '0' = 53 - 48 = 5
        // std::cout << int(tileString[1]) << " " << tileString[1] - '0' << std::endl;
        if (shape == tileString[1] - '0') // '0' - '9'
        {
            correctShape = true;
            break;
        }
    }

    // if(correctColour && correctShape) return true;
    // else return false;
    return correctColour && correctShape;
}

bool Tile::validateTilePosition(std::string tilePositionString, int width, int height)
{
    // Input: B2
    // Output: true

    // Input: B11
    // Output: true

    char row = tilePositionString[0];
    if (row < 'A' || row >= 'A' + height)
    {
        return false;
    }

    std::string colString = tilePositionString.substr(1);
    int col = std::stoi(colString);
    if (col < 1 || col > width)
    {
        return false;
    }

    return true;
}