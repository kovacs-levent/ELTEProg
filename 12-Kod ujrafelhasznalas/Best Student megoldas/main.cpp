///K�sz�tette: Kov�cs Levente
///D�tum: 2018.03.30.
///Feladat:
///Ki a kurzus legjobb hallgat�ja? A hallgat�k nev�t �s r�szeredm�ny�t (0 �s 5 k�z�tti jegy)
///egy-egy sorban, ugyanazon nev� hallgat� sorai k�zvetlen�l egym�s ut�n adtuk meg egy
///sz�veges �llom�nyban.
#include <iostream>
#include "BestStudent.h"
#include "StudentEnumerator.h"

using namespace std;

int main()
{
    BestStudent best_student_test;
    StudentEnumerator st_enor("input.txt");
    best_student_test.addEnumerator(&st_enor);
    best_student_test.run();
    if(best_student_test.found())
    {
        cout << best_student_test.optElem().name << " " << best_student_test.opt() << endl;
    }
    else
    {
        cout << "Nem volt nem bukott hallgato!";
    }
    return 0;
}
