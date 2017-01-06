all:

assembly: snippets_1.s snippets_2.s swap_1.s swap_2.s

snippets_1.s: snippets_1.cpp
	g++ -c -S snippets_1.cpp -o snippets_1.s

snippets_2.s: snippets_2.cpp
	g++ -c -S snippets_2.cpp -o snippets_2.s

swap_1.s: swap_1.cpp
	g++ -c -S swap_1.cpp -o swap_1.s

swap_2.s: swap_2.cpp
	g++ -c -S swap_2.cpp -o swap_2.s

clean:
	rm *.s