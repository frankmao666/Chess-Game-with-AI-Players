#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include "coor.h"
#include "info.h"
#include <memory>
#include <iostream>
#include <vector>

class Board;

class TextDisplay {
    
    std::vector<std::vector<char> > text;
    public:
    TextDisplay();
    void normInit();
    void getNotify(Coor was, Coor des, Type t, Colour colour);
    friend std::ostream & operator<<(std::ostream & out, TextDisplay & t);
    
    
};

#endif

