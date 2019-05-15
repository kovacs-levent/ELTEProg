#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "highestBounce.h"
using namespace std;

int main()
{
    SeqInFileEnumerator<webpage> enor("input.txt");
    highestBounce hb;
    hb.addEnumerator(&enor);
    hb.run();
    std::cout << hb.opt().url << " " << hb.opt().bouncerate;
    return 0;
}
