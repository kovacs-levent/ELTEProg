//Készítette:    Veszprémi Anna
//Dátum:         2018.02.16.
//Feladat:       Verem típus megvalósítása
//               Egy zárójelekből álló szövegen a helyes zárójelezés vizsgálata,
//               az összetartozó helyes zárójelpárok indexének kiírása
//Tesztelés:     külön megírt teszt függvények alkalmazásával

#include <iostream>
#include "verem.h"

using namespace std;

//Tesztelő függvények a Verem osztályhoz
void TesztVerem();
void TesztKivetel();

//Helyes zárójelezés programja
int main()
{
    cout << "Helyes zarojelezes" << endl;
    string X;
    cout<<"Kerek egy zarojelekbol allo szoveget:\n";
    cin>>X;
    Verem V;
    bool helyes=true;
    int i=0;
    while(helyes && i<(int)X.size())
    {
        if(X[i]=='(')
        {
            V.verembe(i);
        }else if(X[i]==')')
        {
            if(!V.ures_e())
            {
                int k=V.verembol();
                cout<<"("<<k+1<<","<<i+1<<") ";
            }else{
                helyes=false;
                cerr<<"\nVaratlan csuko zarojel.\n";
            }
        }else{
            cerr<<X[i]<<" hiba a szoveg "<<i+1<<". poziciojan!";
        }
        ++i;
    }
    if(!V.ures_e())
    {
        cout<<"\nTobb nyito, mint csuko zarojel.\n";
    }
    helyes=helyes && V.ures_e();
    if(helyes)
        cout<<"\nA zarojelezes helyes.\n";
    else
        cout<<"\nA zarojelezes nem helyes\n";

    TesztVerem();
    TesztKivetel();
    return 0;
}

//Teszteli a verem osztályt, előre eltervezett műveletekkel
void TesztVerem()
{
    cout<<"\n========= Verem osztaly tesztelese. =========\n";
    //Konstruktorok
    Verem V;
    cout<<"V letrejott.\n";
    if(!V.ures_e())
    {
        cerr<<"Ures-e() rossz!\n";
    }else
    {
        cout<<"V.urese() helyes.\n";
    }
    Verem W(3);
    cout<<"W(3) letrejott.\n";
     if(!W.ures_e())
    {
        cerr<<"Ures-e() rossz!\n";
    }else{
         cout<<"W.urese() helyes.\n";
    }
    cout<<endl;
    //műveletek tesztelése
    bool hiba=false;
    for(int i=1; i<=10; ++i)
    {
        V.verembe(i);
        if(V.teto()!=i)
        {
            cerr<<"teto() vagy verembe() hibas\n";
            hiba=true;
        }
    }
    if(!hiba)
        cout<<"V verembe 1..10 berakasa sikeres\n";
    else
        cout<<"V verembe 1..10 berakasa sikertelen\n";

    hiba=false;
    int i=10;
    while(!V.ures_e())
    {
        if(V.verembol()!=i)
        {
            cerr<<"verembol() hibas\n";
            hiba=true;
        }
        --i;
    }
    if(!hiba)
        cout<<"V verembol 10..1 kivetele sikeres\n";
    else
        cout<<"V verembol 10..1 kivetele sikertelen\n";
    cout<<endl;
    //És hasonlóan folytatva...
}

//Teszteli a verem kivételeit
void TesztKivetel()
{
    //Kivételek kipróbálása
    cerr<<"Teszteljuk a kivetel dobast:\n";
    try{
        Verem W(-1);
    }catch(Verem::Hiba err)
    {
        if(err==Verem::HibasMeret)
            cerr<<"Verem meret nem lehet 1-nel kisebb!\n";
    }

    try{
        Verem W(3);
        int e=W.verembol();
    }catch(Verem::Hiba err)
    {
        if(err==Verem::UresVerem)
            cerr<<"Ures verembol probal kivenni!\n";
    }

    try{
        Verem W(3);
        int e=W.teto();
    }catch(Verem::Hiba err)
    {
        if(err==Verem::UresVerem)
            cerr<<"Ures verem tetejet probalja vizsgalni!\n";
    }

    //Teszteljük, hogy növeli-e a méretet
    cout<<"vector meret novelesenek tesztelese\n";
    try{
        Verem W(1);
        for(int i=1; i<=12; ++i)
        {
            W.verembe(i); //Próbálgatjuk a vector növelését
        }
        cout<<"1..12 elem berakva\n";
        while(!W.ures_e())
        {
            cout<<W.verembol()<<" ";
        }
        cout<<" elemek kivetele sikerult\n";
    }catch(Verem::Hiba err)
    {
        cerr<<"Ha ezt latja, forduljon a szoftver keszitojehez!\n";
    }

}

