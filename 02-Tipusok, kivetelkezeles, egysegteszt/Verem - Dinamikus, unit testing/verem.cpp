//Készítette:    Veszprémi Anna
//Dátum:         2018.02.16.
//Feladat:       Verem típus megvalósítása
//Megjegyzés:    vector típus veremnek kedvező műveleteire támaszkodik: pus_back, pop_back, back

#include "verem.h"
#include <iostream>

using namespace std;

//Feladat: berak egy egész értéket a verembe
//Bemenet: Verem this - Verem
//         e - egész
//Kimenet: Verem this - Verem
//Tevékenység: a paraméterben kapott értéket beteszi a verembe
void Verem::verembe(int e)
{
    _vec.push_back(e);
}

//Feladat: kiveszi a verem tetején lévõ értéket
//Bemenet: Verem this - Verem
//Kimenet: Verem this - Verem
//         e - egész
//Tevékenység: kiveszi a verembõl a legfelsõ elemet
//             nulla elemet tartalmazó Verem esetén hibát dob
int Verem::verembol()
{
    if((int)_vec.size()==0) throw UresVerem;
    int e=_vec.back();
    _vec.pop_back();
    return e;
}

//Feladat: visszaadja a verem tetején lévõ értéket
//Bemenet: Verem this - Verem
//Kimenet: e - egész
//Tevékenység: a verem tetejét kiolvassa
//             nulla elemet tartalmazó Verem esetén hibát dob
int Verem::teto() const
{
    if((int)_vec.size()==0) throw UresVerem;
    int e=_vec.back();
    return e;
}
