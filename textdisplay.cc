#include "textdisplay.h"
#include "coor.h"
#include "info.h"
#include <vector>
#include <memory>


TextDisplay::TextDisplay() {
    for (int r = 0; r < 8; ++r) {
        std::vector<char> lis;
        for (int c = 0; c < 8; ++c) {
            if (r % 2 == 0) {
                if (c % 2 == 0) lis.emplace_back(' ');
                else if (c % 2 == 1) lis.emplace_back('_');
            }
            else if (r % 2 == 1) {
                if (c % 2 == 0) lis.emplace_back('_');
                else if (c % 2 == 1) lis.emplace_back(' ');
            }
        }
        text.emplace_back(lis);
    }
}

void TextDisplay::normInit() {
    text[0][0] = 'r';
    text[0][1] = 'n';
    text[0][2] = 'b';
    text[0][3] = 'q';
    text[0][4] = 'k';
    text[0][5] = 'b';
    text[0][6] = 'n';
    text[0][7] = 'r';
    for (int i = 0; i < 8; ++i) {
        text[1][i] = 'p';
    }
    
    text[7][0] = 'R';
    text[7][1] = 'N';
    text[7][2] = 'B';
    text[7][3] = 'Q';
    text[7][4] = 'K';
    text[7][5] = 'B';
    text[7][6] = 'N';
    text[7][7] = 'R';
    for (int i = 0; i < 8; ++i) {
        text[6][i] = 'P';
    }
}

void TextDisplay::getNotify(Coor was, Coor des, Type t, Colour colour) {
    if ((was.row == -1) && (was.col == -1)) {
        if (colour == Colour::White) {
            switch (t) {
                case tRook: text[des.row][des.col] = 'R';
                    break;
                case tKnight: text[des.row][des.col] = 'N';
                    break;
                case tBishop: text[des.row][des.col] = 'B';
                    break;
                case tQueen: text[des.row][des.col] = 'Q';
                    break;
                case tKing: text[des.row][des.col] = 'K';
                    break;
                case tPawn: text[des.row][des.col] = 'P';
                    break;
                default: text[des.row][des.col] = ' ';
                    break;
            }
        }
        if (colour == Colour::Black) {
            switch (t) {
                case tRook: text[des.row][des.col] = 'r';
                    break;
                case tKnight: text[des.row][des.col] = 'n';
                    break;
                case tBishop: text[des.row][des.col] = 'b';
                    break;
                case tQueen: text[des.row][des.col] = 'q';
                    break;
                case tKing: text[des.row][des.col] = 'k';
                    break;
                case tPawn: text[des.row][des.col] = 'p';
                    break;
                default: text[des.row][des.col] = ' ';
                    break;
            }
        }
    }
    else if ((des.row == -1) && (des.col == -1) && (t == NonPiece) && (colour == Colour::NoneColour)) {
        if (was.row % 2 == 0) {
            if (was.col % 2 == 0)  text[was.row][was.col] = ' ';
            else if (was.col % 2 == 1)  text[was.row][was.col] = '_';
        }
        else {
            if (was.col % 2 == 0)  text[was.row][was.col] = '_';
            else if (was.col % 2 == 1) text[was.row][was.col] = ' ';
        }
    }
    else {
        if (was.row % 2 == 0) {
            if (was.col % 2 == 0)  text[was.row][was.col] = ' ';
            else if (was.col % 2 == 1)  text[was.row][was.col] = '_';
        }
        else {
            if (was.col % 2 == 0)  text[was.row][was.col] = '_';
            else if (was.col % 2 == 1) text[was.row][was.col] = ' ';
        }
        if (colour == Colour::White) {
            switch (t) {
                case tRook: text[des.row][des.col] = 'R';
                    break;
                case tKnight: text[des.row][des.col] = 'N';
                    break;
                case tBishop: text[des.row][des.col] = 'B';
                    break;
                case tQueen: text[des.row][des.col] = 'Q';
                    break;
                case tKing: text[des.row][des.col] = 'K';
                    break;
                case tPawn: text[des.row][des.col] = 'P';
                    break;
                default: text[des.row][des.col] = ' ';
                    break;
            }
        }
        if (colour == Colour::Black) {
            switch (t) {
                case tRook: text[des.row][des.col] = 'r';
                    break;
                case tKnight: text[des.row][des.col] = 'n';
                    break;
                case tBishop: text[des.row][des.col] = 'b';
                    break;
                case tQueen: text[des.row][des.col] = 'q';
                    break;
                case tKing: text[des.row][des.col] = 'k';
                    break;
                case tPawn: text[des.row][des.col] = 'p';
                    break;
                default: text[des.row][des.col] = ' ';
                    break;
            }
        }
    }
}

std::ostream & operator<<(std::ostream & out, TextDisplay & t) {
    for (int r = 0; r < 8; ++r) {
        out << 8 - r << ' ';
        for (int c = 0; c < 8; ++c) {
            out << t.text[r][c];
        }
        out << std::endl;
    }
    out << std::endl;
    out << "  abcdefgh" << std::endl;
    return out;
}
