#include "foods.h"

#include <fstream>

using namespace std;

Foods::Foods(const std::string &fname)
{
    ///Fajlban talalhato nev, ar parokkal toltsuk fel az arukeszletet
    std::ifstream ifstr(fname);
    Goods* p;
    std::string name;
    int ar;
    ifstr >> name;
    ifstr >> ar;
    while(!ifstr.fail())
    {
        p = new Goods(name, ar);
        _stock.push_back(p);
        ifstr >> name;
        ifstr >> ar;
    }
}
