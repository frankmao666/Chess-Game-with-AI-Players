#include "piece.h"
#include "info.h"
#include "rook.h"
#include <vector>
#include "board.h"


Rook::Rook (Colour colour, Type t, int weight, Coor c, Board * b)
    :Piece{colour, t, weight, c, b} {}


bool Rook::canReach(Coor des) {
    if ((des.row < 0) || (des.row > 7) || (des.col < 0) || (des.col > 7)) return false;
    Coor curr = getInfo().c;
    Colour mycolour = getInfo().colour;
    
    if (((des.row != curr.row) && (des.col != curr.col)) || ((des.row == curr.row) && (des.col == curr.col))) {
        return false;
    }
    
    if ((b->getPiece(des)->getInfo().type != NonPiece) && (b->getPiece(des)->getInfo().colour == mycolour)) {
        return false;
    }
    
    if ((curr.row == des.row) && (curr.col > des.col)) {
        for (int co = curr.col - 1; co > des.col; --co) {
            Coor posi = {curr.row, co};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    }
    
    if ((curr.row == des.row) && (curr.col < des.col)) {
        for (int co = curr.col + 1; co < des.col; ++co) {
            Coor posi = {curr.row, co};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    }
    
    if ((curr.col == des.col) && (curr.row < des.row)) {
        for (int r = curr.row + 1; r < des.row; ++r) {
            Coor posi = {r, curr.col};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    }
    if ((curr.col == des.col) && (curr.row > des.row)) {
        for (int r = curr.row - 1; r > des.row; --r) {
            Coor posi = {r, curr.col};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    }
    return false;
}
std::vector<Coor> Rook::nextMoveList() {
    std::vector<Coor> list;
    Coor curr = getInfo().c;
    Colour mycolour = getInfo().colour;
    for (int r = curr.row-1; r >= 0; --r) {
        Coor pos{r, curr.col};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != mycolour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    for (int r = curr.row+1; r <= 7; ++r) {
        Coor pos{r, curr.col};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos))  list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != mycolour) { // can capture
            if (!checkMyKing(pos))  list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int co = curr.col-1; co >= 0; --co) {
        Coor pos{curr.row, co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != mycolour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int co = curr.col+1; co <= 7; ++co) {
        Coor pos{curr.row, co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != mycolour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    
    return list;
}

