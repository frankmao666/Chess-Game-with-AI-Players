#include "player.h"
#include "info.h"
#include "game.h"
Player::Player(int level, Colour colour, Game * g): level{level}, side{colour}, g{g} {}

void Player::addScore(int s) { score = score + s; }

int Player::getScore() { return score; }

Player& Player::getOpp() {//get oppnoent
    return *(side == Colour::White ? g->bPlayer : g->wPlayer);
}
Colour Player::getOpc() {//get opposite colour
    return side == Colour::White ? Colour::Black : Colour::White;
}
