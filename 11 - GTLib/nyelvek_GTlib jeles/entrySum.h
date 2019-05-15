#ifndef ENTRYSUM_H_INCLUDED
#define ENTRYSUM_H_INCLUDED
#include "library\summation.hpp"

///Egy népszerûségi bejegyzés, szükséges az >> operátor, hogy stringstreamEnor-ból tudjuk olvasni
struct entry
{
    std::string date;
    int popularity;
    friend std::istream& operator>>(std::istream& istr, entry &e)
    {
        istr >> e.date;
        istr >> e.popularity;
        return istr;
    }
};

///A szummázás eredményét megvalósító struktúra
struct resultType
{
    int sum;
    int count;
    bool wasUnpopular;
    resultType() : sum(0), count(0), wasUnpopular(false)
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
    resultType add(const resultType& a, const resultType& b) const;

};


#endif // ENTRYSUM_H_INCLUDED
