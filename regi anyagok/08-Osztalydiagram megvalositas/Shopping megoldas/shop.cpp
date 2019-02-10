#include "shop.h"

using namespace std;

Shop::Shop(const string &fname, const string &tname):_foods(fname), _tech(tname)
{
    ///Inicializalo listaban inicializaljuk az elelmiszer es muszaki reszleget
}

Goods* Shop::linSearch(const string &name, vector<Goods*> &stock) const
{
    ///linearis keresessel menjunk vegig az arukeszleten, az elelmiszer reszleg bejarasahoz seged eljaras
    bool l = false;
    Goods* p = NULL;
    int i = 0;
    while(!l && i < stock.size())
    {
        l = (name == stock[i]->name);
        i++;
    }
    if(l)
    {
        p = stock[i-1];
    }
    return p;
}

Goods* Shop::minSearch(const string &name, vector<Goods*> &stock) const
{
    ///Felt. min kerrel menjunk vegig az arukeszleten a legkisebb arral rendelkezo arut keresve, a muszaki reszleg bejarasahoz seged eljaras
    bool l = false;
    Goods* p = NULL;
    int min;
    int i = 0;
    while(i < stock.size())
    {
        if(name != stock[i]->name)
        {

        }
        else if(l && name == stock[i]->name)
        {
            if(min > stock[i]->price)
            {
                p = stock[i];
                min = stock[i]->price;
            }
        }
        else if(!l && name == stock[i]->name)
        {
            l = true;
            p = stock[i];
            min = stock[i]->price;
        }
        i++;
    }
    return p;
}
