#include "Node.h"

// Default Constructor
Node::Node() : next(nullptr)
{
}

// Regular constructor
Node::Node(Tile *tile, Node *next) : tile(tile), next(next)
{
}

// Copy constructor
Node::Node(const Node &other) : tile(other.tile), next(other.next)
{
}

Node &Node::operator=(const Node &other)
{
   this->tile = other.tile;
   this->next = nullptr;
   return *this;
}

// Destructor
Node::~Node()
{
   delete &this->next;
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
   this->tile.reset();
}

// Get/Set
Tile *Node::getTile()
{
   return this->tile.get();
}

void Node::setTile(Tile *tile)
{
   this->tile.reset(tile);
}

Node *Node::getNext()
{
   return this->next.get();
}

void Node::setNext(Node *next)
{
   this->next.reset(next);
}