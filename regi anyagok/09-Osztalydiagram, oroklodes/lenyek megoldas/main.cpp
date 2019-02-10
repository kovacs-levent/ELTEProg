#include <iostream>
#include <fstream>
#include <vector>
#include "creature.h"

using namespace std;

int main()
{
   ifstream f("inp.txt");
   if(f.fail())
   {
        cout << "Nincs meg a fájl\n";
        return 0;
   }

   // Lények létrehozása
    int n;
    f >> n;
    vector<Creature*> creature(n);
    for(int i=0; i<n; ++i){
        char ch;
        string name;
        f >> ch >> name;
        switch(ch){
        case 'G' : creature[i] = new Greenfinch(name); break;
        case 'B' : creature[i] = new Sandbug(name);    break;
        case 'S' : creature[i] = new Squelchy(name);   break;
        }
    }

   // Pálya betöltése
    int m;
    f >> m;
    vector<int> court(m);
    for(int j=0; j<m; ++j) f >> court[j];

   // Verseny
    for(int i=0; i<n; ++i)
    {
        for(int j=0; creature[i]->alive() && j<m; ++j)
        {
            creature[i]->transmute(court[j]);
        }
        if (creature[i]->alive()) cout << creature[i]->name() << endl;
    }

   // Lények megszüntetése
   for(int i=0; i<n; ++i) delete creature[i];

   return 0;
}
