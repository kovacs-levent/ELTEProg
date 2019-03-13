#ifndef SZAMLA_ENOR_H_INCLUDED
#define SZAMLA_ENOR_H_INCLUDED
#include "szamla.h"
#include <fstream>

class szamlaEnor
{
public:
    enum Status{norm, abnorm};
    enum Errors{FILE_ERROR};
    szamlaEnor(const std::string &filename);
    void First();
    void Next();
    bool End()
    {
        return sx == abnorm;
    }
    szamla Current()
    {
        return dx;
    }
    void Read();
    bool isNumber(const std::string &str);
private:
    szamla dx;
    Status sx;
    std::ifstream ifstr;
};

#endif // SZAMLA_ENOR_H_INCLUDED
