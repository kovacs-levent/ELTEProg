#include "merge_enor.h"

mergeEnor::mergeEnor(const std::string &file1, const std::string &file2) : in1(file1.c_str()), in2(file2.c_str())
{
    if(in1.fail() || in2.fail())
    {
        throw OPEN_ERROR;
    }
    sx = norm;
    sy = norm;
    isEnd = false;
}

void mergeEnor::First()
{
    Read1();
    Read2();
    Next();
}

void mergeEnor::Next()
{
    if(sx == abnorm || sy == abnorm)
    {
        isEnd = true;
    }
    if(sy == abnorm || (sx == norm && dx < dy))
    {
        akt.isWritten = true;
        Read1();
    }
    else if(sx == norm && sy == norm  && dx == dy)
    {
        akt.value = dx;
        akt.isWritten = false;
        Read1();
        Read2();
    }
    else if(sx == abnorm || (sy == norm && dx > dy))
    {
        akt.isWritten = true;
        Read2();
    }
}

void mergeEnor::Read1()
{
    in1 >> dx;
    if(in1.fail())
    {
        sx = abnorm;
    }
}

void mergeEnor::Read2()
{
    in2 >> dy;
    if(in2.fail())
    {
        sy = abnorm;
    }
}
