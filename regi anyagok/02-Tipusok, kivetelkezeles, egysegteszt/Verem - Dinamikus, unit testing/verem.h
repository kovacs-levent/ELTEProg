//Készítette:    Veszprémi Anna
//Dátum:         2018.02.16.
//Feladat:       Verem típus megvalósítása

#ifndef VEREM_H_INCLUDED
#define VEREM_H_INCLUDED
#include <vector>

//Egész számokat tároló verem megvalósítása vector-ral
class Verem{
public:
   enum Hiba{UresVerem};
   //Verem(){} //konstruktor, nincs teendõ, elhagyható
   bool ures_e() const {return (int)_vec.size()==0;};
   void verembe(int e);
   int verembol();
   int teto() const;
   //Tesztelést segítõ metódus
   std::vector<int> mutasd() {return _vec;}
private:
   std::vector<int> _vec;
};


#endif // VEREM_H_INCLUDED
