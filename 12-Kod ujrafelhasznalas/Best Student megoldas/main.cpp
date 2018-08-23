///Készítette: Kovács Levente
///Dátum: 2018.03.30.
///Feladat:
///Ki a kurzus legjobb hallgatója? A hallgatók nevét és részeredményét (0 és 5 közötti jegy)
///egy-egy sorban, ugyanazon nevû hallgató sorai közvetlenül egymás után adtuk meg egy
///szöveges állományban.
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
