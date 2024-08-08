.default: all
 
all: qwirkle
 
clean:
	rm -rf qwirkle *.o *.dSYM
 
qwirkle:
	g++ -std=c++14 -O0 -g Model/Bag.cpp Model/Board.cpp Model/Hand.cpp Model/LinkedList.cpp Model/Model.cpp Model/Node.cpp Model/Player.cpp Model/Tile.cpp Program/Controller.cpp Program/qwirkle.cpp Program/View.cpp Utilities/FileHandler.cpp Utilities/GetInput.cpp Utilities/TileCodes.h -o qwirkle

 