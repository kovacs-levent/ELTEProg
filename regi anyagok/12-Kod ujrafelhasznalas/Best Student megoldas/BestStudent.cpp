#include "BestStudent.h"
#include "arrayenumerator.hpp"

double BestStudent::func(const Student &e) const
{
    Average pr;
    ArrayEnumerator<int> enor2(&e.mark);
    pr.addEnumerator(&enor2);
    pr.run();
    return pr.result().sum/pr.result().count;
}
