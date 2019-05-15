#ifndef UNPOPULAR_H_INCLUDED
#define UNPOPULAR_H_INCLUDED
#include "library\summation.hpp"

class unpopular : public Summation<webpage, bool>
{
public:
    unpopular(const std::string& name, const bool first) : firstPop(first), _name(name)
    {

    }
protected:
    bool neutral() const
    {
        return firstPop;
    }

    bool func(const webpage& e) const
    {
        return e.onceUnpopular;
    }

    bool add(const bool& a, const bool& b) const
    {
        return a || b;
    }

    bool whileCond(const webpage& current) const
    {
        return (current.url == _name);
    }
    bool firstPop;
    std::string _name;
};

#endif // UNPOPULAR_H_INCLUDED
