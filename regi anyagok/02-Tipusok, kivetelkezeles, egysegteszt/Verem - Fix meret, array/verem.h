//K�sz�tette:    Veszpr�mi Anna
//D�tum:         2018.02.16.
//Feladat:       Verem t�pus megval�s�t�sa
#ifndef VEREM_H_INCLUDED
#define VEREM_H_INCLUDED
#include <vector>

class Verem{

public:
   enum Hiba{UresVerem,HibasMeret};
   Verem(); //�res konstruktor
   Verem(int m); //Adott m�ret� verem
   bool ures_e() const {return _p==-1;};
   void verembe(int e);
   int verembol();
   int teto() const;
private:
   int _verem_meret;
   std::vector<int> _vec;
   int _p;
};


#endif // VEREM_H_INCLUDED
