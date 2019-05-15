#ifndef WEBPAGE_H_INCLUDED
#define WEBPAGE_H_INCLUDED
#include <sstream>
#include "entry.h"
#include "entrySum.h"
#include "library\stringstreamenumerator.hpp"

struct webpage
{
    std::string url;
    std::string date;
    double bouncerate;
    bool onceUnpopular;
    friend std::istream& operator>>(std::istream& istr, webpage& w);

    friend bool operator>(const webpage &lhs, const webpage &rhs)
    {
        return lhs.bouncerate > rhs.bouncerate;
    }
};

#endif // WEBPAGE_H_INCLUDED
