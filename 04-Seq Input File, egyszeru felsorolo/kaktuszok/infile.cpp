#include "infile.h"

InFile::InFile(const std::string &input)
{
    ifstr.open(input.c_str());
    if(ifstr.fail())
    {
        throw FILE_ERROR;
    }
    sx = norm;
}

void InFile::read()
{
    ifstr >> dx.nev;
    ifstr >> dx.haza;
    ifstr >> dx.szin;
    ifstr >> dx.meret;
    if(ifstr.fail())
    {
        sx = abnorm;
    }
}
