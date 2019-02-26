//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Feladat:       Prioritásos sor megvalósítása rendezetlen tömbbel.
//               Menürendszer készítés a típus műveleteinek kényelmes kipróbálásához.
//               Automatikusan futtatható tesztesetek készítése a catch.hpp segítségével.
//Felhasznált header fájl: read.hpp (ellenőrzött beolvasás billentyűzetről, szerző: Gregorics Tibor)

#include <iostream>
#include <vector>
#include "priorsor.h"
#include "menu.h"

using namespace std;

// Ezzel lehet a manuális es a unit teszt mód között váltogatni
#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Prioritasos sor" << endl;

    Menu Teszt;
    Teszt.Run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "priorsor.h"

//A gyakorlati anyagban kitűzött tesztesetek megvalósítása

TEST_CASE("isEmpty()","[PrQueue]")
{
    PrQueue Q1;
    CHECK( Q1.isEmpty() == TRUE );

    Item e(1,"a");
    Q1.add(e);
    CHECK( Q1.isEmpty() == FALSE );

    e=Q1.remMax();
    CHECK( Q1.isEmpty() == TRUE );
}

TEST_CASE("add","[PrQueue]")
{
    PrQueue Q;
    Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e4(4,"d"); Item e5(5,"e");

    {
        Q.add(e1);
        CHECK( 1 == Q.getLength());
        vector<Item> v= Q.getItems();
        CHECK( v[0] == e1 );
    }

    {
        Q.add(e2);Q.add(e3);Q.add(e4);Q.add(e5);
        CHECK( 5 == Q.getLength());
        vector<Item> v= Q.getItems();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]); CHECK( e4 == v[3]); CHECK( e5 == v[4]);
    }
}

TEST_CASE("maxindex max remMax","[max] [PrQueue]")
{
    //maxindex és remMax tesztelése
    SECTION("ures sor")
    {
        PrQueue Q;
        CHECK_THROWS(Q.max());
        CHECK_THROWS(Q.remMax());

    }

    //Itemek a teszteléshez
    Item e;
    Item e1(1,"a"); Item e2(2,"b"); Item e3(3,"c"); Item e5(5,"a");
    SECTION("egy elemu")
    {
        PrQueue Q;
        Q.add(e1);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e1 );
        e=Q.remMax();
        CHECK( 0 == Q.getLength());
        CHECK( e == e1 );
    }

    SECTION("tobb elemu, elso a legnagyobb")
    {
        PrQueue Q;
        Q.add(e5); Q.add(e2); Q.add(e3);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e5 );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e5 );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e3); CHECK(v[1]==e2);
    }

    SECTION("tobb elemu, utolso a legnagyobb")
    {
        PrQueue Q;
        Q.add(e1); Q.add(e2); Q.add(e3);
        CHECK(2 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3 );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e3 );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

    SECTION("tobb elemu, belso a legnagyobb")
    {
        PrQueue Q;
        Q.add(e1); Q.add(e3); Q.add(e2);
        CHECK(1 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3 );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e3 );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e2);
    }

    Item e5c(5,"c");
    SECTION("tobb elemu, nem egyertelmu elso es utolso")
    {
        PrQueue Q;
        Q.add(e5); Q.add(e2); Q.add(e5c);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e5 );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e5 );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e5c); CHECK(v[1]==e2);
    }

    Item e3b(3,"b");
    SECTION("tobb elemu, nem egyertelmu masodik es harmadik")
    {
        PrQueue Q;
        Q.add(e1); Q.add(e3b); Q.add(e3);
        CHECK(1 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3b );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e3b );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e1); CHECK(v[1]==e3);
    }

    Item e3a(3,"a");
    SECTION("tobb elemu, nem egyertelmu mind azonos")
    {
        PrQueue Q;
        Q.add(e3a); Q.add(e3b); Q.add(e3);
        CHECK(0 == Q.getMaxindex());
        e=Q.max();
        CHECK( e == e3a );
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e3a );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e3); CHECK(v[1]==e3b);
    }

    SECTION("tobb elemu, kiveves sorrendje, ujra beteves")
    {
        PrQueue Q;
        Q.add(e2); Q.add(e3); Q.add(e1);
        e=Q.remMax();
        CHECK( 2 == Q.getLength());
        CHECK( e == e3 );
        vector<Item> v=Q.getItems();
        CHECK(v[0]==e2); CHECK(v[1]==e1);
        e=Q.remMax();
        CHECK( 1 == Q.getLength());
        CHECK( e == e2 );
        v.clear();
        v=Q.getItems();
        CHECK(v[0]==e1);
        e=Q.remMax();
        CHECK( 0 == Q.getLength());
        CHECK( e == e1 );
        Q.add(e3);Q.add(e2);Q.add(e1);
        v.clear();
        for(int i=1; i<=3; ++i) v.push_back(Q.remMax());
        CHECK(v[0]==e3);CHECK(v[1]==e2);CHECK(v[2]==e1);
        CHECK(Q.isEmpty()==TRUE);
    }


}

#endif
