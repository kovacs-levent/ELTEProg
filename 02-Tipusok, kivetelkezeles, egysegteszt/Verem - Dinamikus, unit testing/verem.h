//K�sz�tette:    Veszpr�mi Anna
//D�tum:         2018.02.16.
//Feladat:       Verem t�pus megval�s�t�sa

#ifndef VEREM_H_INCLUDED
#define VEREM_H_INCLUDED
#include <vector>

//Eg�sz sz�mokat t�rol� verem megval�s�t�sa vector-ral
class Verem{
public:
   enum Hiba{UresVerem};
   //Verem(){} //konstruktor, nincs teend�, elhagyhat�
   bool ures_e() const {return (int)_vec.size()==0;};
   void verembe(int e);
   int verembol();
   int teto() const;
   //Tesztel�st seg�t� met�dus
   std::vector<int> mutasd() {return _vec;}
private:
   std::vector<int> _vec;
};


#endif // VEREM_H_INCLUDED
