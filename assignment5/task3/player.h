#ifndef PLAYER_H_
#define PLAYER_H_

#include "playfield.h"
#include "shared.h"
#include <iostream>
#include <vector>

template<typename F>
class player {
public:
    int play(const F &field);
};

template<typename F>
class numbered_player : public player<F> {
public:
    numbered_player(int number);
    int play(const F &field);
protected:
    int find_win_slot(const F &field, const int &player_number);
    int get_number() const;
    int get_enemy_number() const;
private:
    bool is_win_slot(F field, const int &player_number, const int &slot);
    int number;
};

template <typename F>
int player<F>::play(const F &field){
    std::vector<int> possible_slots = shared<F>::get_possible_slots(field);
    int random_possible_slot = possible_slots.at(rand() % possible_slots.size());
    return random_possible_slot;
}

template<typename F>
numbered_player<F>::numbered_player(int number) : number(number) {}

template<typename F>
int numbered_player<F>::get_number() const {
	return number;
}

template<typename F>
int numbered_player<F>::get_enemy_number() const {
	return (number == 1) ? 2 : 1;
}

template <typename F>
int numbered_player<F>::play(const F &field){

    // find winning slot on possible enemy turn
    int win_slot = find_win_slot(field, get_number());

    // find enemy winning slot on possible enemy turn
    int enemy_win_slot = find_win_slot(field, get_enemy_number());

    // random slot on possible enemy turn
    int random_possible_slot = player<F>::play(field);

    // priority order: win_slot, enemy_win_slot, random_possible_slot
     return (win_slot != -1) ? win_slot : (enemy_win_slot != -1) ? enemy_win_slot : random_possible_slot;
}

template <typename F>
int numbered_player<F>::find_win_slot(const F &field, const int &player_number){

    for (int slot : shared<F>::get_possible_slots(field)){
        // found winning slot
        if(is_win_slot(field, player_number, slot)) return slot;
    }
    // no winning slot found
    return -1;
}

template <typename F>
bool numbered_player<F>::is_win_slot(F field, const int &player_number, const int &slot){
    field.set_stone_in_column(player_number, slot);
    return shared<F>::is_win(field) == player_number;
}

#endif /* PLAYER_H_ */
