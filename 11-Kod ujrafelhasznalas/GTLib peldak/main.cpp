#include <iostream>
#include <fstream>
#include "MyClasses.hpp"
#include "library\seqinfileenumerator.hpp"
#include "library\intervalenumerator.hpp"
///Feladatok:
///1. Számítsuk ki egy szöveges állományban elhelyezett egész számok összegét
///2. Válogassuk ki egy szoveges állományban elhelyezett számok közül a párosakat
/// írjuk ki egy output streamre (általános, konzolra, fájlra is működik)
///3. Igaz-e, hogy a fájlban az összes szám páros?
///4. Van-e a fájlban prím szám, ha igen, adjuk meg az elsőt.
///5. Mennyi az összege egy pozitív egész szám valódi osztóinak?

///Fontos! Az írt kódban nem szerepelhet ciklus és rekurzív hívás sem.
using namespace std;

void Osszeg();
void Kivalogat();
void Mindparos();
void VanPrim();
void OsztoOsszeg();

int main()
{
    int v;
    do
    {
        cout<<"\nMenu:\n";
        cout<<"0. Kilepes\n";
        cout<<"1. Fajlban levo egeszek osszege.\n";
        cout<<"2. Fajlban levo parosak kivalogatasa output fajlba.\n";
        cout<<"3. Igaz-e, hogy a fajlban levo osszes szam paros.\n";
        cout<<"4. Van-e a fajlban primszam.\n";
        cout<<"5. Valodi osztok osszege.";
        cout<<"\nMelyiket valasztod:"; cin>>v;
        switch(v)
        {
        case 1:
            Osszeg();
            break;
        case 2:
            Kivalogat();
            break;
        case 3:
            Mindparos();
            break;
        case 4:
            VanPrim();
            break;
        case 5:
            OsztoOsszeg();
            break;
        default:
            break;
        }
    }while(v!=0);
    return 0;
}

void Osszeg()
{
    cout << "\nOsszegzes, seqInfile" << endl;
    string fname;
    cout << "Kerem a fajl nevet:"; cin >> fname;
    MySum sum;
    SeqInFileEnumerator<int> enor(fname);
    sum.addEnumerator(&enor);
    sum.run();
    cout << sum.result() << std::endl;
}

void Kivalogat()
{
    cout << "\nOsszegzes, seqInfile" << endl;
    string fname;
    cout<<"Kerem a fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        std::ofstream ofstr("output.txt");
        Evens e(&ofstr);
        e.addEnumerator(&enor);
        e.run();
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
}

void Mindparos()
{
    cout << "\nOptlinker, seqInfile" << endl;
    string fname;
    cout<<"Kerem a bemenet fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        All_Even ae;
        ae.addEnumerator(&enor);
        ae.run();
        if(ae.found())
        {
            std::cout << "Mind paros volt!";
        }
        else
        {
            std::cout << "Nem volt mind paros, elso nem paros: " << ae.elem();
        }
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
}

void VanPrim()
{
    cout << "\nLinkerben, optlinker" << endl;
    string fname;
    cout<<"Kerem a bemenet fajl nevet:"; cin>>fname;
    try
    {
        SeqInFileEnumerator<int> enor(fname);
        Has_Prime hp;
        hp.addEnumerator(&enor);
        hp.run();
        if(hp.found())
        {
            std::cout << "Volt primszam a fajlban, a legelso: " << hp.elem();
        }
        else
        {
            std::cout << "Nem volt primszam a fajlban!";
        }
    }catch(...){
        cerr<<fname<<" fajl nem nyithato meg!\n";
    }
}

void OsztoOsszeg()
{
    std::cout << "Adja meg a szamot: ";
    int n;
    cin >> n;
    IntervalEnumerator enor(2, n/2);
    SumDivisors sd(n);
    sd.addEnumerator(&enor);
    sd.run();
    std::cout << sd.result();
}
