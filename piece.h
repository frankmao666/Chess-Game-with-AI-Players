#ifndef _PIECE_H_
#define _PIECE_H_

#include <vector>
#include "coor.h"
#include "info.h"

class Board;

class Piece {
    
    protected:
    int move = 0;
    Info info;
    Board * b;
    bool checkMyKing(Coor des); // return true if move to des will make my king in check
    
    
	public:
    
    Piece(Colour colour, Type t, int weight, Coor c, Board * b);
    ~Piece() { b = nullptr; }
    Piece(const Piece & other); 
    Info getInfo() const;
    bool validMove(Coor des); // check if *this can move to c
    void incMove(); // increase move by one
    void decMove(); // decrease move by one
    void setPosn(Coor c);
    virtual bool checkMoved();
    virtual bool checkMoveTwo();
    virtual bool canReach(Coor des); // return true if the piece can move to des without considering
                                               // make the king in check
    std::vector<Coor> assumeMoveList(Coor assume);//assume the piece is at some coordinate and return valid moves
	virtual std::vector<Coor> nextMoveList(); // return all possible valid moves
    virtual bool checkCastle(Coor des);
    virtual bool checkPassant(Coor c);
};

#endif



	
