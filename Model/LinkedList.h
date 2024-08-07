
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "../Utilities/TileCodes.h"

class LinkedList
{
public:
   // Contructor(s)/Destructor
   LinkedList();
   ~LinkedList();

   // Methods
   Tile *find(Colour colour, Shape shape); // Returns tile of node using colour and shape to search
   Tile *at(int i);                        // Returns tile of node using index to search
   void remove(int i);                     // Removes reference to tile at node using index to search
   void printAll();                        // Prints the details of tile of each node in the list
   void clear();                           // Clear the contents of the list
   int size();                             // Returns the number of nodes in the list

   // Get/Set
   Tile *getFront();
   Tile *getBack();
   Node *getHead();
   Node *getTail();
   void setFront(Tile *tile);
   void setBack(Tile *tile);
   void addFront(Tile *tile);
   void addBack(Tile *tile);
   void deleteBack();
   void deleteFront();

private:
   // Member vars
   Node *head;
   Node *tail;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H