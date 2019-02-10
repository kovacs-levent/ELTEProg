#include "infile.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

InFile::InFile(const std::string& input)
{
    ifstr.open(input.c_str());
    if(ifstr.fail())
    {
        std::cout << "Hiba a fajl megnyitasa kozben!";
        exit(1);
    }
    sx = norm;
}

void InFile::Read()
{
    std::stringstream sstr;
    std::string line;
    getline(ifstr, line);
    if(ifstr.fail() || line.length() == 0)
    {
        sx = abnorm;
    }
    else
    {
        std::string tmp;
        sstr.str(line);
        sstr >> dx.aru;
        sstr >> tmp;
        while(!isdigit(tmp[0]))
        {
            dx.aru = dx.aru+" "+tmp;
            sstr >> tmp;
        }
        dx.db = atoi(tmp.c_str());
    }
    dx.sold = false;
    dx.written = false;
}
