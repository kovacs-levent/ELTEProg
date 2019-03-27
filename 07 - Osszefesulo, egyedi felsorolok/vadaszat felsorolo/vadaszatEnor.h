#ifndef VADASZATENOR_H_INCLUDED
#define VADASZATENOR_H_INCLUDED
#include <fstream>
#include "zsakmany.h"

class vadaszatEnor
{
public:
    enum status{norm, abnorm};
    enum fileError{OPEN_ERROR};
    vadaszatEnor(const std::string &filename);
    void First();
    void Next();
    void Read();
    vadasz Current()
    {
        return akt;
    }
    bool End()
    {
        return isEnd;
    }
private:
    std::ifstream instr;
    vadasz akt, next;
    bool isEnd;
    status sx;
};

#endif // VADASZATENOR_H_INCLUDED
