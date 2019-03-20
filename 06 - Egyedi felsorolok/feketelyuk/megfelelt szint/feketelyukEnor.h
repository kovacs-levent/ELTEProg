#ifndef FEKETELYUKENOR_H_INCLUDED
#define FEKETELYUKENOR_H_INCLUDED
#include "feketelyuk.h"
#include <fstream>

class feketelyukEnor
{
public:
    enum Error{OPEN_ERROR};
    enum Status{norm, abnorm};
    feketelyukEnor(const std::string &filename);
    void First();
    void Next();
    feketelyuk Current()
    {
        return dx;
    }
    bool End()
    {
        return sx == abnorm;
    }
    void Read();
private:
    std::ifstream ifstr;
    feketelyuk dx;
    Status sx;
};

#endif // FEKETELYUKENOR_H_INCLUDED
