#ifndef MYLINSEARCH_H_INCLUDED
#define MYLINSEARCH_H_INCLUDED
#include "library\linsearch.hpp"

class searchUnpopular : public LinSearch<language, false>
{
protected:
    bool cond(const language& e) const
    {
        return e.wasUnpopular;
    }
};

#endif // MYLINSEARCH_H_INCLUDED
