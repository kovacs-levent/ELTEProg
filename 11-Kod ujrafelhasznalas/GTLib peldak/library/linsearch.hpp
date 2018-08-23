//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Lineáris keresés programozási tételének ősosztálya

#pragma once

#include "procedure.hpp"

//Lineáris keresés programozási tételét definiáló ősosztály-sablon, amely
//felüldefiniálja a Procedure ősosztály init(), whileCond(), body() metódusait. Ez utóbbi rugalmasságát
//az eddigiek mellett egy újabb felülírandó/ható metódus (cond()) biztosítja,
//Sablonparaméterek:    Item          - a felsorolt elemek típusa
//                      bool optimist - pesszimista illetve optimista keresés beállítására szolgál
//Új műveletei:         found(), elem(), a megtalált Item típusú eredmény lekérdezésére szolgálnak.
//Új virtuális metódus: cond() - az éppen felsorolt Item típusú elemhez egy logikai értéket rendel (keresés feltétele)
//Reprezentáció:        bool _l    - a lineáris keresés logikai változója
//                      Item _elem - a lineáris keresés aktuálisan vizsgált eleme
template < typename Item, bool optimist = false>
class LinSearch : public Procedure<Item>
{
protected:
    bool _l;
    Item _elem;

    void init() final override { _l = optimist; }
    void body(const Item& e) final override { _l = cond(_elem = e); }
    bool whileCond(const Item& e) const final override { return optimist?_l:!_l;}

    virtual bool cond(const Item& e) const = 0;

public:
    bool found()  const{ return _l; }
    Item elem()   const{ return _elem;}
};

