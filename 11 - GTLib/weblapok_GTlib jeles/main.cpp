#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "searchUnpopular.h"
#include "webpageEnor.h"
using namespace std;

int main()
{
    webpageEnor enor("input.txt");
    searchUnpopular su;
    su.addEnumerator(&enor);
    su.run();
    if(su.found())
    {
        std::cout << "Volt: " << su.elem().url;
    }
    else
    {
        std::cout << "Nem volt";
    }
    return 0;
}
