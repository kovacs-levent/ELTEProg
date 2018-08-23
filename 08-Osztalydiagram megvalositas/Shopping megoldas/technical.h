#pragma once
#include <vector>
#include <string>
#include "goods.h"

class Technical
{
public:
    Technical(const std::string &fname);
    std::vector<Goods*>& getStock()
    {
        return _stock;
    }
private:
    std::vector<Goods*> _stock;
};
