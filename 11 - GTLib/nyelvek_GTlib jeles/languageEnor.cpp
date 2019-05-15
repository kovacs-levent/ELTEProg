#include "languageEnor.h"

void languageEnor::next()
{
    isEnd = f.end();
    if(!isEnd)
    {
        actLanguage.name = f.current().name;
        actLanguage.wasUnpopular = f.current().wasUnpopular;
        alwaysUnpopular e(actLanguage.name, actLanguage.wasUnpopular);
        e.addEnumerator(&f);
        e.run();
        actLanguage.wasUnpopular = e.result();
    }
}
