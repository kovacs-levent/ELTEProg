#include "entrySum.h"

resultType entrySum::func(const entry& e) const
{
    resultType r;
    if(e.pages == 1)
    {
        ++r.bouncecount;
    }
    ++r.visitcount;
    return r;
}

resultType entrySum::add(const resultType &a, const resultType &b) const
{
    resultType r;
    r.bouncecount = a.bouncecount + b.bouncecount;
    r.visitcount = a.visitcount + b.visitcount;
    return r;
}
