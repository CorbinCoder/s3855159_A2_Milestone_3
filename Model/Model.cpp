#include "Model.h"

Model::Model()
{
}


Model::Model(std::string player_1_name, std::string player_2_name)
{
    this->player_1 = new Player(player_1_name);
    this->player_2 = new Player(player_2_name);
    this->bag = new Bag(4);
    this->bag->Shuffle();
    this->board = new Board();
}

Model::Model(std::string player_1_name, std::string player_2_name, Bag bag, Board board)
{
    this->player_1 = new Player(player_1_name);
    this->player_2 = new Player(player_2_name);
    this->bag = new Bag(bag);
    this->board = new Board(board);
}

Model::Model(Model &other)
{
    this->player_1 = other.player_1;
    this->player_2 = other.player_2;
    this->bag = other.bag;
    this->board = other.board;
}

Model::~Model()
{
    delete &this->player_1;
    this->player_1 = nullptr;
    delete &this->player_2;
    this->player_2 = nullptr;
    delete &this->bag;
    this->bag = nullptr;
    delete &this->board;
    this->board = nullptr;
}

// Methods
void Model::drawHand(int player)
{
    // draws 6 tiles from the bag
    for (int i = 0; i < this->getPlayer(player)->getHand()->getHandsize(); i++)
    {
        this->getPlayer(player)->getHand()->addTile(this->bag->Draw());
    }
}

// Get/Set
Player *Model::getPlayer(int pos)
{
    if (pos == 1)
    {
        return player_1;
    }

    return player_2;
}

Bag* Model::getBag()
{
    return this->bag;
}

Board* Model::getBoard()
{
    return this->board;
}

// replaces specifified
void Model::setPlayer(int pos, Player player)
{
    if (pos == 1)
    {
        this->player_1 = new Player(player);
    }
    else if (pos == 2)
    {
        this->player_2 = new Player(player);
    }
    else
    {
        std::cout << "Error - player position is invalid" << std::endl;
    }
}



void Model::setBag(Bag bag)
{
    this->bag = new Bag(bag);
}

void Model::setBoard(Board board)
{
    this->board = new Board(board);
}