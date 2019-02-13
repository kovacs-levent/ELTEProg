#include <iostream>
#include "horpadas.h"

using namespace std;

///Feladat: Legmagasabban fekvõ horpadás keresése. Egy felszínen adott távolságonként mérték a tengerszint feletti magasságot.
/// Horpadásnak veszünk egy értéket, ha a körülötte (balra és jobbra) lévõ magasságok nagyobbak ennél az értéknél.
/// A feltételes maximum keresés programozási tétellel oldjuk meg a feladatot.

int main()
{
    Felszin f;
    f.beolvas_darabszam("input_darabbal.txt");
    int ind, max;
    if(f.max_horpadas(ind, max))
    {
        std::cout << "A legnagyobb horpadas: " << max << std::endl;
    }
    else
    {
        std::cout << "Nem volt horpadas" << std::endl;
    }
    f.beolvas_darab_nelkul("input_darabnelkul.txt");
    if(f.max_horpadas(ind,max))
    {
        std::cout << "A legnagyobb horpadas: " << max << std::endl;
    }
    else
    {
        std::cout << "Nem volt horpadas" << std::endl;
    }
    return 0;
}
