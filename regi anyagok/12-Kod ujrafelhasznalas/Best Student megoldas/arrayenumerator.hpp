//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Tömbök felsorolóinak ososztálya

#pragma once

#include "enumerator.hpp"
#include <vector>

//Tömb elemeinek felsorolását definiáló osztály-sablon
//Műveletek: first(), next(), end(), current()
//Reprezentáció:_vect - a felsorolni kívánt tömb
//              _ind  - a felsorolás indexe
template <typename Item>
class ArrayEnumerator : public Enumerator<Item>
{
    protected:
        std::vector<Item> *_vect;
        int   _ind;

    public:
        ArrayEnumerator(std::vector<Item> *v):_vect(v) {}

        void first()  final override { _ind = 0;}
        void next()   final override{ ++_ind; }
        bool end()    const final override { return _ind>=(int)_vect->size();}
        Item current()const final override { return (*_vect)[_ind];}
};

