#include "nyelv.h"

std::istream& operator>>(std::istream& istr, language &l)
{
    std::string str;
    std::getline(istr, str);
    std::stringstream sstr(str);
    sstr >> l.name;
    sstr >> l.indexName;
    StringStreamEnumerator<entry> enor(sstr);
    entrySum e;
    e.addEnumerator(&enor);
    e.run();
    l.avgPopularity = (double)e.result().sum/(double)e.result().count;
    l.wasUnpopular = e.result().wasUnpopular;
    return istr;
}
