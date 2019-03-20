#include <iostream>
#include "feketelyukEnor.h"

using namespace std;

///Ebben a f�jlban a megfelelt szint megold�sa van. A t�teles feladat a main-be:
///Adjon meg egy olyan fekete lyukat (annak azonos�t�j�t), amelynek utolj�ra m�rt t�mege a legnagyobb azok k�z�tt,
///amelyeket valamikor 3 milli� f�ny�vn�l k�zelebb �szleltek!

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
