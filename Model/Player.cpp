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
}

Player::Player(std::string name, int handSize, int score, int position)
{
    this->name = name;
    this->hand = new Hand(handSize);
    this->score = score;
    this->position = position;
}




// called when a player types in the command, place {tile} at {position}
Tile *Player::placeTile(Colour colour, Shape shape)
{
    // check tile is in player's hand
    Tile *selectedTile = hand->getTile(colour, shape);

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
void Player::drawHand(Tile* tiles[])
{
    // passes tiles to hand
    for (int i = 0; i < sizeof(&tiles); i++) 
    {
        this->hand->addTile(tiles[i]);
    }
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
