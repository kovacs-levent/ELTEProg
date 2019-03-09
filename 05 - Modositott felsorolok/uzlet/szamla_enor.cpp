#include "szamla_enor.h"
#include <sstream>

szamlaEnor::szamlaEnor(const std::string &filename) : ifstr(filename.c_str())
{
    if(ifstr.fail())
    {
        throw FILE_ERROR;
    }
    sx = norm;
}

void szamlaEnor::First()
{
    Next();
}

void szamlaEnor::Next()
{
    Read();
    if(ifstr.fail())
    {
        sx = abnorm;
    }
}

void szamlaEnor::Read()
{
    std::string str;
    getline(ifstr, str);
    std::istringstream sstr(str);
    sstr >> dx.vevo;
    vetel tmp;
    sstr >> tmp.termek;
    sstr >> tmp.ar;
    dx.osszeg = 0;
    while(!sstr.fail())
    {
        dx.osszeg += tmp.ar;
        sstr >> tmp.termek;
        sstr >> tmp.ar;
    }
}
