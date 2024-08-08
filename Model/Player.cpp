#include "Player.h"
#include "LinkedList.h"

// default constructor
Player::Player()
{
}

Player::Player(std::string name)
{
    this->name = name;
    this->score = 0;
    // this->hand = Hand();
    // this->position = 0;
}

// constructor

// Destructor
// Player::~Player()
// {
//     delete &this->name;
//     delete &this->hand;
//     delete &this->score;
//     delete &this->position;
// delete[] &this->hand; // this->hand is a class instance of LinkedList, not a pointer
//}

// Copy Constructor
// Player::Player(const Player &other)
// {
//     name = other.name;
//     hand = Hand(other.hand);
//     score = other.score;
//     position = other.position;
// }

// Move Constructor
// run when std::move is used
// Player::Player(Player &&other)
// {
//     name = other.name;
//     hand = Hand(other.hand);
//     score = other.score;
//     position = other.position;
// }

// Used to initialize player data after instance
// is initialized
// void Player::init(std::string name, int score, int position, int handSize)
// {
//     this->name = name;
//     this->hand = Hand();
//     this->score = score;
//     this->position = position;
// }

// called when a player types in the command, place {tile} at {position}
Tile *Player::placeTile(Colour colour, Shape shape)
{

    // check tile is in player's hand
    // Tile *selectedTile = hand.getTile(colour, shape);

    // if (selectedTile != nullptr)
    // {
    //     // remove tile from player's hand
    //     hand.removeTile(selectedTile);
    // }

    // another function will place it on the board

    // return selectedTile;
}

void Player::replaceTile(Colour colour, Shape shape, Tile *newTile)
{
    placeTile(colour, shape);

    // replaces it with newTile
    // hand.setTile(colour, shape, newTile);
}

// array length meant to be 6 but left indefined in case of updates to rules in milestone 3
void Player::drawHand(Tile *tiles[])
{
    // passes tiles to hand
    // hand.drawHand(tiles);
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

// Hand Player::getHand()
// {
//     return this->hand;
// }

int Player::getScore()
{
    return this->score;
}
