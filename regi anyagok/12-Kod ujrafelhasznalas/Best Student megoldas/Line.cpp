#include "Line.h"

std::istream& operator>>(std::istream& istr, Line &l)
{
    istr >> l.name;
    istr >> l.mark;
    return istr;
}

/*
Ez a regi Read()-nek megfelel� met�dusunk szekvenci�lis inputf�jlok eset�n.
void Read()
{
}
*/
