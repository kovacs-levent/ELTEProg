//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Prioritásos sor header állománya

#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"

//A prioritásos sor elemei egy egészből (prioritás) és egy szövegből állnak
//Az elem típusát megvalósító struct

//segéd füüggvény az ellenőrzött beolvasáshoz.
//Többszörös deklaráció elkerülése miatt inline
inline bool valid(int a){return true;}

struct Item
{
    //publikus adattagok
    int pr;
    std::string data;

    //Paraméter nélküli (üres)-, és paraméteres konstruktor
    Item() {};
    Item(int p,std::string s):pr(p), data(s) {}

    //Az elem kényelmes beolvasása/kiírása céljából készíthetünk >> és << operátort
    friend std::istream& operator>>(std::istream& s, Item& e)
    {
        e.pr=read<int>("Elem prioritasa:","Egesz szamot kerek!",valid);
        std::cout<<"Elembe kerulo adat:";
        s>>e.data;
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s<<"prioritas: "<<e.pr<<" adat: "<<e.data<<" ";
        return s;
    }

    //Teszteléshez készült, egyenlőséget vizsgáló == operátor
    bool operator==(const Item& b)
    {
        return (pr==b.pr && data==b.data);
    }
};

//A prioritásos sor felülete
class PrQueue
{
    public:
        enum PrQueueError{EMPTY_PRQUEUE};

        //PrQueue(); //Nincs teendő
        //~PrSor() {} //Nincs teendő

        void add(Item a);
        Item remMax() throw (PrQueueError); //legnagyobb prioritássú elem kivétele a sorból
        Item max() const throw (PrQueueError); //(egyik) legnagyobb prioritású elem visszaadása
        bool isEmpty() {return _vec.size()==0;} //pr.sor ürességét vizsgálja

        //Csak a teszteléshez használatos metódusok
        friend std::ostream& operator<<(std::ostream& s, const PrQueue& q); //sor kiirása
        unsigned int getLength() const {return _vec.size();}
        unsigned int getCapacity() const {return _vec.capacity();}
        std::vector<Item> getItems() const;
        int getMaxindex() const {return maxindex();} //maxindex privát, nem hívható meg kívülről

    private:
        std::vector<Item> _vec; //tároló tömb vectorral implementálva
        int maxindex() const; //maximális elem indexének kiválasztása

};


#endif // PRIORSOR_H_INCLUDED
