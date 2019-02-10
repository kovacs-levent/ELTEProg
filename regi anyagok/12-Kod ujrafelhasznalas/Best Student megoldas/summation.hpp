//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Összegzés programozási tétele

#pragma once

#include "procedure.hpp"

//Összegzés programozási tételét definiáló ősosztály-sablon, amely
//felüldefiniálja a Procedure ősosztály body() metódusát. Ez utóbbi rugalmasságát
//az eddigiek mellett két újabb felülírandó/ható sablonfüggvény (add(), cond()) biztosítja.
//Sablonparaméterek:        Item  - a felsorolt elemek típusa
//                          Range - az összegzés eredményének típusa
//Új művelete:              result(), a Range típusú eredmény lekérdezésére szolgál.
//Új virtuális metódusok:   add() - az éppen felsorolt Item típusú elem alapján módosítja a Range típusú eredményt
//                          cond()- az éppen felsorolt Item típusú elemhez egy logikai értéket rendel (feltételes összegzés)
//Konstruktorai: Egyik konstruktora dinamikusan foglalja le az összegzés eredményét tároló Range típusú memóriahelyet,
//               a másik kivülről kapja meg ennek memóriacímét.
//Reprezentáció:        Range* _result- az összegzés eredményére mutató pointer
//                      bool _inref   - jelzi, hogy az összegzés eredményénak memóriahelyét a konstruktorban foglaltuk-e le.
template < typename Item, typename Range = Item >
class Summation : public Procedure<Item>
{
protected:
    Range *_result;
    bool _inref;

    Summation(){ _inref = true; _result = new Range; }
    Summation(Range *r){ _inref = false; _result = r; }
    //virtual void init() = 0;
    void body(const Item& e) final override { if(cond(e)) add(e); }
    virtual void add(const Item& e) = 0;
    virtual bool cond(const Item& e) const { return true;}
public:
    Range result() const { return *_result; }
    ~Summation(){ if(_inref) delete _result;}
};

