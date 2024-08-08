#include "Node.h"

// Default Constructor
Node::Node()
{
}

// Regular constructor
Node::Node(Tile *tile, Node *next)
{
   this->tile = tile;
   this->next = next;
}

// Copy constructor
Node::Node(Node &other)
{
   this->tile = new Tile(*other.tile);
   this->next = nullptr;
}

Node &Node::operator=(Node &other)
{
   delete this->tile;
   this->tile = new Tile(*other.tile);
   this->next = nullptr;
   return *this;
}

// Destructor
Node::~Node()
{
   delete this->tile;
   // delete this->next;
}

// Return true if next node tile matches colour or shape
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

void Node::clear()
{
   delete this->tile;
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