#include "feketelyukEnor.h"
#include <sstream>
#include <iostream>

feketelyukEnor::feketelyukEnor(const std::string &filename) : ifstr(filename.c_str())
{
    if(ifstr.fail())
    {
        throw OPEN_ERROR;
    }
}

void feketelyukEnor::First()
{
    Read();
    if(ifstr.fail())
    {
        sx = abnorm;
    }
    else
    {
        sx = norm;
    }
}

void feketelyukEnor::Next()
{
    Read();
    if(ifstr.fail())
    {
        sx = abnorm;
    }
}

void feketelyukEnor::Read()
{
    std::string str;
    std::getline(ifstr, str);
    std::istringstream i_sstr(str);
    i_sstr >> dx.ID;
    dx.wasClose = false;
    megfigyeles tmp;
    i_sstr >> tmp.date;
    i_sstr >> tmp.weight;
    i_sstr >> tmp.distance;
    while(!i_sstr.fail())
    {
        dx.wasClose = dx.wasClose || tmp.distance < 3;
        dx.lastWeight = tmp.weight;
        i_sstr >> tmp.date;
        i_sstr >> tmp.weight;
        i_sstr >> tmp.distance;
    }
}
