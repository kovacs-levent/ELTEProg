#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include "department.h"

class Store
{
public:
    Store(const std::string &foodIn, const std::string &engineerIn);
    Department foodDept, engDept;
};

#endif // STORE_H_INCLUDED
