#ifndef _PAWN_H_
#define _PAWN_H_

#include "piece.h"

class Pawn: public Piece {
    bool justForwardTwo = false; // if the piece have just moved forward two
	public:
    Pawn(Colour colour, Type t, int weight, Coor c, Board * b);
	bool ablePromote(); // check if able to promote
    bool checkMoveTwo() override; // return true if *this justForward Two
    void changeMoveTwo(bool t); // the justForwardTwo value
    bool checkPassant(Coor c) override; // return true if the move is en passant
	std::vector<Coor> nextMoveList() override;
    bool canReach(Coor des) override;
};

#endif
