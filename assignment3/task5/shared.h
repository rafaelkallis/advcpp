
#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <vector>

template<typename F>
class shared {
public:
	static bool is_full(const F &field);
	static bool can_set_stone(const F &field, int x);
	static void print_field(const F &field);
	static int is_win(const F &field);
	static bool is_valid_player(int player);
	static bool is_valid_column(int x);
	static bool is_valid_row(int y);
	static std::vector<int> get_possible_slots(const F &field);
protected:
	static bool is_win_helper(const F &field, const int &player, const int &x, const int &y, const int &dx, const int &dy);
};

template<typename F>
bool shared<F>::is_full(const F &field){
	for(int x = 0; x < F::width; x++)
        if(can_set_stone(x)) return false;
    return true;
}

template<typename F>
bool shared<F>::can_set_stone(const F &field, int x){
	return !field.stoneat(x, 0);
}

template<typename F>
void shared<F>::print_field(const F &field){
	std::cout << std::endl;
    for(int p = 0; p < F::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int y = 0; y < F::height; y++) {
        for(int x = 0; x < F::width; x++) {
            int sp = field.stoneat(x, y);
            char ch;
            switch(sp) {
                case F::player1:
                    ch = 'X';
                    break;
                case F::player2:
                    ch = 'O';
                    break;
                default:
                    ch = ' ';
                    break;
            }
            std::cout << "|" << " " << ch << " " << "|";
        }
        std::cout << std::endl;
    }

    for(int p = 0; p < F::width; p++) {
        std::cout << "-----";
    }
    std::cout << std::endl;
    for(int p = 0; p < F::width; p++) {
        std::cout << "  " << (char)('A' + p) << "  ";
    }
    std::cout << std::endl;
}

template<typename F>
int shared<F>::is_win(const F &field){

	for (int x = 0; x < F::width; ++x){
		for (int y = 0; y < F::height; ++y){
			bool win = false;
			win = win || is_win_helper(field, F::player1, x, y,  1, 0);
			win = win || is_win_helper(field, F::player1, x, y,  0, 1);
			win = win || is_win_helper(field, F::player1, x, y,  1, 1);
			win = win || is_win_helper(field, F::player1, x, y, -1, 1);
			if (win) return F::player1;
		}
	}

	for (int x = 0; x < F::width; ++x){
		for (int y = 0; y < F::height; ++y){
			bool win = false;
			win = win || is_win_helper(field, F::player2, x, y,  1, 0);
			win = win || is_win_helper(field, F::player2, x, y,  0, 1);
			win = win || is_win_helper(field, F::player2, x, y,  1, 1);
			win = win || is_win_helper(field, F::player2, x, y, -1, 1);
			if (win) return F::player2;
		}
	}

	return -1;
}

template<typename F>
bool shared<F>::is_win_helper(const F &field, const int &player, const int &x, const int &y, const int &dx, const int &dy){
	if(!is_valid_column(x)) return false;
    if(!is_valid_row(y)) return false;

    int same = 0;
    bool inverted = false;

    for(int i = 0; i < 4; i++) {
        int xx = inverted ? x - (i * dx) : x + (i * dx);
        int yy = inverted ? y - (i * dy) : y + (i * dy);

        bool found = is_valid_column(xx) && is_valid_row(yy) && field.stoneat(xx, yy) == player;

        if(found)
            if(++same == 4) return true;

        if(!inverted && (i == 3 || !found)) {
            i = 0;
            inverted = true;
            continue;
        }

        if(!found) break;
    }

    return same >= 4;
}

template<typename F>
bool shared<F>::is_valid_player(int player){
	return player == F::none 
        || player == F::player1
        || player == F::player2;
}

template<typename F>
bool shared<F>::is_valid_column(int x){
	return x >= 0 && x < F::width;
}

template<typename F>
bool shared<F>::is_valid_row(int y){
	return y >= 0 && y < F::height;
}

template<typename F>
std::vector<int> shared<F>::get_possible_slots(const F &field){
	std::vector<int> possible_slots;
    for(int x = 0; x < F::width; x++) {
        if(can_set_stone(field, x)) possible_slots.push_back(x);
    }
    return possible_slots;
}

#endif