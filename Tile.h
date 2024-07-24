#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

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
};

#endif // ASSIGN2_TILE_H
