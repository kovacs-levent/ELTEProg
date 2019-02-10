//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Szekvenciális inputfájl felsorolóinak ososztálya

#pragma once

#include <fstream>
#include <typeinfo>

#include "enumerator.hpp"

//Szöveges állomány szekvenciális inputfájlkénti felsorolását definiáló osztály-sablon
//Műveletek: first(), next(), end(), current()
//Reprezentáció:_f - a felsorolni kívánt szöveges állomány
//              _df  - az éppen felsorolt Item típusú elem
template <typename Item>  // Item implementálja az operator>>-t
class SeqInFileEnumerator : public Enumerator<Item>
{
    protected:
        std::ifstream _f;
        Item          _df;

    public:
        enum Exceptions { OPEN_ERROR };
        SeqInFileEnumerator(const std::string& str){
            _f.open(str.c_str());
            if(_f.fail()) throw OPEN_ERROR;
            if(typeid(Item)==typeid(char)) _f.unsetf(std::ios::skipws);
        }

        void first()         final override { next();}
        void next()          final override { _f >> _df;}
        bool end()     const final override { return _f.eof();}
        Item current() const final override { return _df; }
};

