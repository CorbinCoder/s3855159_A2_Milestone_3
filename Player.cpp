
#include <string>
#include "PLayer.h";
#include "LinkedList.h";
using std::string;

// constructor
Player::Player(string name, LinkedList hand, int score, int position)
{
    this->name = name;
    this->hand = hand;
    this->score = score;
    this->position = position;
}

// Destructor
Player::~Player()
{
    delete[] &this->hand;
}

// Copy Constructor
Player::Player(Player &other)
{
    name = other.name;
    hand = LinkedList(other.hand);
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

void Player::placeTile(Tile selectedTile)
{

    // check tile is in player's hand

    // remove tile from player's hand

    // another function will place it on the board
}

void Player::replaceTile(Tile selectedTile, Tile newTile)
{
    // check tile is in player's hand

    // removes tile from player's hand

    // replaces it with newTile
}

void Player::createHand()
{
    // creates LinkedList and adds 6 random tiles to it
}

// getters and setters
string Player::getName()
{
    return this->name;
}

LinkedList Player::getHand()
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