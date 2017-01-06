all: shared.o player.o playfield.o

shared.o: shared.h
	g++ -c shared.h -o shared.o

player.o: player.h
	g++ -c player.h -o player.o

playfield.o: playfield.cpp playfield.h
	g++ -c playfield.cpp -o playfield.o

clean:
	rm *.o