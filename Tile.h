
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile
{
public:
   Colour colour;
   Shape shape;

   // constructor
   Tile(Colour colour, Shape shape);

   // Deconstructor
   ~Tile();

   // Copy Constructor
   Tile(Tile &other);

   // Move Constructor
   Tile(Tile &&other);

   Colour getColour();

   Shape getShape();
};

#endif // ASSIGN2_TILE_H
