
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "TileCodes.h"

class LinkedList
{
   public:

   // Contructor(s)/Destructor
   LinkedList();
   ~LinkedList();

   // Methods
   Tile* find(Colour colour, Shape shape);
   Tile* at(int i);
   void remove(int i);
   void printAll();
   void clear();
   int size();

   // Get/Set
   Tile *getFront();
   Tile *getBack();
   Node *getHead();
   Node *getTail();
   void setFront(Tile* tile);
   void setBack(Tile* tile);
   void addFront(Tile *tile);
   void addBack(Tile *tile);
   void deleteBack();
   void deleteFront();

   private:

   // Member vars
   Node *head;
   Node *tail;
   static int length;
};

#endif // ASSIGN2_LINKEDLIST_H