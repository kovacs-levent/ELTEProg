#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED
#include <fstream>
#include "kaktusz.h"

enum Status{abnorm, norm};
class InFile
{
public:
    InFile(const std::string &input);
    void read();
    kaktusz GetDx() const
    {
        return dx;
    }
    Status getSx() const
    {
        return sx;
    }
private:
    std::ifstream ifstr;
    enum FileError{FILE_ERROR};
    kaktusz dx;
    Status sx;
};

#endif // INFILE_H_INCLUDED
