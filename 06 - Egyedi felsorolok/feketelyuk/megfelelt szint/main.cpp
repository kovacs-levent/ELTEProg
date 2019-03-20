#include <iostream>
#include "feketelyukEnor.h"

using namespace std;

///Ebben a fájlban a megfelelt szint megoldása van. A tételes feladat a main-be:
///Adjon meg egy olyan fekete lyukat (annak azonosítóját), amelynek utoljára mért tömege a legnagyobb azok között,
///amelyeket valamikor 3 millió fényévnél közelebb észleltek!

int main()
{
    feketelyukEnor enor("input.txt");
    bool l = false;
    int maxWeight;
    feketelyuk elem;
    enor.First();
    while(!enor.End())
    {
        feketelyuk tmp = enor.Current();
        if(!tmp.wasClose)
        {

        }
        else if(tmp.wasClose && l)
        {
            if(tmp.lastWeight < maxWeight)
            {
                elem = tmp;
                maxWeight = tmp.lastWeight;
            }
        }
        else if(tmp.wasClose && !l)
        {
            l = true;
            elem = tmp;
            maxWeight = elem.lastWeight;
        }
        enor.Next();
    }
    if(l)
    {
        std::cout << "A legnagyobb tomegu fekete lyuk, amelyik kozelebb volt valamikor mint 3 millio fenyev: " << elem.ID;
    }
    else
    {
        std::cout << "Nem volt 3 millio fenyevnel kozelebb fekete lyuk.";
    }
    return 0;
}
