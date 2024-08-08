#include "Model.h"

Model::Model()
{
    this->bag = Bag();
}

Model::Model(std::string player_1_name, std::string player_2_name, Bag bag) : player_1(player_1_name, 6, 0, 1), player_2(player_2_name, 6, 0, 2)
{
    this->bag = bag;
    // Board board;
}

Model::Model(Model &other) : player_1(other.player_1), player_2(other.player_1), bag(other.bag)
{
}

Model::~Model()
{
    // delete &this->player_1;
    // delete &this->player_2;
    // delete &this->bag;
}

// Methods
void Model::drawHand(int player)
{
    // draws 6 tiles from the bag
    Tile *tiles[6];
    int i = 0;
    while (i < 6)
    {
        Tile *tile = getBag().Draw();
        tiles[i] = tile;
    }

    this->getPlayer(player).drawHand(tiles);
}

// Get/Set
Player Model::getPlayer(int pos)
{
    if (pos = 1)
    {
        return this->player_1;
    }
    else if (pos = 2)
    {
        return this->player_2;
    }
    else
    {
        std::cout << "Error - player position is invalid" << std::endl;
    }
}

Bag Model::getBag()
{
    return this->bag;
}

// Board Model::getBoard()
// {
//     return this->board;
// }

// replaces specifified
void Model::setPlayer(int pos, Player player)
{
    if (pos == 1)
    {
        this->player_1 = player;
    }
    else if (pos == 2)
    {
        this->player_2 = player;
    }
    else
    {
        std::cout << "Error - player position is invalid" << std::endl;
    }
}

void Model::setBag(Bag bag)
{
    this->bag = bag;
}

// void Model::setBoard(Board board)
// {
//     this->board = board;
// }