//Készítette:    Veszprémi Anna
//Dátum:         2018.02.16.
//Feladat:       Verem típus megvalósítása
//Megjegyzés:    Tömbös szemléletű nem használja ki a vector speciális műveleteit (pus_back(), pop_back(), back())

#include "verem.h"
#include <iostream>

using namespace std;

//Paraméter nélkül hívható konstruktor
//Tevékenység: 100 méretű tömböt foglal le a veremnek
//             üresre állítja a vermet
Verem::Verem()
{
    _verem_meret=100;
    _vec.resize(_verem_meret);
    _p=-1; //Nullás index miatt p=-1, ha üres a verem!
}

//Paraméterrel hívható konstruktor
//Tevékenység: a paraméterben megadott méretű tömböt foglal le a veremnek
//             üresre állítja a vermet
//             hibát dob, ha a megadott méret helytelen (<=0)
Verem::Verem(int m)
{
    if(m<=0) throw HibasMeret;
    _verem_meret=m;
    _vec.resize(_verem_meret);
    _p=-1;
}

//Feladat: berak egy egész értéket a verembe
//Bemenet: Verem this - Verem
//         e - egész
//Kimenet: Verem this - Verem
//Tevékenység: a paraméterben kapott értéket beteszi a verembe
//             ha a vector megtelt, duplájára növeli a méretét
void Verem::verembe(int e)
{
    if(_p==_verem_meret-1)
    {
        _verem_meret*=2;
        _vec.resize(_verem_meret);
    }
    _vec[++_p]=e;
}

//Feladat: kiveszi a verem tetején lévő értéket
//Bemenet: Verem this - Verem
//Kimenet: Verem this - Verem
//         e - egész
//Tevékenység: kiveszi a veremből a legfelső elemet
//             nulla elemet tartalmazó Verem esetén hibát dob
int Verem::verembol()
{
    if(_p==-1) throw UresVerem;
    int e=_vec[_p];
    --_p;
    return e;
}

//Feladat: visszaadja a verem tetején lévő értéket
//Bemenet: Verem this - Verem
//Kimenet: e - egész
//Tevékenység: a verem tetejét kiolvassa
//             nulla elemet tartalmazó Verem esetén hibát dob
int Verem::teto() const
{
    if(_p==-1) throw UresVerem;
    return _vec[_p];
}
