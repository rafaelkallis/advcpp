all: playfield.o shared.o

playfield.o: playfield.cpp playfield.h
	g++ -c playfield.cpp -o playfield.o

shared.o: shared.h
	g++ -c shared.h -o shared.o

clean:
	rm *.o