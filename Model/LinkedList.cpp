
#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;

   // TODO
}

// Destructor
LinkedList::~LinkedList()
{
   delete head;
   delete tail;
}

// Add node to first position
void LinkedList::addFront(Tile *tile)
{
   Node *temp = new Node();
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

// Delete the first node
void LinkedList::deleteFront()
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
      Node *temp = head;
      head = head->getNext();
      delete temp;
   }
}

// Add node to end position
void LinkedList::addBack(Tile *tile)
{
   Node *temp = new Node();
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

// Delete the end node
void LinkedList::deleteBack()
{
   if (head == nullptr)
   {
      return;
   }
   else
   {
      Node *temp = head;

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

// Clear contents of LinkedList
void LinkedList::clear()
{
   Node* temp = this->head;
   head = head->getNext();
   delete temp;
}

// Get/Set
int LinkedList::getLength()
{
   return this->length;
}

Tile* LinkedList::getFront()
{
   return this->head->getTile();
}

void LinkedList::setFront(Tile* tile)
{
   this->head->setTile(tile);
}

Tile* LinkedList::getBack()
{
   return this->tail->getTile();
}

void LinkedList::setBack(Tile* tile)
{
   this->tail->setTile(tile);
}

Node* LinkedList::getHead()
{
   return this->head;
}

Node* LinkedList::getTail()
{
   return this->tail;
}