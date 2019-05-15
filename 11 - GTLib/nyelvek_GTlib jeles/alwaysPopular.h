#ifndef ALWAYSPOPULAR_H_INCLUDED
#define ALWAYSPOPULAR_H_INCLUDED
#include "library/summation.hpp"

class alwaysUnpopular : public Summation<language, bool>
{
public:
    alwaysUnpopular(const std::string &lang, const bool l)
    {
        name = lang;
        firstPopular = l;
    }

    bool neutral() const
    {
        return firstPopular;
    }

    bool func(const language &e) const
    {
        return e.wasUnpopular;
    }

    bool add(const bool& a, const bool &b) const
    {
        return a && b;
    }

    bool whileCond(const language & current) const
    {
        return (current.name == name);
    }
private:
    std::string name;
    bool firstPopular;
};

#endif // ALWAYSPOPULAR_H_INCLUDED
