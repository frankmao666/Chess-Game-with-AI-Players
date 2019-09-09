#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "piece.h"

class Queen: public Piece {
    
    public:
    Queen(Colour colour, Type t, int weight, Coor c, Board * b);
    bool canReach(Coor des) override;
    
    std::vector<Coor> nextMoveList() override;
    
};
#endif
