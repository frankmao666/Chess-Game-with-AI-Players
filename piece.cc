#include "piece.h"
#include "info.h"
#include "board.h"
#include <memory>


using namespace std;

Piece::Piece(Colour colour, Type t, int weight, Coor c, Board * b): info{colour, t, c, weight} {
    this->b = b;
}

Piece::Piece(const Piece & other):info{other.getInfo()} {
    this->b = other.b;
}

Info Piece::getInfo() const {
    return info;
}

void Piece::incMove() {
    ++move;
}

void Piece::decMove() {
    if (move > 0) --move;
}

bool Piece::checkMoved() { return (move > 0); }

bool Piece::checkMoveTwo() {
    return false;
}

bool Piece::checkMyKing(Coor des) {
    return b->checkMyKing(getInfo().c, des);
}


bool Piece::canReach(Coor des) {
    return false;
}

std::vector<Coor> Piece::nextMoveList() {
    std::vector <Coor> lis;
    return lis;
}
std::vector<Coor> Piece::assumeMoveList(Coor assume) {
    Coor original = info.c;
    info.c = assume;
    auto ret = nextMoveList();
    info.c = original;
    return ret;
}
bool Piece::validMove(Coor des) {
    if (!canReach(des)) return false;
    if (checkMyKing(des)) return false; // king is in check after moving
    else return true;
}

void Piece::setPosn(Coor c) {
    info.c = c;
}

bool Piece::checkCastle(Coor des) { return false; }

bool Piece::checkPassant(Coor c) { return false; }

