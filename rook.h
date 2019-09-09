#ifndef _ROOK_H_
#define _ROOK_H_

#include "piece.h"

class Rook: public Piece {
    
    protected:
    
    // std::vector<Coor> MoveList() const override;
    
    public:
    Rook(Colour colour, Type t, int weight, Coor c, Board * b);
    bool canReach(Coor des) override;
    std::vector<Coor> nextMoveList() override;
    
};

#endif
