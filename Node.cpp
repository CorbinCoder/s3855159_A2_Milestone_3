#include "Node.h"

// Default Constructor
Node::Node()
{
}

// regular constructor
Node::Node(Tile *tile, Node *next)
{
   this->tile = tile;
   this->next = next;
}

// copy constructor
Node::Node(Node &other)
{
   this->tile = other.tile;
   this->next = other.next;
}

// deconstructor
Node::~Node()
{
   delete this->tile;
   delete this->next;
}

// checks whether the next node matches either in colour of shape
bool Node::checkNextMatch()
{
   if (this->tile->getColour() == next->getTile()->getColour() || this->tile->getShape() == next->getTile()->getShape())
   {
      return true;
   }
   else
   {
      return false;
   }
}

// Get/Set
Tile *Node::getTile()
{
   return this->tile;
}

void Node::setTile(Tile *tile)
{
   this->tile = tile;
}

Node *Node::getNext()
{
   return this->next;
}

void Node::setNext(Node *next)
{
   this->next = next;
}