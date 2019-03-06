#ifndef OUTFILE_H_INCLUDED
#define OUTFILE_H_INCLUDED
#include <fstream>
#include "kaktusz.h"

class OutFile
{
public:
    OutFile(const std::string &output);
    void write(const kaktusz &dx);
private:
    enum FileError{FILE_ERROR};
    std::ofstream ofstr;
};


#endif // OUTFILE_H_INCLUDED
