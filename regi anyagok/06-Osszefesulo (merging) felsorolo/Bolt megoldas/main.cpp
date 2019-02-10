#include <iostream>
#include "bolt_enor.h"

using namespace std;

bool felt_max_ker_bolt(const std::string &input, const std::string &input2, rendeles& maxelem, int &max)
{
    bool l = false;
    bolt_enor be("input.txt","input2.txt");
    be.First();
    while(!be.End())
    {
        if(be.Current().sold || be.Current().written)
        {

        }
        else if(l && !be.Current().sold && !be.Current().written)
        {
            if(max < be.Current().db)
            {
                maxelem = be.Current();
                max = be.Current().db;
            }
        }
        else if(!l && !be.Current().sold && !be.Current().written)
        {
            l = true;
            maxelem = be.Current();
            max = be.Current().db;
        }
        be.Next();
    }
    return l;
}

int main()
{
    rendeles maxelem;
    int max;
    if(felt_max_ker_bolt("input.txt","input2.txt", maxelem, max))
    {
        cout << maxelem.aru << " " << max;
    }
    else
    {
        cout << "Nem volt ilyen elem!";
    }
    //cout << "Hello world!" << endl;
    return 0;
}
