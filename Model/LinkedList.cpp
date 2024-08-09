
#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0)
{
}

// Destructor
LinkedList::~LinkedList()
{
   // loop through all the nodes?

   while (head != tail)
   {
      this->deleteBack();
   }
   delete head;
}

// Copy constructor
LinkedList::LinkedList(LinkedList &other) : head(nullptr), tail(nullptr)
{

   Node *temp = other.head;

   while (temp != nullptr)
   {
      this->addBack(new Tile(*(temp->getTile())));
      temp = temp->getNext();
   }
}
// copy assignment operator
LinkedList &LinkedList::operator=(LinkedList &other)
{
   if (this != &other)
   {

      // delete all the nodes
      while (head != tail)
      {
         this->deleteBack();
      }
      delete head;
      this->head = nullptr;
      this->tail = nullptr;

      // reinstate all the nodes

      Node *temp = other.head;

      while (temp != nullptr)
      {
         this->addBack(new Tile(*(temp->getTile())));
         temp = temp->getNext();
      }
      // checks that original and copy have same memory address

      // creates new array, copies values and destroys old array
   }
   return *this;
}
// move constructor
LinkedList::LinkedList(LinkedList &&other) noexcept
    : head(other.head), tail(other.tail)
{
   other.head = nullptr;
   other.tail = nullptr;
}

// move operator
LinkedList &LinkedList::operator=(LinkedList &&other) noexcept
{
   if (this != &other)
   {
      while (head != tail)
      {
         this->deleteBack();
      }
      delete head;

      this->head = other.head;
      this->tail = other.tail;
      other.head = nullptr;
      other.tail = nullptr;
   }
   return *this;
}

// Methods

Tile *LinkedList::find(Colour colour, Shape shape)
{
   Node *temp = this->head;

   if (temp != nullptr)
   {
      while (temp != nullptr)
      {
         if (temp->getTile()->getColour() == colour && temp->getTile()->getShape() == shape)
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

   return NULL;
}

Tile *LinkedList::at(int i)
{
   // create node to loop through nodes
   Node *temp = this->head;
   for (int j = 0; j < i && temp != nullptr; ++j)
   {
      temp = temp->getNext();
   }

   if (temp == nullptr)
   {

      std::cout << "Error - List is empty" << std::endl;
      return nullptr;
   }

   return temp->getTile();
}

void LinkedList::remove(int i)
{
   if (i == 0)
   {
      this->deleteFront();
      return;
   }
   if (i == length - 1)
   {
      this->deleteBack();
      return;
   }
   Node *previous = this->head;

   for (int j = 0; j < (i - 1) && previous != nullptr; ++j)
   {
      previous = previous->getNext();
   }
   if (previous != nullptr)
   {
      Node *temp = previous->getNext();
      previous->setNext(temp->getNext());
      delete temp;
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
}

void LinkedList::replace(int i, Tile *newTile)
{

   // find the node at the index
   Node *temp = this->head;
   for (int j = 0; j < i && temp != nullptr; ++j)
   {
      temp = temp->getNext();
   }

   if (temp == nullptr)
   {

      std::cout << "Error - List is empty" << std::endl;
      return;
   }
   temp->setTile(newTile);
}

void LinkedList::printAll()
{
   Node *temp = new Node();
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
   while (head != tail)
   {
      this->deleteBack();
   }
   delete head;
   head = nullptr;
   tail = nullptr;
}

// Get/Set
int LinkedList::size()
{
   return this->length;
}

// Add node to first position (takes ownership of ptr)
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
   if (head == nullptr)
   {
      std::cout << "List is empty";
      return;
   }
   else if (head == tail)
   {
      delete head;
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

// Add node to end position (takes ownership of ptr)
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
   else if (head == tail)
   {
      delete head;
      this->head = nullptr;
      this->tail = nullptr;
      length--;
   }
   else
   {
      Node *temp = head;

      while (temp->getNext() != tail)
      {
         temp = temp->getNext();
      }

      delete tail;
      // temp->getNext() == nullptr; // Redundant - Add your logic for this comparison
      tail = temp;
      length--;
   }
}

Tile *LinkedList::getFront()
{
   return this->head->getTile();
}

void LinkedList::setFront(Tile *tile)
{
   this->head->setTile(tile);
}

Tile *LinkedList::getBack()
{
   return this->tail->getTile();
}

void LinkedList::setBack(Tile *tile)
{
   this->tail->setTile(tile);
}

Node *LinkedList::getHead()
{
   return this->head;
}

Node *LinkedList::getTail()
{
   return this->tail;
}
