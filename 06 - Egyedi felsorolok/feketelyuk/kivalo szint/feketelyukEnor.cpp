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
    ///Prog t�tel sz�ks�ges a Next-be
    ///Jelen esetben �sszegezz�k a wasClose-okat, hogy megkapjuk, minden �llom�s �szlelte-e k�zel
    ///Alapb�l ez egy line�ris keres�s lenne, de az olvas�st nem szak�thatjuk meg, vissza kell vezetni a linkert �sszegz�sre
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
