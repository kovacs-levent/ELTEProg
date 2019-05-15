#ifndef ENTRYSUM_H_INCLUDED
#define ENTRYSUM_H_INCLUDED
#include "library\summation.hpp"

///Egy n�pszer�s�gi bejegyz�s, sz�ks�ges az >> oper�tor, hogy stringstreamEnor-b�l tudjuk olvasni
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

///A szumm�z�s eredm�ny�t megval�s�t� strukt�ra
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
