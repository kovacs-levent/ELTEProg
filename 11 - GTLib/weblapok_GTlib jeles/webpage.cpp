#include "webpage.h"

std::istream& operator>>(std::istream& istr, webpage& w)
{
    std::string str;
    getline(istr, str);
    std::stringstream i_sstr(str);
    i_sstr >> w.url;
    i_sstr >> w.date;
    StringStreamEnumerator<entry> enor(i_sstr);
    entrySum e;
    e.addEnumerator(&enor);
    e.run();
    w.bouncerate = (double)e.result().bouncecount/(double)e.result().visitcount;
    w.onceUnpopular = e.result().bouncecount > 2;
    return istr;
}
