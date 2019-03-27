#include <iostream>
#include "vadaszatEnor.h"

bool allHunterShotBear(const std::string &filename, vadasz &elem)
{
    vadaszatEnor enor(filename);
    bool l = true;
    enor.First();
    while(l && !enor.End())
    {
        elem = enor.Current();
        l = elem.shotBear;
        enor.Next();
    }
    return l;
}

int main()
{
    vadasz result;
    if(allHunterShotBear("input.txt", result))
    {
        std::cout << "Minden vadasz lott medvet valamelyik vadaszatan";
    }
    else
    {
        std::cout << "Nem minden vadasz lott medvet, pl.: " << result.nev << " nem lott";
    }
    return 0;
}
