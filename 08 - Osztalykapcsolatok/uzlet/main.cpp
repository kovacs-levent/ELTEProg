#include <iostream>
#include "customer.h"

using namespace std;

int main()
{
    bool print=true;
    Customer c("customer1.txt");
    Store s("food.txt", "technical.txt");
    c.purchase(s);
    cout << c;
    return 0;
}
