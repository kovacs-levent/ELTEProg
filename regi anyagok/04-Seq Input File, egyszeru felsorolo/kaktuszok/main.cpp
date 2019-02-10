#include <iostream>
#include "infile.h"
#include "kaktuszEnor.h"
#include "outfile.h"

using namespace std;
//Az órán látott tétel felsoroló nélkül InFile-al
bool felt_max_ker_read(const std::string &input, kaktusz &maxelem, int &maxm)
{
    bool l = false;
    InFile in_file(input);
    in_file.read();
    while(in_file.getSx() != abnorm)
    {
        bool tmp = (in_file.GetDx().haza == "Mexiko");
        if(!tmp)
        {

        }
        else if(tmp && l)
        {
            if(maxm < in_file.GetDx().meret)
            {
                maxm = in_file.GetDx().meret;
                maxelem = in_file.GetDx();
            }
        }
        else if(tmp && !l)
        {
            l = true;
            maxelem = in_file.GetDx();
            maxm = in_file.GetDx().meret;
        }
        in_file.read();
    }
    return l;
}
//Az órán látott tétel felsoroló objektummal
bool felt_max_ker_enor(const std::string &input, kaktusz &maxelem, int &maxm)
{
    bool l = false;
    kaktuszEnor enor(input);
    enor.First();
    while(!enor.End())
    {
        bool tmp = (enor.Current().haza == "Mexiko");
        if(!tmp)
        {

        }
        else if(tmp && l)
        {
            if(maxm < enor.Current().meret)
            {
                maxm = enor.Current().meret;
                maxelem = enor.Current();
            }
        }
        else if(tmp && !l)
        {
            l = true;
            maxelem = enor.Current();
            maxm = enor.Current().meret;
        }
        enor.Next();
    }
    return l;
}

int main()
{
    kaktusz maxelem;
    int maxmeret;
    bool l = felt_max_ker_enor("input.txt", maxelem, maxmeret);
    if(l)
    {
        std::cout << "A legnagyobb mexikoi kaktusz:" << maxelem.nev << ", merete:" << maxmeret;
    }
    else
    {
        std::cout << "Nem volt mexikoi kaktusz.";
    }
    return 0;
}
