#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"
#include <memory>
#include "../Utilities/TileCodes.h"

class Node
{
public:
   // Constructor(s)/destructor

   Node();
   Node(Tile *tile, Node *next);
   Node(const Node &other);
   Node &operator=(const Node &other);
   ~Node();

   // Methods

   bool checkNextMatch(); // Check if the next tile in the list is a match for this
   void clear();          // Clear the contents of the node

   // Get/Set

   Tile *getTile();
   void setTile(Tile *tile);

   Node *getNext();
   void setNext(Node *next);

private:
   // Member vars

   std::shared_ptr<Tile> tile;
   std::shared_ptr<Node> next;
};

#endif // ASSIGN2_NODE_H