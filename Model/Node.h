#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"
#include "TileCodes.h"

class Node
{
   public:

   // Constructor(s)/destructor

   Node();
   Node(Tile *tile, Node *next);
   Node(Node &other);
   ~Node();

   // Methods

   bool checkNextMatch(); // Check if the next tile in the list is a match for this
   void clear(); // Clear the contents of the node

   // Get/Set

   Tile *getTile();
   void setTile(Tile *tile);

   Node *getNext();
   void setNext(Node *next);

   private:

   // Member vars
   
   Tile *tile;
   Node *next;

};

#endif // ASSIGN2_NODE_H