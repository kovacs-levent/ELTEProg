#include "webpageEnor.h"

void webpageEnor::next()
{
    isEnd = f.end();
    if(!isEnd)
    {
        actpage.url = f.current().url;
        unpopular up(actpage.url, f.current().onceUnpopular);
        up.addEnumerator(&f);
        up.run();
        actpage.onceUnpopular = up.result();
    }
}
