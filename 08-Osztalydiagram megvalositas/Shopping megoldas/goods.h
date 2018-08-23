#pragma once
#include <string>

class Goods
{
public:
    std::string name;
    int price;
    Goods(const std::string & n, int i):name(n),price(i){}
};
