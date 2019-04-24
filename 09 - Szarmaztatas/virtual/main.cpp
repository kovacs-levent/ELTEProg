#include <iostream>

using namespace std;

//Egyszeru pelda ami szemlelteti a virtualis es nem virtualis fuggvenyek oroklese kozti kulonbseget.

class Base
{
public:
    void show()
    {
        std::cout << "Base class show()!" << std::endl;
    }

    virtual void write()
    {
        std::cout << "Base class write()!" << std::endl;
    }

    virtual ~Base()
    {

    }
};

class Derived : public Base
{
public:
    void show()
    {
        std::cout << "Derived class show()!" << std::endl;
    }

    void write()
    {
        std::cout << "Derived class write()!" << std::endl;
    }
};

int main()
{
    Base* b = new Derived;
    b->show();
    b->write();
    delete b;
    return 0;
}
