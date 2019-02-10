#pragma once
#include "library/summation.hpp"
#include "library/linsearch.hpp"
#include "library/intervalenumerator.hpp"
#include <iostream>
#include <cmath>

class MySum : public Summation<int>
{
protected:
    void init()
    {
        *_result = 0;
    }

    void add(const int &e)
    {
        *_result += e;
    }
};

class Evens : public Summation<int, std::ostream>
{
public:
    Evens(std::ostream* ostr) : Summation<int, std::ostream>(ostr)
    {

    }
protected:
    void init()
    {
    }

    void add(const int& e)
    {
        *_result << e << " ";
    }

    bool cond(const int& e) const
    {
        return e % 2 == 0;
    }
};

class All_Even : public LinSearch<int, true>
{
protected:
    bool cond(const int& e) const
    {
        return e % 2 == 0;
    }
};

class Is_Prime : public LinSearch<int, true>
{
public:
    Is_Prime(const int& e)
    {
        n = e;
    }
protected:
    int n;

    bool cond(const int& e) const
    {
        return n % e != 0;
    }
};

class Has_Prime : public LinSearch<int>
{
protected:
    bool cond(const int &e) const
    {
        Is_Prime ip(e);
        if(e > 1)
        {
            IntervalEnumerator enor(2, sqrt(e));
            ip.addEnumerator(&enor);
            ip.run();
            return ip.found();
        }
        return false;
    }
};

class SumDivisors : public Summation<int>
{
public:
    SumDivisors(const int& e)
    {
        n = e;
    }
protected:
    int n;
    void init()
    {
        *_result = 0;
    }

    void add(const int& e)
    {
        *_result += e;
    }

    bool cond(const int& e) const
    {
        return n % e == 0;
    }
};
