#ifndef ENTRYSUM_H_INCLUDED
#define ENTRYSUM_H_INCLUDED
#include "library\summation.hpp"
#include "entry.h"

struct resultType
{
    int visitcount;
    int bouncecount;
    resultType() : visitcount(0), bouncecount(0)
    {
    }
};

class entrySum : public Summation<entry, resultType>
{
    resultType neutral() const
    {
        resultType r;
        return r;
    }

    resultType func(const entry& e) const;
    resultType add(const resultType &a, const resultType &b) const;
};


#endif // ENTRYSUM_H_INCLUDED
