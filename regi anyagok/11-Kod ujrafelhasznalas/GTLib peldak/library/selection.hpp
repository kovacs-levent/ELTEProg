//Készítette:    Gregorics Tibor
//Dátum:         2017.08.31.
//Feladat:       Kiválasztás pprogramozási tételének ososztálya

#pragma once

#include "procedure.hpp"

//Lineáris keresés programozási tételét definiáló ősosztály-sablon, amely
//felüldefiniálja a Procedure ősosztály init(), body(), loopCond() metódusait. Ez utóbbi rugalmasságát
// egy újabb felülírandó/ható metódus (cond()) biztosítja,
//Sablonparaméterek:    Item  - a felsorolt elemek típusa
//Új műveletei:         result() az eredmény (megtalált Item típusó elem) lekérdezésére szolgálnak.
//Új virtuális metódus: cond() - az éppen felsorolt Item típusú elemhez egy logikai értéket rendel (keresés feltétele)
//Reprezentáció:  csak az ősosztályét (Procedure) használja
template < typename Item >
class Selection : public Procedure<Item>
{
protected:
    void init() override final {}
    void body(const Item& e) override final {}
    bool loopCond() const override final {
        return !cond(Procedure<Item>::_enor->current());
    }
    virtual bool cond(const Item& e) const = 0;
public:
    Item result() const {
        return Procedure<Item>::_enor->current();
    }
};


