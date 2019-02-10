//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Menürendszer forráskód
//Feladat:       A menüpontok a prioritásos sor típus műveleteit meghívják, majd
//               a művelet lefutása után mindig kiírják a sor jellemzőit.
//               Külön tesztelhető a copy konstruktor és az értékadás operátor.
//               Terhelés teszttel vizsgálható a memória kapacitás.

#include <iostream>
#include "menu.h"

using namespace std;


Menu::Menu(int meret):
Q(meret)
{
    cout<<"A"<<meret<<" meretu prioritasos sor letrejott\n";
}

void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                Sorba();
                KiirSor();
                break;
            case 2:
                Sorbol();
                KiirSor();
                break;
            case 3:
                Legnagyobb();
                KiirSor();
                break;
            case 4:
                Urese();
                KiirSor();
                break;
            case 5:
                KiirSor();
                break;
            case 6:
                CopyTeszt();
                break;
            case 7:
                ErtekadasTeszt();
                break;
            case 8:
                TerhelesTeszt();
                break;
            default:
                cout<<"\nViszontlatasra!\n";
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    const int n=8;
    int valasz;
    cout<<"\n****************************************\n";
    cout<<"0. Kilepes\n";
    cout<<"1. Prior sorba berak\n";
    cout<<"2. Legnagyobbat kivesz\n";
    cout<<"3. Legnagyobbat lekerdez\n";
    cout<<"4. Ures-e vizsgalat\n";
    cout<<"5. Sort kiir\n";
    cout<<"6. Copy konstruktor tesztelese\n";
    cout<<"7. Ertekadas operator tesztelese\n";
    cout<<"8. Terheles teszt (mennyi elemet tudunk a sorba tenni)\n";
    cout<<"****************************************\n";
    do{
        cout<<"Valasztas:";
        cin>>valasz;
    }while(valasz<0 || valasz>n);
    return valasz;
}

void Menu::Sorba()
{
    Elem e;
    cout<<"Mit tegyunk be?";
    cin >> e;
    Q.prSorba(e);
}

void Menu::Sorbol()
{
    Elem e;
    bool hiba=false;
    try{
        e=Q.maxKivesz();
    }catch(PrSor::PrSorHiba err)
    {
        hiba=true;
        if(err==PrSor::URES_PRSOR)
            cerr<<"A kiveves nem sikerult! A pr.sor ures!\n";
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
    if(!hiba) cout<<"Kivett elem:\n"<<e<<endl;
}

void Menu::Legnagyobb()
{
    Elem e;
    bool hiba=false;
    try{
        e=Q.max();
    }catch(PrSor::PrSorHiba err)
    {
        hiba=true;
        if(err==PrSor::URES_PRSOR)
            cerr<<"A vizsgalat nem sikerult! A pr.sor ures!\n";
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
    if (!hiba) cout<<"Legnagyobb elem:\n"<<e<<endl;
}

void Menu::Urese()
{
    if(Q.ures_e())
        cout<<"A pr.sor ures.\n";
    else
        cout<<"A pr.sor nem ures.\n";
}

void Menu::KiirSor()
{
    cout<<Q;
}

void Menu::CopyTeszt()
{
    //Készítünk egy másolatot Q sorról
    PrSor Q1(Q);
    //PrSor Q1=Q; //Ez is jó
    cout<<"Az eredeti Q sor:"<<Q;
    cout<<"A masolat Q1 sor:"<<Q1;
    Elem a;

    //Megváltoztatjuk az erdeti sort, majd a másolat sort, majd kiíratjuk.
    //Ha a kettő különbözik, akkor a másolás sikeres volt.
    cout<<"Tegyen valamit az eredeti sorba (Q):";
    cin>>a;
    Q.prSorba(a);

    cout<<"Tegyen valamit a masolat sorba (Q1):";
    cin>>a;
    Q1.prSorba(a);

    cout<<"Ellenorizze, hogy a ket sor valoban kulonbozik-e!\n";
    cout<<"Q="<<Q;
    cout<<"Q1="<<Q1;
}

void Menu::ErtekadasTeszt()
{
    cout<<"Eredeti Q sor pillanatnyi tartalma:"<<Q;
    cout<<"Letrehozunk egy uj Q1 sort (ez kapja majd ertekul az eredeti sort).\n";
    int m;
    cout<<"Mi legyen a merete:";
    cin>>m;
    //Itt tesztelhetjük azt a kivételt, ha negatív vagy nulla méretet
    //adunk meg a sor konstruktorának.
    try{
        PrSor Q1(m);
        cout<<"Tegyen valamit Q1 sorba!\n";
        Elem e;
        cin>>e;
        Q1.prSorba(e);
        cout<<"Az elem berakasa utan Q1 tartalma:";
        cout<<Q1;
        Q1=Q;
        cout<<"Q1=Q ertekadas utan a Q1 tartalma:\n"<<Q1;
        cout<<"Ertekadas utan Q tartalma:\n"<<Q;
        cout<<"Tegyen valamit Q1 sorba!\n";
        cin>>e;
        Q1.prSorba(e);
        cout<<"Q1 sor tartalma a beteves utan:\n"<<Q1;
        cout<<"Tegyen valamit Q sorba!\n";
        cin>>e;
        Q.prSorba(e);
        cout<<"Q sor tartalma a beteves utan:\n"<<Q;
        Q=Q; //önmagának történő értékadása tesztelése
        cout<<"Q=Q ertekadas utan Q tartalma:\n";
        cout<<Q<<endl;

    }catch(PrSor::PrSorHiba err){
        if (err==PrSor::HIBAS_MERET)
            cerr<<"Rossz a sor meret!\n";
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
}

void Menu::TerhelesTeszt()
{
    const int meret=1000000000;
    PrSor Q;
    cout<<"A sor pillanatnyi elemszamat kovetheti:\n";
    try{
        for(int i=1; i<meret; ++i)
        {
            if(i%1000000==0) cout<<i<<endl;
            Q.prSorba(Elem(i,"a"));
        }
    }catch(PrSor::PrSorHiba err)
    {
        if (err==PrSor::NINCS_ELEG_MEMORIA){
            cerr<<"Elfogyott a memoria!\n";
            cout<<"Sor hossza:"<<Q.getHossz()<<endl;
            cout<<"Tomb merete:"<<Q.getMeret()<<endl;
        }
        else
            cerr<<"Programhiba, forduljon a program keszitojehez :-))\n";
    }
}

