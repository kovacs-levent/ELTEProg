//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Intervallum felsoroló ososztálya

#pragma once

#include "enumerator.hpp"

//Intervallum elemeinek felsorolását definiáló osztály
//Műveletek: first(), next(), end(), current()
//Reprezentáció:_m, _n - intervallum eleje és vége
//              _ind  - a felsorolás indexe

class IntervallEnumerator : public Enumerator<int>
{
private:
    int _m, _n;
    int _ind;
public:
    IntervallEnumerator(int m, int n): _m(m), _n(n) {}
    void first() override { _ind = _m;}
    void next() override { ++_ind; }
    int current() const override { return _ind; }
    bool end() const override { return _ind>_n; }
};
