#ifndef SZAMLA_H_INCLUDED
#define SZAMLA_H_INCLUDED
#include <string>

struct szamla
{
    std::string vevo;
    int osszeg;
    szamla() : vevo(""), osszeg(0)
    {
    }
};

struct vetel
{
    std::string termek;
    int ar;
};

#endif // SZAMLA_H_INCLUDED
