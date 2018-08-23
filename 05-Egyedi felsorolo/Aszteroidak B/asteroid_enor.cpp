#include "asteroid_enor.h"
#include <iostream>
#include <cstdlib>

asteroid_enor::asteroid_enor(const std::string &input)
{
    ifstr.open(input.c_str());
    if(ifstr.fail())
    {
        throw FILE_ERROR;
    }
    st = norm;
    isEnd = false;
}

void asteroid_enor::Read()
{
    ifstr >> next.id;
    ifstr >> next.date;
    ifstr >> next.weight;
    ifstr >> next.distance;
    if(ifstr.fail())
    {
        st = abnorm;
    }
}

void asteroid_enor::First()
{
    Read();
    if(st == abnorm)
    {
        std::cout << "Ures fajl!";
        exit(1);
    }
    Next();
}

void asteroid_enor::Next()
{
    isEnd = (st == abnorm);
    akt = next;
    akt.is_closing = true;
    akt.closed_distance = 0;
    Read();
    while(st == norm && akt.id == next.id)
    {
        akt.is_closing = akt.is_closing && next.distance < akt.distance;
        akt.closed_distance = akt.closed_distance + akt.distance - next.distance;
        akt.weight = next.weight;
        akt.distance = next.distance;
        Read();
    }
}
