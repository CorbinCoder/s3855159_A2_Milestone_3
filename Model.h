#ifndef ASSIGN2_MODEL_H
#define ASSIGN2_MODEL_H

#include "Tile.h"
#include "Player.h"
#include "Bag.h"

class Model
{
    public:

    // Constructors

    Model();
    Model(std::string player_1_name, std::string player_2_name);
    Model(Model &other);
    ~Model();

    // Methods

    // Get/Set
    Player getPlayer(int pos);
    Bag getBag();
    void setPlayer(int pos, Player player);
    void setBag(Bag bag);
    // Board getBoard();
    // void setBoard(Board board);


    private:

    // Member vars

    Player player_1 = Player::Player();
    Player player_2 = Player::Player();
    Bag bag;
    // Board board;

};

#endif