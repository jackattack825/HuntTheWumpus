CC=g++ -g
EXE_FILE=main
all: $(EXE_FILE)

game.o: game.hpp game.cpp
	$(CC) -c game.cpp

bats.o: bats.hpp bats.cpp
	$(CC) -c bats.cpp

gold.o: gold.hpp gold.cpp
	$(CC) -c gold.cpp

pit.o: pit.hpp pit.cpp
	$(CC) -c pit.cpp

wumpus.o: wumpus.hpp wumpus.cpp
	$(CC) -c wumpus.cpp

room.o: room.hpp room.cpp
	$(CC) -c room.cpp


$(EXE_FILE): game.o game.hpp  bats.o bats.hpp event.hpp gold.o gold.hpp pit.o pit.hpp wumpus.hpp wumpus.o room.hpp room.o main.cpp
	$(CC) game.o bats.o gold.o pit.o wumpus.o room.o main.cpp -o $(EXE_FILE)

