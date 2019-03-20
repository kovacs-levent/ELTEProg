#ifndef FEKETELYUKENOR_H_INCLUDED
#define FEKETELYUKENOR_H_INCLUDED
#include "feketelyuk.h"
#include <fstream>

///Egyedi, csoportos�tott felsorol�kn�l k�nytelenek vagyunk el�reolvasni a f�jlba,
///hogy el tudjuk d�nteni mikor van v�ge a jelenlegi csoportnak.
///K�t felsoroland� rekordra van sz�ks�g, �ltal�ban ezeket akt-k�nt �s next-k�nt szoktuk elnevezni.
///Az akt-ban lesz a t�nylegesen felsorolt objektum (ezt a next-ben �ll�tjuk el� progt�tellel), a next-be olvasunk

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
