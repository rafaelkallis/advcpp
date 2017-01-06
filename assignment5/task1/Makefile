all: test
	rm *.o

test: test.o smart_pointer.o dumb_pointer.o
	g++ test.o dumb_pointer.o -o test

test.o: test.cpp
	g++ -c test.cpp -o test.o

smart_pointer.o: smart_pointer.h
	g++ -c smart_pointer.h -o smart_pointer.o

dumb_pointer.o: dumb_pointer.h
	g++ -c dumb_pointer.h -o dumb_pointer.o

clean:
	rm *.o test