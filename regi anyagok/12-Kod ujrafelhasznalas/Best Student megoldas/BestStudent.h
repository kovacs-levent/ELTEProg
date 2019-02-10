#ifndef BESTSTUDENT_H_INCLUDED
#define BESTSTUDENT_H_INCLUDED
#include "maxsearch.hpp"
#include "Student.h"
#include "Average.h"
#include <iostream>

class BestStudent : public MaxSearch<Student,double,Less<double> >
{
    double func(const Student &e) const
    {
        std::cout << e.name << " " << e.avr << " " << e.isFailing << std::endl;
        return e.avr;
    }

    bool cond(const Student& e) const
    {
        return !e.isFailing;
    }
};

#endif // BESTSTUDENT_H_INCLUDED
