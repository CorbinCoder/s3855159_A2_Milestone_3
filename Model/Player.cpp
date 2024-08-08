#include "Player.h"
#include "LinkedList.h"

// default constructor
Player::Player()
{
}

// constructor
Player::Player(std::string name, Hand* hand, int score, int position)
{
    this->name = name;
    this->hand = hand;
    this->score = score;
    this->position = position;
}

// Destructor
Player::~Player()
{
    delete &this->name;
    delete &this->hand;
    delete &this->score;
    delete &this->position;
    delete[] &this->hand; // this->hand is a class instance of LinkedList, not a pointer
}

// Copy Constructor
Player::Player(Player &other)
{
    name = other.name;
    hand = other.hand;
    score = other.score;
    position = other.position;
}

// Move Constructor
// run when std::move is used
Player::Player(Player &&other)
{
    name = other.name;
    hand = other.hand;
    score = other.score;
    position = other.position;
}

// Player &Player::operator=(Player &other)
// {

//     // checks that original and copy have same memory address
//     if (this != &other)
//     {
//         // creates new array, copies values and destroys old array
//         Node **newNodes = new Node *[other.capacity];
//         for (int i = 0; i < other.length; ++i)
//         {
//             newNodes[i] = new Node(*(other.nodes[i]));
//         }
//         for (int j = 0; j < length; j++)
//         {
//             delete nodes[j];
//             nodes[j] = nullptr;
//         }
//         delete[] nodes;
//         nodes = newNodes;
//         capacity = other.capacity;
//         length = other.length;
//     }
//     return *this;
// }

// Used to initialize player data after instance
// is initialized
void Player::init(std::string name, Hand* hand, int score, int position)
{
    this->name = name;
    this->hand = hand;
    this->score = score;
    this->position = position;
}

// called when a player types in the command, place {tile} at {position}
Tile *Player::placeTile(Colour colour, Shape shape)
{

    // check tile is in player's hand
    Tile *selectedTile = this->hand->getTile(colour, shape);

    if (selectedTile != nullptr)
    {
        // remove tile from player's hand
        this->hand->removeTile(selectedTile);
    }

    // another function will place it on the board

    return selectedTile;
}

void Player::replaceTile(Colour colour, Shape shape, Tile *newTile)
{
    placeTile(colour, shape);

    // replaces it with newTile
    this->hand->setTile(colour, shape, newTile);
}

// array length meant to be 6 but left indefined in case of updates to rules in milestone 3
void Player::drawHand(Tile *tiles[])
{
    // passes tiles to hand
    this->hand->drawHand(tiles);
}

// getters and setters
std::string Player::getName()
{
    return this->name;
}

void Player::setName(std::string name)
{
    this->name = name;
}

Hand* Player::getHand()
{
    return this->hand;
}

int Player::getScore()
{
    return this->score;
}

int Player::getPosition()
{
    return this->position;
}