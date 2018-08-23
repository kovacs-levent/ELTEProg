#include "bolt_enor.h"

void bolt_enor::Next()
{
    if(in_f1.sx == norm)
    {
    if(in_f2.sx == abnorm || in_f1.dx.aru < in_f2.dx.aru)
    {
        ofstr << in_f1.dx.aru << " " << in_f1.dx.db << std::endl;
        akt = in_f1.dx;
        in_f1.Read();
    }
    else if(in_f1.dx.aru == in_f2.dx.aru)
    {
        in_f1.dx.db -= in_f2.dx.db;
        if(in_f1.dx.db > 0)
        {
            in_f1.dx.sold = true;
            ofstr << in_f1.dx.aru << " " << in_f1.dx.db << std::endl;
        }
        akt = in_f1.dx;
        in_f1.Read();
        in_f2.Read();
    }
    else if(in_f1.dx.aru > in_f2.dx.aru)
    {
        in_f1.dx.written = true;
        akt = in_f1.dx;
        in_f2.Read();
    }
    }
    else
    {
        isEnd = true;
    }
}
