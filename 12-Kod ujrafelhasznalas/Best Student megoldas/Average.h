#ifndef AVERAGE_H_INCLUDED
#define AVERAGE_H_INCLUDED
#include "Line.h"
#include "summation.hpp"

struct Result
{
    int sum;
    int count;
    bool isFailing;
};

class Average:public Summation<Line, Result>
{
public:
    Average(const std::string& name, const int mark)
    {
        _name = name;
        firstMark = mark;
    }

    void init()
    {
        _result->sum = firstMark;
        _result->count = 1;
        _result->isFailing = firstMark == 1;
    }

    void add(const Line &e)
    {
        _result->sum += e.mark;
        _result->count++;
        _result->isFailing = _result->isFailing || e.mark == 1;
    }

    bool whileCond(const Line &e) const
    {
        return (e.name == _name);
    }
private:
    std::string _name;
    int firstMark;
};

#endif // AVERAGE_H_INCLUDED
