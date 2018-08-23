#ifndef KAKTUSZENOR_H_INCLUDED
#define KAKTUSZENOR_H_INCLUDED
#include "infile.h"

class kaktuszEnor
{
public:
    kaktuszEnor(const std::string &inputfile) : input(inputfile)
    {

    }

    void First()
    {
        input.read();
    }

    bool End() const
    {
        return input.getSx() == abnorm;
    }

    void Next()
    {
        input.read();
    }

    kaktusz Current() const
    {
        return input.GetDx();
    }
private:
    InFile input;
};

#endif // KAKTUSZENOR_H_INCLUDED
