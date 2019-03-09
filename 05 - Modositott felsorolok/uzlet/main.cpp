#include <iostream>
#include "szamla_enor.h"

using namespace std;

int main()
{
    szamlaEnor enor("input.txt");
    int bevetel = 0;
    enor.First();
    while(!enor.End())
    {
        bevetel += enor.Current().osszeg;
        enor.Next();
    }
    std::cout << "A mai bevetel: " << bevetel;
    return 0;
}
