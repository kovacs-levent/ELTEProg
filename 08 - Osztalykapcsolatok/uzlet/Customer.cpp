#include "customer.h"
#include <fstream>

Customer::Customer(const std::string &fname)
{
    std::ifstream ifstr(fname);
    std::string tmp;
    ifstr >> name;
    ifstr >> tmp;
    while(!ifstr.fail())
    {
        list.push_back(tmp);
        ifstr >> tmp;
    }
}

bool Customer::linsearch(const std::string &name, const Department& r, int &ind) const
{
    bool l = false;
    int i = 0;
    while(!l && i < r.getStockSize())
    {
        l = r.getProduct(i).name == name;
        ind = i;
        ++i;
    }
    return l;
}

bool Customer::minsearch(const std::string &name, const Department &r, int &ind) const
{
    bool l = false;
    int minPrice;
    for(unsigned int i=0; i<r.getStockSize(); ++i)
    {
        if (r.getProduct(i).name != name)
        {

        }
        if (l && r.getProduct(i).name == name)
        {
            if (minPrice > r.getProduct(i).price)
            {
                minPrice = r.getProduct(i).price;
                ind = i;
            }
        }
        else if (!l && r.getProduct(i).name == name)
        {
            l = true;
            minPrice = r.getProduct(i).price;
            ind = i;
        }
    }
    return l;
}

void Customer::purchase(Store &store)
{
    for(int i = 0; i < list.size(); ++i)
    {
        int j;
        if(linsearch(list[i], store.foodDept, j))
        {
            putInCart(store.foodDept.getProduct(j));
            store.foodDept.removeGoods(j);
        }
    }
     for(int i = 0; i < list.size(); ++i)
    {
        int j;
        if(minsearch(list[i], store.engDept, j))
        {
            putInCart(store.engDept.getProduct(j));
            store.engDept.removeGoods(j);
        }
    }
}

std::ostream &operator<< (std::ostream &os, const Customer &c)
{
    os << c.name << " has bought the following products: \n";
    for (int i = 0; i < c.basket.size(); ++i)
    {
        os << "  " << c.basket[i].name << " " << c.basket[i].price << std::endl;
    }
    return os;
}
