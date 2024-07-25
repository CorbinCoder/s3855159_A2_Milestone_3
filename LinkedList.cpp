
#include "LinkedList.h"

//Constructors
LinkedList::LinkedList() {
   head = nullptr;
   tail = nullptr;

   // TODO
}

LinkedList::~LinkedList() 
{
   delete head;
   delete tail;
}

// Methods
void LinkedList::addFront(Tile* tile)
{
   Node* temp = new Node();
   temp->setTile(tile);
   temp->setNext(nullptr);

   if (head == nullptr)
   {
      this->head = temp;
      this->tail = temp;
      length++;
   }
   else
   {
      temp->setNext(head);
      head = temp;
      length++;
   }
}

void LinkedList::removeFront()
{
   if (head = nullptr)
   {
      std::cout << "List is empty";
      return;
   }
   else if (head == tail)
   {
      head = nullptr;
      tail = nullptr;
      length--;
   }
   else
   {
      Node* temp = head;
      head = head->getNext();
      delete temp;
   }
}

void LinkedList::addEnd(Tile* tile)
{
   Node* temp = new Node();
   temp->setTile(tile);
   temp->setNext(nullptr);

   if (head == nullptr)
   {
      this->head = temp;
      this->tail = temp;
      length++;
   }
   else
   {
      this->tail->setNext(temp);
      this->tail = temp;
      length++;
   }
}

void LinkedList::removeEnd()
{
   if (head == nullptr)
   {
      return;
   }
   else
   {
      Node* temp = head;

      while (temp->getNext() != tail) 
      {
         temp = temp->getNext();
      }

      delete tail;
      temp->getNext() == nullptr;
      tail = temp;
      length--;
   }
}

int LinkedList::getLength()
{
   return this->length;
}
