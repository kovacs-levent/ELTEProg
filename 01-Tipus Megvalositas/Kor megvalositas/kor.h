#ifndef KOR_H_INCLUDED
#define KOR_H_INCLUDED
#define pi 3.14159265
#include <iostream>
#include <cstdlib>
#include "pont.h"

class kor
{
    private:

        //adattagok
        pont kp;
        double r;

    public:
        //konstruktorok
        kor();
        kor(const double a, const double b, const double c);
        kor(const pont &p, const double c);

        //getter es setter metodusok, izles szerint
        //ezek definicioi is kerulhetnek a cpp-be,
        //de en az inline definiciok mellett dontottem
        pont getkp () const {return kp;}
        double getr () const {return r;}
        void setkp (const pont &a)
        {
            kp.setXY(a.getX(), a.getY());
        }
        void setr (const double b) {r=b;}

        //public metodusok/fuggvenyek
        void Kiir() const;
        double tavolsag(const pont &p) const;
        double Terulet() const;
};
#endif // KOR_H_INCLUDED
