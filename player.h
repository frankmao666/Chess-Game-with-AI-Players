#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "info.h"
#include "coor.h"

class Game;

class Player {
    protected:
    int level = 0;
	Colour side;
    int score = 0;
    Game * g = nullptr;
    Player& getOpp();
    Colour getOpc();
    public:
    Player(int level, Colour colour, Game * g);
    void addScore(int s);
    int getScore();
    virtual void goMove(Coor& src, Coor& dest) = 0;
};

#endif

