#include "Bag.h"
#include "TileCodes.h"
#include <vector>

// Default constructor
Bag::Bag(int numeach)
{
    New(numeach);
}

// Copy constructor
Bag::Bag(Bag &other)
{
    this->tiles = other.tiles;
}

// Destructor
Bag::~Bag()
{
    delete tiles;
}

// Create a new bag - set number of each tile
void Bag::New(int numeach)
{
    char colours[6] {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    char shapes[6] {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

    for (int i = 0; i < sizeof(colours); i++)
    {
        for (int j = 0; j < sizeof(shapes); j++)
        {
            for (int i = 0; i < numeach; i++)
            {
                tiles->addFront(new Tile(colours[i], shapes[j]));
            }
        }
    }
}

// Shuffle the bag - randomises tile order
void Bag::Shuffle()
{
    for (int i = 0; i < this->tiles->getLength(); i++)
    {
        Node *ptr = tiles->getHead();
        Node* prev = nullptr;

        while (ptr && ptr->getNext())
        {
            if (std::rand() % 1000 / 1000.0 < 0.25)
            {
                prev->setNext(ptr->getNext());
                Node *temp = ptr->getNext()->getNext();
                ptr->getNext()->setNext(ptr);
                ptr->setNext(temp);
            }
            prev = ptr;
            ptr = ptr->getNext();
        }
    }
}

// Draw a tile from the bag - draws from the top
Tile* Bag::Draw()
{
    Tile* temp = this->tiles->getFront();

    this->tiles->deleteFront();

    return temp;
};