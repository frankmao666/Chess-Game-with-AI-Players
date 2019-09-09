#include "queen.h"
#include "piece.h"
#include "board.h"
#include "info.h"
#include <vector>

Queen::Queen (Colour colour, Type t, int weight, Coor c, Board * b):
    Piece{colour, t, weight, c, b} {}

bool Queen::canReach(Coor des) {
    Coor curr = getInfo().c;
    Colour myColour = getInfo().colour;
    if ((des.row < 0) || (des.row > 7) || (des.col < 0) || (des.col > 7)) return false;
    if ((des.row == curr.row) && (des.col == curr.col)) {
        return false;
    }
    if ((b->getPiece(des)->getInfo().type != NonPiece) && (b->getPiece(des)->getInfo().colour == myColour)) {
        return false;
    }
    
    if ((curr.row > des.row) && (curr.col > des.col)) {
        for (int r = curr.row - 1, co = curr.col - 1; ((r >= des.row) && (co >= des.col)); --r, --co) {
            Coor pos = {r, co};
            if ((b->getPiece(pos)->getInfo().type != NonPiece) && (r > des.row) && (co > des.col)) { // pieces on the path
                return false;
            } else if (((b->getPiece(pos)->getInfo().type == NonPiece) ||
                        (b->getPiece(pos)->getInfo().colour != myColour)) &&
                       ((r == des.row) && (co == des.col))) {
                return true; // the destination has no piece or different colour piece
            } else if ((b->getPiece(pos)->getInfo().type == NonPiece) && ((r > des.row) && (co > des.col))) {
                continue; // on the path, no piece
            }
        }
        return false;
        
    } else if ((curr.row > des.row) && (curr.col < des.col)) {
        for (int r = curr.row - 1, co = curr.col + 1; ((r >= des.row) && (co <= des.col)); --r, ++co) {
            Coor pos = {r, co};
            if ((b->getPiece(pos)->getInfo().type != NonPiece) && ((r > des.row) && (co < des.col))) { // pieces on the path
                return false;
            } else if (((b->getPiece(pos)->getInfo().type == NonPiece) ||
                        (b->getPiece(pos)->getInfo().colour != myColour)) &&
                       ((r == des.row) && (co == des.col))) {
                return true; // the destination has no piece or different colour piece
            } else if ((b->getPiece(pos)->getInfo().type == NonPiece) && ((r > des.row) && (co < des.col))) {
                continue; // on the path, no piece
            }
        }
        return false;
    } else if ((curr.row < des.row) && (curr.col > des.col)) {
        for (int r = curr.row + 1, co = curr.col - 1; ((r <= des.row) && (co >= des.col)); ++r, --co) {
            Coor pos = {r, co};
            if ((b->getPiece(pos)->getInfo().type != NonPiece) && ((r < des.row) && (co > des.col))) { // pieces on the path
                return false;
            } else if (((b->getPiece(pos)->getInfo().type == NonPiece) ||
                        (b->getPiece(pos)->getInfo().colour != myColour)) &&
                       ((r == des.row) && (co == des.col))) {
                return true; // the destination has no piece or different colour piece
            } else if ((b->getPiece(pos)->getInfo().type == NonPiece) && ((r < des.row) && (co > des.col))) {
                continue; // on the path, no piece
            }
        }
        return false;
    } else if ((curr.row < des.row) && (curr.col < des.col)) {
        for (int r = curr.row + 1, co = curr.col + 1; ((r <= des.row) && (co <= des.col)); ++r, ++co) {
            Coor pos = {r, co};
            if ((b->getPiece(pos)->getInfo().type != NonPiece) && ((r < des.row) && (co < des.col))) { // pieces on the path
                return false;
            } else if (((b->getPiece(pos)->getInfo().type == NonPiece) ||
                        (b->getPiece(pos)->getInfo().colour != myColour)) &&
                       ((r == des.row) && (co == des.col))) {
                return true; // the destination has no piece or different colour piece
            } else if ((b->getPiece(pos)->getInfo().type == NonPiece) && ((r < des.row) && (co < des.col))) {
                continue; // on the path, no piece
            }
        }
        return false;
    } else if ((curr.row == des.row) && (curr.col > des.col)) {
        for (int co = curr.col - 1; co > des.col; --co) {
            Coor posi = {curr.row, co};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    } else if ((curr.row == des.row) && (curr.col < des.col)) {
        for (int co = curr.col + 1; co < des.col; ++co) {
            Coor posi = {curr.row, co};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    } else if ((curr.col == des.col) && (curr.row < des.row)) {
        for (int r = curr.row + 1; r < des.row; ++r) {
            Coor posi = {r, curr.col};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    } else if ((curr.col == des.col) && (curr.row > des.row)) {
        for (int r = curr.row - 1; r > des.row; --r) {
            Coor posi = {r, curr.col};
            if (b->getPiece(posi)->getInfo().type != NonPiece) return false; // block the way
        }
        return true;
    }
    return false;
}

std::vector<Coor> Queen::nextMoveList() {
    std::vector<Coor> list;
    Coor curr = getInfo().c;
    Colour myColour = getInfo().colour;
    for (int r = curr.row - 1; r >= 0; --r) {
        Coor pos{r, curr.col};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int r = curr.row + 1; r <= 7; ++r) {
        Coor pos{r, curr.col};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos))  list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos))  list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int co = curr.col - 1; co >= 0; --co) {
        Coor pos{curr.row, co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int co = curr.col + 1; co <= 7; ++co) {
        Coor pos{curr.row, co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break;
    }
    
    for (int r = curr.row - 1, co = curr.col - 1; ((r >= 0) && (co >= 0)); --r, --co) {
        Coor pos{r,co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break; // been blocked
    }
    
    for (int r = curr.row + 1, co = curr.col - 1; ((r <= 7) && (co >= 0)); ++r, --co) {
        Coor pos{r,co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break; // been blocked
    }
    
    for (int r = curr.row + 1, co = curr.col + 1; ((r <= 7) && (co <= 7)); ++r, ++co) {
        Coor pos{r,co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break; // been blocked
    }
    
    for (int r = curr.row - 1, co = curr.col + 1; ((r >= 0) && (co <= 7)); --r, ++co) {
        Coor pos{r,co};
        if (b->getPiece(pos)->getInfo().type == NonPiece) {
            if (!checkMyKing(pos)) list.emplace_back(pos);
        } else if (b->getPiece(pos)->getInfo().colour != myColour) { // can capture
            if (!checkMyKing(pos)) list.emplace_back(pos);
            break;
        } else break; // been blocked
    }
    
    return list;
}


