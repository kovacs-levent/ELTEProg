#include "vadaszatEnor.h"
#include <sstream>

vadaszatEnor::vadaszatEnor(const std:: string &filename) : instr(filename.c_str())
{
    if(instr.fail())
    {
        throw OPEN_ERROR;
    }
    sx = norm;
    isEnd = false;
}

void vadaszatEnor::First()
{
    Read();
    Next();
}

void vadaszatEnor::Next()
{
    isEnd = (sx == abnorm);
    akt = next;
    Read();
    while(sx == norm && akt.nev == next.nev)
    {
        akt.shotBear = akt.shotBear || next.shotBear;
        Read();
    }
}

void vadaszatEnor::Read()
{
    std::string str;
    getline(instr, str);
    if(instr.fail())
    {
        sx = abnorm;
    }
    else
    {
        std::stringstream in_sstr(str);
        in_sstr >> next.nev;
        zsakmany tmp;
        in_sstr >> tmp.allatfaj;
        in_sstr >> tmp.suly;
        next.shotBear = false;
        while(!in_sstr.fail())
        {
            next.shotBear = next.shotBear || (tmp.allatfaj == "Medve");
            in_sstr >> tmp.allatfaj;
            in_sstr >> tmp.suly;
        }
    }
}
