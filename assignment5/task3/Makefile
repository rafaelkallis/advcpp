all: driver
	rm *.o

driver: driver.o game.o shared.o player.o playfield.o
	g++ driver.o game.o shared.o player.o playfield.o -o driver

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

game.o: game.h
	g++ -c game.h -o game.o

shared.o: shared.h
	g++ -c shared.h -o shared.o

player.o: player.h
	g++ -c player.h -o player.o

playfield.o: playfield.cpp playfield.h
	g++ -c playfield.cpp -o playfield.o

clean:
	rm *.o driver