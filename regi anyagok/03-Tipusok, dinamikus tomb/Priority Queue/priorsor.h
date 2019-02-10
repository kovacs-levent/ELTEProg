//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Prioritásos sor header állománya

#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>

//A prioritásos sor elemei egy egészből (prioritás) és egy szövegből állnak
//Az elem típusát megvalósító struct

struct Elem
{
    //publikus adattagok
    int pr;
    std::string adat;

    //Paraméter nélküli (üres)-, és paraméteres konstruktor
    Elem() {};
    Elem(int p,std::string s):pr(p), adat(s) {}

    //Az elem kényelmes beolvasása/kiírása céljából készíthetünk >> és << operátort
    friend std::istream& operator>>(std::istream& s, Elem& e)
    {
        std::cout<<std::endl<<"Elem prioritasa:";
        s>>e.pr;
        std::cout<<"Elembe kerulo adat:";
        s>>e.adat;
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Elem& e)
    {
        s<<"prioritas: "<<e.pr<<" adat: "<<e.adat<<" ";
        return s;
    }

    //Teszteléshez készült, egyenlőséget vizsgáló == operátor
    bool operator==(const Elem& b)
    {
        return (pr==b.pr && adat==b.adat);
    }
};

//A prioritásos sor felülete
class PrSor
{
    public:
        enum PrSorHiba{URES_PRSOR,HIBAS_MERET,NINCS_ELEG_MEMORIA};

        PrSor(); //Paraméter nélküli konstruktor
        PrSor(int m) throw (PrSorHiba); //adott méretû prioritásos sor létrehozásához konstruktor
        ~PrSor() {delete [] _vec;} //Destruktor felszabadítja a dinamikus tömböt

        void prSorba(Elem a) throw (PrSorHiba); //elem berakása a sorba
        Elem maxKivesz() throw (PrSorHiba); //legnagyobb prioritássú elem kivétele a sorból
        Elem max() const throw (PrSorHiba); //(egyik) legnagyobb prioritású elem visszaadása
        bool ures_e() {return _h==0;} //pr.sor ürességét vizsgálja

        PrSor(const PrSor&); //Copy konstruktor
        PrSor& operator=(const PrSor&); //Értékadás operátor

        //Csak a teszteléshez használatos metódusok
        friend std::ostream& operator<<(std::ostream& s, const PrSor& q); //sor kiirása
        int getHossz() const {return _h;}
        int getMeret()const {return _n;}
        std::vector<Elem> getElemek() const;
        int getMaxindex() const {return maxindex();} //maxindex privát, nem hívható meg kívülről

    private:
        Elem *_vec; //tároló tömb
        int _n; //tömb mérete
        int _h; //PrSor elemszáma
        static const int size=100; //üres konstruktor esetén ez lesz az induló méret
        int maxindex() const; //maximális elem indexének kiválasztása

};


#endif // PRIORSOR_H_INCLUDED
