#include "pawn.h"
#include "piece.h"
#include "board.h"
#include "info.h"
#include <vector>

static const int first_r = 0;
static const int last_r = 7;

Pawn::Pawn (Colour colour, Type t, int weight, Coor c, Board * b):
    Piece{colour, t, weight, c, b} {}


bool Pawn::checkMoveTwo() {
    return justForwardTwo;
}


bool Pawn::ablePromote() {
    Colour myColour = getInfo().colour;
    Coor curr = getInfo().c;
    if (myColour == Colour::White) {
        if (curr.row == first_r) return true;
    } else if (myColour == Colour::Black) {
        if (curr.row == last_r) return true;
    }
    return false;
}

bool Pawn::checkPassant (Coor c) {
    Colour myColour = getInfo().colour;
    Coor curr = getInfo().c;
    if (myColour == Colour::White) {
        if (((c.col == curr.col - 1) || (c.col == curr.col + 1)) &&
            (c.row == curr.row - 1)) {
            Coor pos = {c.row + 1, c.col};
            if ((b->getPiece(pos)->getInfo().colour == Colour::Black) && (b->getPiece(pos)->checkMoveTwo() == true))
                
                return true;
        }
        return false;
    }
    if (myColour == Colour::Black) {
        if (((c.col == curr.col - 1) || (c.col == curr.col + 1)) &&
            (c.row == curr.row + 1)) {
            Coor pos = {c.row - 1, c.col};
            if ((b->getPiece(pos)->getInfo().colour == Colour::White) && (b->getPiece(pos)->checkMoveTwo() == true))
                return true;
        }
        return false;
    }
    return false;
}

void Pawn::changeMoveTwo(bool t) {
    justForwardTwo = t;
}

bool Pawn::canReach(Coor des) {
    if ((des.row < 0) || (des.col < 0) || (des.row > 7) || (des.col > 7)) return false;
    Colour myColour = getInfo().colour;
    Coor curr = getInfo().c;
    if (checkPassant(des) == true) return true;
    if (myColour == Colour::White) {
        if ((!move) && (des.col == curr.col) && (des.row == curr.row - 2) &&
            (b->getPiece(des)->getInfo().type == NonPiece)) {
            return true;
        }
        if ((des.col == curr.col) && (des.row == curr.row - 1) &&
            (b->getPiece(des)->getInfo().type == NonPiece)) {
            return true;
        }
        if ((((des.col == curr.col - 1) || (des.col == curr.col + 1)) &&
            (des.row == curr.row - 1)) && (b->getPiece(des)->getInfo().colour == Colour::Black)) {
            return true;
        }
        return false;
    }
    if (myColour == Colour::Black) {
        if ((!move) && (des.col == curr.col) && (des.row == curr.row + 2) &&
            (b->getPiece(des)->getInfo().type == NonPiece)) {
            return true;
        }

        if ((des.col == curr.col) && (des.row == curr.row + 1) &&
            (b->getPiece(des)->getInfo().type == NonPiece)) {
            return true;
        }
        if (((des.col == curr.col - 1) || (des.col == curr.col + 1)) &&
            (des.row == curr.row + 1) && (b->getPiece(des)->getInfo().colour == Colour::White)) {
            return true;
        }
        return false;
    }
    return false;
}

std::vector<Coor> Pawn::nextMoveList() {
    std::vector<Coor> list;
    Colour myColour = getInfo().colour;
    Coor c = getInfo().c;
    if (myColour == Colour::White) {
        Coor pos1 = {c.row - 1, c.col};
        Coor pos2 = {c.row - 1, c.col + 1};
        Coor pos3 = {c.row - 1, c.col - 1};
        Coor pos4 = {c.row - 2, c.col};
        if (validMove(pos1)) list.emplace_back(pos1);
        if (validMove(pos2)) list.emplace_back(pos2);
        if (validMove(pos3)) list.emplace_back(pos3);
        if (validMove(pos4)) list.emplace_back(pos4);
    } else if (myColour == Colour::Black) {
        Coor pos1 = {c.row + 1, c.col};
        Coor pos2 = {c.row + 1, c.col + 1};
        Coor pos3 = {c.row + 1, c.col - 1};
        Coor pos4 = {c.row + 2, c.col};
        if (validMove(pos1)) list.emplace_back(pos1);
        if (validMove(pos2)) list.emplace_back(pos2);
        if (validMove(pos3)) list.emplace_back(pos3);
        if (validMove(pos4)) list.emplace_back(pos4);
    }
    return list;
}
