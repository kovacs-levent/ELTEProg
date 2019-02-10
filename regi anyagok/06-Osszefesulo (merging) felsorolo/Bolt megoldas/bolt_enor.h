#ifndef BOLT_ENOR_H_INCLUDED
#define BOLT_ENOR_H_INCLUDED
#include "infile.h"
#include "rendeles.h"
#include <cstdlib>

class bolt_enor
{
public:
    bolt_enor(const std::string &input1, const std::string &input2) : in_f1(input1), in_f2(input2)
    {
        ofstr.open("output.txt");
        if(ofstr.fail())
        {
            exit(1);
        }
    }

    void First()
    {
        in_f1.Read();
        in_f2.Read();
    }

    void Next();

    rendeles Current() const
    {
        return akt;
    }

    bool End()
    {
        return isEnd;
    }
private:
    std::ofstream ofstr;
    InFile in_f1;
    InFile in_f2;
    rendeles akt;
    bool isEnd;
};

#endif // BOLT_ENOR_H_INCLUDED
