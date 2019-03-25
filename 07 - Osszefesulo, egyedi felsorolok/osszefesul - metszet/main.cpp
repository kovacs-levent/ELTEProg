#include <iostream>
#include "merge_enor.h"

using namespace std;

int main()
{
    mergeEnor enor("input.txt", "input2.txt");
    enor.First();
    while(!enor.End())
    {
        if(enor.Current().isWritten)
        {
            std::cout << enor.Current().value << " ";
        }
        enor.Next();
    }
    return 0;
}
