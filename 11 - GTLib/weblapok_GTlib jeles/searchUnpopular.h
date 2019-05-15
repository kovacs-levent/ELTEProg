#ifndef SEARCHUNPOPULAR_H_INCLUDED
#define SEARCHUNPOPULAR_H_INCLUDED
#include "library\linsearch.hpp"
#include "webpage.h"

class searchUnpopular : public LinSearch<webpage, false>
{
    bool cond(const webpage& e) const
    {
        return e.onceUnpopular;
    }
};

#endif // SEARCHUNPOPULAR_H_INCLUDED
