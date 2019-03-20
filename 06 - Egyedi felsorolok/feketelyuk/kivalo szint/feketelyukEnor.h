#ifndef FEKETELYUKENOR_H_INCLUDED
#define FEKETELYUKENOR_H_INCLUDED
#include "feketelyuk.h"
#include <fstream>

///Egyedi, csoportosított felsorolóknál kénytelenek vagyunk elõreolvasni a fájlba,
///hogy el tudjuk dönteni mikor van vége a jelenlegi csoportnak.
///Két felsorolandó rekordra van szükség, általában ezeket akt-ként és next-ként szoktuk elnevezni.
///Az akt-ban lesz a ténylegesen felsorolt objektum (ezt a next-ben állítjuk elõ progtétellel), a next-be olvasunk

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
        return akt;
    }
    bool End()
    {
        return isEnd;
    }
    void Read();
private:
    std::ifstream ifstr;
    bool isEnd;
    feketelyuk akt;
    feketelyuk next;
    Status sx;
};

#endif // FEKETELYUKENOR_H_INCLUDED
