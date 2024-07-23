#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H
#include <string>
#include "LinkedList.h";
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

    // Deconstructor
    ~Player();

    // Copy Constructor
    Player(Player &other);

    // Move Constructor
    Player(Player &&other);

    void placeTile();

    void replaceTile();

    void createHand();

    // getters and setters
    string getName();

    LinkedList getHand();

    int getScore();

    int getPosition();
};

#endif // ASSIGN2_PLAYER_H