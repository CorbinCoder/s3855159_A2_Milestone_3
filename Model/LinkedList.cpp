
#include "LinkedList.h"

// Default Constructor
LinkedList::LinkedList()
{
   head = nullptr;
   // tail = nullptr;
   length = 0;
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
LinkedList::LinkedList(LinkedList &other)
{
   this->head = nullptr;
   this->tail = nullptr;
   Node *temp = new Node();
   temp = other.head;

   while (temp != nullptr)
   {
      this->addBack(new Tile(*temp->getTile()));
      temp = temp->getNext();
   }
}

// move constructor
LinkedList::LinkedList(LinkedList &&other)
{
   this->head = other.head;
   this->tail = other.tail;
   other.head = nullptr;
   other.tail = nullptr;
}

// move operator
LinkedList &LinkedList::operator=(LinkedList &&other)
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
   return *this;
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

      Node *temp = new Node();
      temp = other.head;

      while (temp != nullptr)
      {
         this->addBack(new Tile(*temp->getTile()));
         temp = temp->getNext();
      }
      // checks that original and copy have same memory address

      // creates new array, copies values and destroys old array
   }
   return *this;
}

// Methods

Tile *LinkedList::find(Colour colour, Shape shape)
{
   Node *temp = new Node();
   temp = this->head;

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
   Node *temp = new Node();
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

   return NULL;
}

void LinkedList::remove(int i)
{
   // find the node at the index
   Node *temp = new Node();
   temp = this->head;

   Node *prev = new Node();

   if (prev != nullptr)
   {
      while (prev != nullptr)
      {

         if (this->length == (i - 1))
         {

            *prev->getNext() = *temp;

            //  link it to next node
            prev->setNext(temp->getNext());

            // delete node
            delete temp;
            // temp->setNext(temp->getNext()->getNext());
         }
         // temp->setNext(temp->getNext());
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
}

void LinkedList::replace(int i, Tile *newTile)
{

   // find the node at the index
   Node *temp = new Node();
   temp = this->head;

   if (temp != nullptr)
   {
      while (temp != nullptr)
      {

         if (this->length == i)
         {
            //  replace it with newNode
            temp->setTile(newTile);
         }
      }
   }
   else
   {
      std::cout << "Error - List is empty" << std::endl;
   }
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
   Node *temp = this->head;
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
      // this->tail = temp;
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
