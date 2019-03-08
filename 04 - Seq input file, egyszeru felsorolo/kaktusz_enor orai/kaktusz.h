#ifndef KAKTUSZ_H_INCLUDED
#define KAKTUSZ_H_INCLUDED
#include <string>

struct kaktusz
{
    std::string nev;
    std::string haza;
    std::string szin;
    int meret;

	//Konstruktor a kaktuszokhoz, ez a mostani feladathoz nem kell
    /*kaktusz(const std::string &n, const std::string &h, const std::string &sz, const int &m)
    {
        nev = n;
        haza = h;
        szin = sz;
        meret = m;
    }*/
};

#endif // KAKTUSZ_H_INCLUDED
