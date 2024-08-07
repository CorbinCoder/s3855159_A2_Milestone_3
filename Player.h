#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "Tile.h"
#include "Hand.h"

class Player
{
private:
    std::string name;
    Hand hand;
    int score;
    int position;

public:
    // default constructor
    Player();

    // constructor
    Player(std::string name, Hand hand, int score, int position);

    // Destructor
    ~Player();

    // Copy Constructor
    Player(Player &other);

    // Move Constructor
    Player(Player &&other);

    void init(std::string name, Hand hand, int score, int position);

    Tile *placeTile(Colour colour, Shape shape);

    void replaceTile(Colour colour, Shape shape, Tile newTile);

    void createHand();

    // getters and setters
    std::string getName();

    Hand getHand();

    int getScore();

    int getPosition();
};

#endif // ASSIGN2_PLAYER_H