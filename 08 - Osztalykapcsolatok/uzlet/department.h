#ifndef DEPARTMENT_H_INCLUDED
#define DEPARTMENT_H_INCLUDED
#include "product.h"
#include <vector>
class Department
{
public:
    Department(const std::string &filename);
    void removeGoods(int i);
    Product getProduct(int i) const
    {
        return stock[i];
    }
    unsigned int getStockSize() const
    {
        return stock.size();
    }
private:
    std::vector<Product> stock;
};

#endif // DEPARTMENT_H_INCLUDED
