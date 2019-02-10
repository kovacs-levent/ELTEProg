//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Általános maximum keresés

#pragma once

#include "procedure.hpp"

//"Nagyobb" relációt szolgáltató osztály-sablon
//Műveletek: operátor()
//Sablon paraméterek: Value - az összehasonlítandó elemek típusa
template <typename Value> // Value implementálja az operator>()-t
class Greater{
    public:
        bool operator()(const Value& l, const Value& r){
            return l > r;
        }
};

//"Nagyobb" relációt szolgáltató osztály-sablon
//Műveletek: operátor()
//Sablon paraméterek: Value - az összehasonlítandó elemek típusa
template <typename Value> // Value implementálja az operator<()-t
class Less{
    public:
        bool operator()(const Value& l, const Value& r){
            return l < r;
        }
};

//Általános maximumkeresés programozási tételét definiáló ősosztály-sablon, amely
//felüldefiniálja a Procedure ősosztály init(), body() metódusait. Ez utóbbi rugalmasságát
//az eddigiek mellett két újabb felülírandó/ható metódus (func(), cond()) biztosítja,
//Sablonparaméterek:      Item  - a felsorolt elemek típusa
//                        Value - az összehasonlítandó értékek típusa
//                        Compare - az összehasonlító operátort szolgáltató típus
//Új metódusok:           found(), opt(), optElem() az Item típusú eredmény és annak Value típusú értékének lekérdezésére szolgálnak.
//Új virtuális metódusok: func() - az éppen  felsorolt Item típusú elemhez egy Value típusú értéket rendel
//                        cond() - az éppen  felsorolt Item típusú elemhez egy logikai értéket rendel (feltételes maximumkeresés)
//Reprezentáció:        bool _l       - a feltétel maximum keresés logikai változója
//                      Item _optelem - a feltétel maximum keresés addig talált legjobb Item típusú eleme
//                      Value _opt    - a feltétel maximum keresés addig talált legjobb Item típusú elemének Value típusú értéke
//                      Compare _better - Value értékeket összehasonlító objektum
template <typename Item, typename Value = Item, typename Compare = Greater<Value> >
class MaxSearch : public Procedure<Item>
{
protected:
    bool    _l;
    Item    _optelem;
    Value   _opt;
    Compare _better;

    void init() final override { _l = false;}
    void body(const Item& e) final override;

    virtual Value func(const Item& e) const = 0;
    virtual bool  cond(const Item& e) const { return true;}

public:
    bool found()   const { return _l;}
    Value opt()    const { return _opt;}
    Item optElem() const { return _optelem;}
};

// Általános maximumkeresés ciklusmagjának váza
// virtuális metódusok: (func(), cond())
template <class Item, class Value, class Compare>
void MaxSearch<Item,Value,Compare>::body(const Item& e)
{
    Value val = func(e);
    if ( !cond(e) ) return;
    if (_l){
        if (_better(val,_opt)){
            _opt = val;
            _optelem = e;
        }
    }
    else {
        _l = true;
        _opt = val;
        _optelem = e;
    }
}

