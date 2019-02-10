//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Számlálás programozási tételének ősosztálya

#pragma once

#include "summation.hpp"

//Számlálás programozási tételét definiáló ősosztály-sablon, amely
//felüldefiniálja a Summation ősosztály init() és add() metódusát, de a rugalmasságát
//az eddigi felülírandó/ható metódusok biztosítják, elsősorban a cond().
//Sablonparaméterek:   Item - a felsorolt elemek típusa
//Új művelete:              -
//Új virtuális metódusok:   -
//Reprezentáció: csak az ősosztályokét (Procedure, Summation) használja
template < typename Item >
class Counting : public Summation<Item, int>
{
public:
    Counting():Summation<Item,int>() {}

protected:
    void init() override final {
        *Summation<Item,int>::_result = 0;
    }
    void add(const Item& e) override final {
        ++*Summation<Item,int>::_result;
    }
};
