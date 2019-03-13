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
    std::string tmp_str;
    getline(ifstr, tmp_str);
    std::istringstream sstr(tmp_str);
    std::ostringstream name_str;
    std::string name, puffer;
    sstr >> name;
    sstr >> tmp_str;
    sstr >> puffer;
    while(!isNumber(puffer))
    {
        name += " " + tmp_str;
        tmp_str = puffer;
        sstr >> puffer;
    }
    dx.vevo = name;
    vetel tmp;
    tmp.termek = tmp_str;
    tmp.ar = atoi(puffer.c_str());
    ///C++11-es konverzió (ehhez include-olni kell a string header-t): tmp.termek = std::stoi(puffer);
    dx.osszeg = 0;
    while(!sstr.fail())
    {
        dx.osszeg += tmp.ar;
        sstr >> tmp.termek;
        sstr >> tmp.ar;
    }
}

bool szamlaEnor::isNumber(const std::string &str)
{
    bool l = true;
    unsigned int i = 0;
    while(l && i < str.length())
    {
        l = isdigit(str[i]);
        ++i;
    }
    return l;
}
