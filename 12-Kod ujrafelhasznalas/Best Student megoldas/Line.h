#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <iostream>

struct Line
{
    std::string name;
    int mark;
    friend std::istream& operator>>(std::istream& istr, Line &l);
};

#endif // LINE_H_INCLUDED
