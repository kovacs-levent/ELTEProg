#include <iostream>
#include <vector>
#include "customer.h"
#include "shop.h"

using namespace std;

int main()
{
    Shop s("elelmiszer.txt","muszaki.txt");
    Customer c("lista.txt");

    c.purchase(s);
    for( Goods* p : c.getGoods()){ cout << p->name << ":" << p->price << endl; }
    return 0;
}
