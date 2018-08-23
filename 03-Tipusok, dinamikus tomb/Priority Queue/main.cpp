//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Feladat:       Prioritásos sor megvalósítása dinamikus, rendezetlen tömbbel.
//               Menürendszer készítés a típus műveleteinek kényelmes kipróbálásához.
//               Automatikusan futtatható tesztesetek készítése a catch.hpp segítségével.

#include <iostream>
#include <vector>
#include "priorsor.h"
#include "menu.h"

using namespace std;

// Ezzel lehet a manuális es a unit teszt mód között váltogatni
//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Prioritasos sor" << endl;

    /*Előre megállapodunk a méretről
    int meret;
    do{
        cout << "Milyen meretu prioritasos sort kivan hasznalni:";
        cin >> meret;
        if(meret<=0)
            cerr << "Pozitiv erteket adjon meg!\n";
    }while(meret<=0);

    Menu Teszt(meret);*/
    Menu Teszt;
    Teszt.Run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "priorsor.h"

//A gyakorlati anyagban kitűzött tesztesetek megvalósítása

TEST_CASE("konstruktorok", "[PrSor]")
{
    PrSor Q;
    CHECK( 0 == Q.getHossz() );
    CHECK( 100 == Q.getMeret() );

    PrSor Q1(3);
    CHECK( 0 == Q1.getHossz() );
    CHECK( 3 ==Q1.getMeret() );

    CHECK_THROWS(PrSor Q2(0));

    CHECK_THROWS(PrSor Q3(-1));
}

TEST_CASE("ures_e","[PsSor]")
{
    PrSor Q1;
    CHECK( Q1.ures_e() == TRUE );

    PrSor Q2(3);
    CHECK( Q2.ures_e() == TRUE );

    Elem e(1,"a");
    Q2.prSorba(e);
    CHECK( Q2.ures_e() == FALSE );

    e=Q2.maxKivesz();
    CHECK( Q2.ures_e() == TRUE );
}

TEST_CASE("prSorba","[PrSor]")
{
    PrSor Q(2);
    Elem e1(1,"a"); Elem e2(2,"b"); Elem e3(3,"c"); Elem e4(4,"d"); Elem e5(5,"e");

    {
        Q.prSorba(e1);
        CHECK( 1 == Q.getHossz());
        CHECK( 2 == Q.getMeret() );
        vector<Elem> v= Q.getElemek();
        CHECK( v[0] == e1 );
    }

    {
        Q.prSorba(e2);
        CHECK( 2 == Q.getHossz());
        CHECK( 2 == Q.getMeret() );
        vector<Elem> v= Q.getElemek();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]);
    }

    {
        Q.prSorba(e3);
        CHECK( 3 == Q.getHossz());
        CHECK( 4 == Q.getMeret() );
        vector<Elem> v= Q.getElemek();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]);
    }

    {
        Q.prSorba(e4);
        CHECK( 4 == Q.getHossz());
        CHECK( 4 == Q.getMeret() );
        vector<Elem> v= Q.getElemek();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]); CHECK( e4 == v[3]);
    }

    {
        Q.prSorba(e5);
        CHECK( 5 == Q.getHossz());
        CHECK( 8 == Q.getMeret() );
        vector<Elem> v= Q.getElemek();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]); CHECK( e4 == v[3]); CHECK( e5 == v[4]);
    }

    PrSor Q1;
    Q1.prSorba(e1); Q1.prSorba(e2);
    CHECK( 2 == Q1.getHossz());
    CHECK( 100 == Q1.getMeret() );
    vector<Elem> v1= Q1.getElemek();
    CHECK( e1 == v1[0]); CHECK( e2 == v1[1]);

}

TEST_CASE("maxindex max maxKivesz","[max] [PrSor]")
{
    //maxindex és maxKivesz tesztelése
    SECTION("ures sor")
    {
        PrSor Q;
        CHECK_THROWS(Q.max());
        CHECK_THROWS(Q.maxKivesz());

    }

    //Elemek a teszteléshez
    Elem e;
    Elem e1(1,"a"); Elem e2(2,"b"); Elem e3(3,"c"); Elem e5(5,"a");
    SECTION("egy elemu")
    {
        PrSor Q;
        Q.prSorba(e1);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e1 );
        e=Q.maxKivesz();
        CHECK( 0 == Q.getHossz());
        CHECK( e == e1 );
    }

    SECTION("tobb elemu, elso a legnagyobb")
    {
        PrSor Q;
        Q.prSorba(e5); Q.prSorba(e2); Q.prSorba(e3);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e5 );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e5 );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e3); CHECK(v[1]==e2);
    }

    SECTION("tobb elemu, utolso a legnagyobb")
    {
        PrSor Q;
        Q.prSorba(e1); Q.prSorba(e2); Q.prSorba(e3);
        CHECK(2 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3 );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e3 );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

    SECTION("tobb elemu, belso a legnagyobb")
    {
        PrSor Q;
        Q.prSorba(e1); Q.prSorba(e3); Q.prSorba(e2);
        CHECK(1 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3 );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e3 );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

    Elem e5c(5,"c");
    SECTION("tobb elemu, nem egyertelmu elso es utolso")
    {
        PrSor Q;
        Q.prSorba(e5); Q.prSorba(e2); Q.prSorba(e5c);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e5 );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e5 );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e5c); CHECK(v[1]==e2);
    }

    Elem e3b(3,"b");
    SECTION("tobb elemu, nem egyertelmu masodik es harmadik")
    {
        PrSor Q;
        Q.prSorba(e1); Q.prSorba(e3b); Q.prSorba(e3);
        CHECK(1 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3b );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e3b );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e1); CHECK(v[1]==e3);
    }

    Elem e3a(3,"a");
    SECTION("tobb elemu, nem egyertelmu mind azonos")
    {
        PrSor Q;
        Q.prSorba(e3a); Q.prSorba(e3b); Q.prSorba(e3);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3a );
        e=Q.maxKivesz();
        CHECK( 2 == Q.getHossz());
        CHECK( e == e3a );
        vector<Elem> v=Q.getElemek();
        CHECK(v[0]==e3); CHECK(v[1]==e3b);
    }
}



#endif
