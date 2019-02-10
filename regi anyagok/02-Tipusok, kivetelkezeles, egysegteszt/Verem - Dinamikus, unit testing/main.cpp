//Készítette:    Veszprémi Anna
//Dátum:         2018.02.16.
//Feladat:       Verem típus megvalósítása
//               Egy zárójelekbõl álló szövegen a helyes zárójelezés vizsgálata,
//               az összetartozó helyes zárójelpárok indexének kiírása

#include <iostream>
#include <string>
#include "verem.h"

using namespace std;

// Ezzel lehet a manuális es a unit teszt mód között váltogatni
#define NORMAL_MODE
#ifdef NORMAL_MODE

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
        cout<<"\nA zarojelezes nem helyes.\n";

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "verem.h"

TEST_CASE("konstruktor, ures verem", "[verem]")
{
    SECTION("konstruktor")
    {
        Verem V;
        vector<int> v_masolat=V.mutasd();
        CHECK( 0== v_masolat.size() );
        CHECK( V.ures_e() == TRUE );
    }

    SECTION("teto() ures veremre hibat dob")
    {
        Verem V;
        CHECK_THROWS(V.teto());
    }

    SECTION("verembol() ures veremre hibat dob")
    {
        Verem V;
        CHECK_THROWS(V.verembol());
    }
}

TEST_CASE("verembe muvelet tesztelese", "[verembe]")
{
    Verem V;
    V.verembe(1); V.verembe(2); V.verembe(3);
    vector<int> v_masolat=V.mutasd();
    for(int i=0; i<3; ++i)
        CHECK (v_masolat[i]==i+1);
    CHECK(v_masolat.size()==3);
    CHECK (V.ures_e() == FALSE);
}

TEST_CASE("verembol() es teto() muvelet tesztelese", "[verembol]")
{
    Verem V;
    V.verembe(1); V.verembe(2); V.verembe(3);
    int i=3;
    while(!V.ures_e())
    {
        CHECK(V.teto() == i);
        CHECK(V.verembol()==i);
        --i;
        vector<int> v_masolat=V.mutasd();
        CHECK(v_masolat.size()== i);
        for(int j=0; j<i; ++j)
            CHECK(v_masolat[j]==j+1);
    }
}



#endif
