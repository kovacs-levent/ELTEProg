#include <iostream>
#include "merge_enor.h"

using namespace std;

int main()
{
    mergeEnor enor("input.txt", "input2.txt");
    enor.First();
    while(!enor.End())
    {
        std::cout << enor.Current() << " ";
        enor.Next();
    }
    return 0;
}
