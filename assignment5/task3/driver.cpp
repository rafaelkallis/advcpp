
#include "game.h"
#include "player.h"
#include "playfield.h"

int main(){

	numbered_player<playfield_impl> player1(1);
	numbered_player<playfield_impl> player2(2);
	playfield_impl field;

	game<playfield_impl> g(&player1, &player2, field);
	g.start();

	return 0;
}