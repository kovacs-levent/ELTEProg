#include "department.h"
#include <fstream>

Department::Department(const std::string &filename)
{
    std::ifstream ifstr(filename);
    Product good;
    ifstr >> good.name;
    ifstr >> good.price;
    while(!ifstr.fail())
    {
        stock.push_back(good);
        ifstr >> good.name;
        ifstr >> good.price;
    }
}

void Department::removeGoods(int i)
{
    stock[i] = stock[stock.size()-1];
    stock.pop_back();
}
