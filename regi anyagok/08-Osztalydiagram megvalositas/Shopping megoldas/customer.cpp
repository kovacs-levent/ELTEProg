#include "customer.h"
#include <fstream>
#include <iostream>

using namespace std;

Customer::Customer(const std::string &fname)
{
    ///toltsuk fel a bevasarlo listat a fajlban talalhato stringekkel
    std::ifstream ifstr(fname);
    std::string tmp;
    ifstr >> tmp;
    while(!ifstr.fail())
    {
        _list.push_back(tmp);
        ifstr >> tmp;
    }
}

void Customer::purchase(Shop &s)
{
    ///Oldjuk meg a feladatot, eloszor az elelmiszereken majd a muszaki reszlegen vegigmenve
    int i = 0;
    while(i < _list.size())
    {
        Goods* p = s.linSearch(_list[i], s.getFoodStock());
        if(p != NULL)
        {
            putInCart(p);
        }
        i++;
    }
    i = 0;
    while(i < _list.size())
    {
        Goods* q = s.minSearch(_list[i], s.getTechStock());
        if(q != NULL)
        {
            putInCart(q);
        }
        i++;
    }
}

void Customer::putInCart(Goods *p)
{
    _goods.push_back(p);
}

