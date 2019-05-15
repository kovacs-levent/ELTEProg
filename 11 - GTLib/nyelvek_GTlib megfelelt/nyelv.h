#ifndef NYELV_H_INCLUDED
#define NYELV_H_INCLUDED
#include "library/stringstreamenumerator.hpp"
#include "entrySum.h"


///A nyelv típusa, ezt kell felsorolni, szükséges az >> operátor a beolvasáshoz, és a > operátor a maxkerhez
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
