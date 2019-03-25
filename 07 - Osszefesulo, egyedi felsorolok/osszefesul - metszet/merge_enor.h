#ifndef MERGE_ENOR_H_INCLUDED
#define MERGE_ENOR_H_INCLUDED
#include <fstream>
#include "elem.h"

class mergeEnor
{
public:
    enum status{norm, abnorm};
    enum File_Error{OPEN_ERROR};
    mergeEnor(const std::string &file1, const std::string& file2);
    void First();
    void Next();
    elem Current()
    {
        return akt;
    }
    bool End()
    {
        return isEnd;
    }
    void Read1();
    void Read2();
private:
    std::ifstream in1, in2;
    bool isEnd;
    status sx, sy;
    int dx, dy;
    elem akt;
};

#endif // MERGE_ENOR_H_INCLUDED
