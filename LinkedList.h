
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int getLength();
   void addEnd(Tile* tile);
   void removeEnd();
   void addFront(Tile* tile);
   void removeFront();

private:
   Node* head;
   Node* tail;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H