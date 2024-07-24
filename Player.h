#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "LinkedList.h"
#include "Tile.h"

class Player
{
private:
    std::string name;
    LinkedList hand;
    int score;
    int position;

public:
    // constructor
    Player(std::string name, LinkedList hand, int score, int position);

    // Destructor
    ~Player();

    // Copy Constructor
    Player(Player &other);

    // Move Constructor
    Player(Player &&other);

    void placeTile(Tile selectedTile);

    void replaceTile(Tile selectedTile, Tile newTile);

    void createHand();

    // getters and setters
    std::string getName();

    LinkedList getHand();

    int getScore();

    int getPosition();
};

#endif // ASSIGN2_PLAYER_H