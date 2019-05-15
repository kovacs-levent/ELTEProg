#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "nyelv.h"
#include "myMaxSearch.h"

int main()
{
    SeqInFileEnumerator<language> enor("input.txt");
    myMaxSearch m;
    m.addEnumerator(&enor);
    m.run();
    std::cout << m.optElem().name << " " << m.optElem().avgPopularity;
    return 0;
}
