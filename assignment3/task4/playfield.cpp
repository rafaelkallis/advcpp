
#include "playfield.h"

#include <iostream>

int playfield::stoneat(int x, int y) const { 
    return rep[x][y]; 
}

void playfield_impl::set_stone_in_column(const int &player, const int &x) {
    if(!shared<playfield_impl>::is_valid_column(x)) {
        std::cout << "Given column is not valid!" << std::endl;
    } else if(!shared<playfield_impl>::is_valid_player(player)) {
        std::cout << "Given player is no valid player!" << std::endl;
    } else if(!shared<playfield_impl>::can_set_stone(*this, x)) {
        std::cout << "Cannot set stone in column " << x << ". Column is full." << std::endl;
    } else {
        int i = playfield::height - 1;
        while(stoneat(x, i) != 0) i--;
        rep[x][i] = player;
    }
}