
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "playfield.h"
#include "shared.h"

template<typename F>
class game {
public:
	game(player<F> *player1, player<F> *player2, F &field);
	void start();
private:
	player<F> *player1;
	player<F> *player2;
	player<F> *current_player;

	F field;

	int current_player_number();
	void change_player();
};

template<typename F>
game<F>::game(player<F> *player1, player<F> *player2, F &field) : player1(player1), player2(player2), field(field), current_player(player1) {}

template<typename F>
int game<F>::current_player_number() {
	return (current_player == player1) ? 1 : 2;
}

template<typename F>
void game<F>::start() {
    while(true) {

        int col = current_player->play(field);
        field.set_stone_in_column(current_player_number(), col);

        if(shared<F>::is_win(field) == current_player_number()) {
			shared<F>::print(field);
            std::cout << "Player " << current_player_number() << " won the game!" << std::endl;
            break;
        }

        if(shared<F>::is_full(field)) {
            shared<F>::print(field);
            std::cout << "Field is full. Draw." << std::endl;
            break;
        }

        change_player();
    }
}

template<typename F>
void game<F>::change_player() {
	current_player = (current_player == player2) ? player1 : player2;
}

#endif