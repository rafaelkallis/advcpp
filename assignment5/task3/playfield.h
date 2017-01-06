#ifndef PLAYFIELD_H_
#define PLAYFIELD_H_

#include "shared.h"

class playfield {
public:
    // the size of the field
    const static int width=7;
    const static int height=6;
    // the elements stored at individual field positions
    const static int none=0;
    const static int player1=1;
    const static int player2=2;

    int stoneat(int x, int y) const;
protected:
	char rep[playfield::width][playfield::height] = {};
};

class playfield_impl : public playfield {
public:
    void set_stone_in_column(const int &player, const int &x);
};

#endif /* PLAYFIELD_H_ */
