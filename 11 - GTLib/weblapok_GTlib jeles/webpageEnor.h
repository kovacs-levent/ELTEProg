#ifndef WEBPAGEENOR_H_INCLUDED
#define WEBPAGEENOR_H_INCLUDED
#include "webpage.h"
#include "library\enumerator.hpp"
#include "unpopular.h"
#include "library\seqinfileenumerator.hpp"

class webpageEnor : public Enumerator<webpage>
{
public:
    webpageEnor(const std::string &name) : f(name)
    {
        isEnd = false;
    }

    void first()
    {
        f.first();
        next();
    }

    void next();
    webpage current() const
    {
        return actpage;
    }
    bool end() const
    {
        return isEnd;
    }

protected:
    webpage actpage;
    SeqInFileEnumerator<webpage> f;
    bool isEnd;
};

#endif // WEBPAGEENOR_H_INCLUDED
