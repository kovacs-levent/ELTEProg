#ifndef LANGUAGEENOR_H_INCLUDED
#define LANGUAGEENOR_H_INCLUDED
#include "nyelv.h"
#include "library/seqinfileenumerator.hpp"
#include "alwaysPopular.h"

class languageEnor : public Enumerator<language>
{
public:
    languageEnor(const std::string &fname) : f(fname)
    {
    }
protected:
    void first()
    {
        f.first();
        next();
    }

    void next();

    language current() const
    {
        return actLanguage;
    }

    bool end() const
    {
        return isEnd;
    }
private:
    language actLanguage;
    SeqInFileEnumerator<language> f;
    bool isEnd;
};


#endif // LANGUAGEENOR_H_INCLUDED
