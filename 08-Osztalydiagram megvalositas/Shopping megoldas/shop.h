#pragma once
#include <vector>
#include <string>
#include "goods.h"
#include "foods.h"
#include "technical.h"

class Shop
{
public:
    Shop(const std::string &fname, const std::string &tname);
    Goods* linSearch(const std::string &name, std::vector<Goods*> &stock) const;
    Goods* minSearch(const std::string &name, std::vector<Goods*> &stock) const;
    std::vector<Goods*>& getFoodStock()
    {
        return _foods.getStock();
    }

    std::vector<Goods*>& getTechStock()
    {
        return _tech.getStock();
    }
private:
    Foods _foods;
    Technical _tech;
};
