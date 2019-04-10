#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <string>
#include "department.h"
#include "product.h"
#include "store.h"

class Customer
{
public:
    Customer(const std::string &fname);
    void purchase(Store &store);
    void putInCart(const Product &p)
    {
        basket.push_back(p);
    }
    friend std::ostream &operator<< (std::ostream &os, const Customer &c);

private:
    std::string name;
    std::vector<std::string> list;
    std::vector<Product> basket;

    bool linsearch(const std::string &name, const Department& r, int &ind) const;
    bool minsearch(const std::string &name, const Department& r, int &ind) const;
};

#endif // CUSTOMER_H_INCLUDED
