#include "entrySum.h"

resultType entrySum::func(const entry& e) const
{
    resultType r;
    r.sum = e.popularity;
    r.count = 1;
    r.wasUnpopular = e.popularity < 10;
    return r;
}

resultType entrySum::add(const resultType& a, const resultType& b) const
{
    resultType r;
    r.sum = a.sum + b.sum;
    r.count = a.count + b.count;
    r.wasUnpopular = a.wasUnpopular || b.wasUnpopular;
    return r;
}
