#ifndef HIGHESTBOUNCE_H_INCLUDED
#define HIGHESTBOUNCE_H_INCLUDED
#include "library\maxsearch.hpp"
#include "webpage.h"

class highestBounce : public MaxSearch<webpage, webpage, Greater<webpage> >
{
    webpage func(const webpage& e) const
    {
        return e;
    }
};

#endif // HIGHESTBOUNCE_H_INCLUDED
