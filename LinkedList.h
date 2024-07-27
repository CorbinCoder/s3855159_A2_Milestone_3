
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
public:
   LinkedList();
   ~LinkedList();

   int getLength();
   void clear();
   int get(int i);

   void addFront(Tile *tile);
   void addBack(Tile *tile);
   void deleteBack();
   void deleteFront();

private:
   Node *head;
   Node *tail;
   int length;
};

#endif // ASSIGN2_LINKEDLIST_H