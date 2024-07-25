#include "Node.h"

//Constructors
Node::Node()
{

}

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
}

Node::Node(Node& other)
{
   this->tile = other.tile;
   this->next = other.next;
}

Node::~Node()
{
   delete this->tile;
   delete this->next;
}

bool Node::checkNextMatch()
{
   if (this->tile->getColour() == next->getTile()->getColour() 
      || this->tile->getShape() == next->getTile()->getShape())
      {
         return true;
      }
      else
      {
         return false;
      }
}

// Get/Set
Tile* Node::getTile() 
{
   return this->tile;
}

void Node::setTile(Tile* tile)
{
   this->tile = tile;
}

Node* Node::getNext()
{
   return this->next;
}

void Node::setNext(Node* next)
{
   this->next = next;
}