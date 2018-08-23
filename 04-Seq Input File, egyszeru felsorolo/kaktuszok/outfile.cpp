#include "outfile.h"

OutFile::OutFile(const std::string &output)
{
    ofstr.open(output.c_str());
    if(ofstr.fail())
    {
        throw FILE_ERROR;
    }
}

void OutFile::write(const kaktusz &dx)
{
    ofstr << dx.nev << " " << dx.haza << " " << dx.szin << " " << dx.meret << std::endl;
}
