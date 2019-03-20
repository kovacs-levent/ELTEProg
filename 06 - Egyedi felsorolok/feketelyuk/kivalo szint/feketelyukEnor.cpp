#include "feketelyukEnor.h"
#include <sstream>
#include <iostream>

feketelyukEnor::feketelyukEnor(const std::string &filename) : ifstr(filename.c_str())
{
    if(ifstr.fail())
    {
        throw OPEN_ERROR;
    }
    isEnd = false;
    sx = norm;
}

void feketelyukEnor::First()
{
    Read();
    Next();
}

void feketelyukEnor::Next()
{
    ///Prog tétel szükséges a Next-be
    ///Jelen esetben összegezzük a wasClose-okat, hogy megkapjuk, minden állomás észlelte-e közel
    ///Alapból ez egy lineáris keresés lenne, de az olvasást nem szakíthatjuk meg, vissza kell vezetni a linkert összegzésre
    isEnd = (sx == abnorm);
    akt = next;
    akt.alwaysClose = akt.wasClose;
    Read();
    while(sx == norm && akt.ID == next.ID)
    {
        akt.alwaysClose = akt.alwaysClose && next.wasClose;
        Read();
    }
}

void feketelyukEnor::Read()
{
    std::string str;
    std::getline(ifstr, str);
    if(ifstr.fail())
    {
        sx = abnorm;
    }
    else
    {
        std::istringstream i_sstr(str);
        i_sstr >> next.ID;
        std::string station;
        i_sstr >> station;
        next.wasClose = false;
        megfigyeles tmp;
        i_sstr >> tmp.date;
        i_sstr >> tmp.weight;
        i_sstr >> tmp.distance;
        while(!i_sstr.fail())
        {
            next.wasClose = next.wasClose || tmp.distance < 3;
            next.lastWeight = tmp.weight;
            i_sstr >> tmp.date;
            i_sstr >> tmp.weight;
            i_sstr >> tmp.distance;
        }
    }
}
