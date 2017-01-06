
#include "playfield.h"

#include <iostream>

int playfield::stoneat(int x, int y) const { 
    return rep[x][y]; 
}

void playfield_impl::set_stone_in_column(const int &player, const int &x) {
    // if(!shared<playfield>::is_valid_column(*this, x)) {
    //     std::cout << "Given column is not valid!" << std::endl;
    // } else if(!shared<playfield>::is_valid_player(*this, player)) {
    //     std::cout << "Given player is no valid player!" << std::endl;
    // } else if(!shared<playfield>::can_set_stone(*this, x)) {
    //     std::cout << "Cannot set stone in column " << x << ". Column is full." << std::endl;
    // } else {
        int i = playfield::height - 1;
        while(stoneat(x, i) != 0) i--;
        rep[x][i] = player;
    // }
}