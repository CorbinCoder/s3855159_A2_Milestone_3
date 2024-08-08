#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "Tile.h"
#include "Hand.h"

class Player
{
private:
    std::string name;
    // Hand hand;
    int score;
    // int position;

public:
    // default constructor
    Player();

    // constructor
    // Player(std::string name, Hand hand, int score, int position);

    Player(std::string name);

    // Destructor
    // ~Player();

    // Copy Constructor
    // Player(const Player &other);

    // Move Constructor
    // Player(Player &&other);

    Tile *placeTile(Colour colour, Shape shape);

    void replaceTile(Colour colour, Shape shape, Tile *newTile);

    void drawHand(Tile *tiles[]);

    // getters and setters
    std::string getName();

    void setName(std::string name);

    Hand getHand();

    int getScore();

    int getPosition();
};

#endif // ASSIGN2_PLAYER_H