
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

// Deconstructor
Player::~Player()
{
}

// Copy Constructor
Player::Player(Player &other)
{
}

// Move Constructor
Player::Player(Player &&other)
{
}

void Player::placeTile()
{
}

void Player::replaceTile()
{
}

void Player::createHand()
{
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
