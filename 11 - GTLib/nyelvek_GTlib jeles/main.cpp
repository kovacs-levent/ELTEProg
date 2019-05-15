#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "languageEnor.h"
#include "myLinsearch.h"

int main()
{
    languageEnor enor("input.txt");
    searchUnpopular m;
    m.addEnumerator(&enor);
    m.run();
    if(m.found())
    {
        std::cout << m.elem().name;
    }
    else
    {
        std::cout << "Nem volt ilyen nyelv";
    }
    return 0;
}
