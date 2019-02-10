#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED
#include "rendeles.h"
#include <fstream>

enum status{norm, abnorm};

class InFile
{
public:
    InFile(const std::string &input);
    void Read();
    rendeles dx;
    status sx;
private:

    std::ifstream ifstr;
};
#endif // INFILE_H_INCLUDED
