#include "Model.h"

Model::Model()
{
    this->bag = Bag(4);
}

Model::Model(std::string player_1_name, std::string player_2_name, Bag bag)
{
    this->player_1.init(player_1_name, new Hand(6), 0, 1);
    this->player_2.init(player_2_name, new Hand(6), 0, 2);
    this->bag = bag;
    // Board board;
}

Model::Model(Model &other)
{
    this->player_1.init(other.player_1.getName(), other.player_1.getHand(),
                        other.player_1.getScore(), other.player_1.getPosition());
    this->player_2.init(other.player_2.getName(), other.player_2.getHand(),
                        other.player_2.getScore(), other.player_2.getPosition());
    this->bag = Bag(other.bag);
}

Model::~Model()
{
    delete &this->player_1;
    delete &this->player_2;
    delete &this->bag;
}

// Methods
void Model::drawHand(int player)
{
    // this->getPlayer(player).drawHand();
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

void Model::setPlayer(int pos, Player player)
{
    if (pos = 1)
    {
        this->player_1.init(player.getName(), player.getHand(),
                            player.getScore(), player.getPosition());
    }
    else if (pos = 2)
    {
        this->player_2.init(player.getName(), player.getHand(),
                            player.getScore(), player.getPosition());
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