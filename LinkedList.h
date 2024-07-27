
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
   public:

   // Contructo(s)/Destructor
   LinkedList();
   ~LinkedList();

   // Methods
   int getLength();
   void clear();
   int get(int i);

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
   int length;

};

#endif // ASSIGN2_LINKEDLIST_H