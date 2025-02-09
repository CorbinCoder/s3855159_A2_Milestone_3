#ifndef ASSIGN2_MODEL_H
#define ASSIGN2_MODEL_H

#include "Tile.h"
#include "Player.h"
#include "Bag.h"
#include "Board.h"

class Model
{
public:
    // Constructor(s)/destructor

    Model();
    Model(std::string player_1_name, std::string player_2_name);
    Model(std::string player_1_name, std::string player_2_name, Bag bag, Board board);
    Model(Model &other);
    ~Model();

    // Methods
    void drawHand(int player); // Draw a hand of tiles for a given player

    // Get/Set
    Player* getPlayer(int pos);
    Bag* getBag();
    void setPlayer(int pos, Player player);
    void setBag(Bag bag);
    Board getBoard();
    void setBoard(Board board);

private:
    // Member vars

    Player* player_1;
    Player* player_2;
    Bag* bag;
    Board* board;
};

#endif