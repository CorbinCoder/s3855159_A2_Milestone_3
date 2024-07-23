#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "LinkedList.h"
#include "Tile.h"
using std::string;

class Player
{
public:
    string name;
    LinkedList hand;
    int score;
    int position;

    // constructor
    Player(string name, LinkedList hand, int score, int position);

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
    string getName();

    LinkedList getHand();

    int getScore();

    int getPosition();
};

#endif / 