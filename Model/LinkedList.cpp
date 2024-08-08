
#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;
}

// Destructor
LinkedList::~LinkedList()
{
   delete head;
   delete tail;
}

// Methods

Tile* LinkedList::find(Colour colour, Shape shape)
{
   Node* temp = new Node();
   temp = this->head;

   if (temp != nullptr)
   {
      while (temp != nullptr)
      {
         if (temp->getTile()->getColour() == colour
         && temp->getTile()->getShape() == shape)
         {
            return temp->getTile();
         }
         temp->setNext(temp->getNext());
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
   return nullptr;
}

Tile* LinkedList::at(int i)
{
   Node* temp = new Node();
   temp = this->head;

   if (temp != nullptr)
   {
      while (temp != nullptr)
      {
         if (i == this->length)
         {
            return temp->getTile();
         }
         temp->setNext(temp->getNext());
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
   return nullptr;
}

void LinkedList::remove(int i)
{

   Node* temp = new Node();
   temp = this->head;

   if (temp != nullptr)
   {
      while (temp != nullptr)
      {
         if (this->length == i)
         {

            Node* prev = temp;
            temp->setNext(temp->getNext()->getNext());
         }
         temp->setNext(temp->getNext());
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
}

void LinkedList::printAll()
{
   Node* temp = new Node();
   temp = this->head;
   int i = 0;

   if (temp != nullptr)
   {
      while (temp != nullptr && i <= this->length)
      {
         std::cout << "Node #" << i 
                     << " Colour: " << this->at(i)->getColour()
                     << " Shape: " << this->at(i)->getShape();
         temp->setNext(temp->getNext());
         i++;
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
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
int LinkedList::size()
{
   return this->length;
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