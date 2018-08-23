#include "creature.h"

using namespace std;

void Greenfinch::transmute(int &ground)
{
    ///megvalósítása a transmute-nak
    if ( alive())
    {
        switch(ground)
        {
            case 0: _power-=2; break;
            case 1: _power+=1; break;
            case 2: _power-=1; ground = 1; break;
        }
    }
}

void Sandbug::transmute(int &ground)
{
    if (alive())
    {
        switch(ground)
        {
            case 0: _power+=3; break;
            case 1: _power-=2; ground = 0; break;
            case 2: _power-=4; ground = 1; break;
        }
    }
}

void Squelchy::transmute(int &ground)
{

}
