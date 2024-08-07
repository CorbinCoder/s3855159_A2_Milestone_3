#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include "TileCodes.h"
#include <string>
#include <iostream>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

const Colour TILE_COLOURS[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
const Shape TILE_SHAPES[] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

class Tile
{
private:
   Colour colour;
   Shape shape;

public:
   // constructor
   Tile(Colour colour, Shape shape);

   // Destructor
   ~Tile();

   // Copy Constructor
   Tile(Tile &other);

   // Move Constructor
   Tile(Tile &&other);

   Colour getColour();

   Shape getShape();

   static bool validateTile(std::string tileString);
   static bool validateTilePosition(std::string tilePositionString, int width, int height);
};

#endif // ASSIGN2_TILE_H
