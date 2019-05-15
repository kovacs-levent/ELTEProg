#ifndef NYELV_H_INCLUDED
#define NYELV_H_INCLUDED
#include "library/stringstreamenumerator.hpp"
#include "entrySum.h"


///A nyelv t�pusa, ezt kell felsorolni, sz�ks�ges az >> oper�tor a beolvas�shoz, �s a > oper�tor a maxkerhez
struct language
{
    std::string name;
    double avgPopularity;
    bool wasUnpopular;

    friend std::istream& operator>>(std::istream& istr, language &l);

    friend bool operator>(const language& lhs, const language& rhs)
    {
        return lhs.avgPopularity > rhs.avgPopularity;
    }
};

#endif // NYELV_H_INCLUDED
