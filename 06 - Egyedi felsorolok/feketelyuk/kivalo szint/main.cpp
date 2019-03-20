#include <iostream>
#include "feketelyukEnor.h"

using namespace std;

///Ebben a fájlban a kiválo szint megoldása van. A tételes feladat a main-be:
///Írja ki azoknak a fekete lyukaknak az azonosítóját,
///amelyeket mindegyik megfigyelő-állomás legalább egyszer 3 millió fényévnél közelebb észlelt!

int main()
{
    feketelyukEnor enor("input.txt");
    enor.First();
    while(!enor.End())
    {
        feketelyuk tmp = enor.Current();
        if(tmp.alwaysClose)
        {
            std::cout << tmp.ID << std::endl;
        }
        enor.Next();
    }
    return 0;
}
