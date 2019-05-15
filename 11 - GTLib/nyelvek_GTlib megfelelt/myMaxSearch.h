#ifndef MYMAXSEARCH_H_INCLUDED
#define MYMAXSEARCH_H_INCLUDED
#include "library\maxsearch.hpp"
#include "nyelv.h"

class myMaxSearch : public MaxSearch<language, language, Greater<language> >
{
    language func(const language& l) const
    {
        return l;
    }

    bool cond(const language& l) const
    {
        return l.wasUnpopular;
    }
};


#endif // MYMAXSEARCH_H_INCLUDED
