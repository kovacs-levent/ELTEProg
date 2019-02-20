#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED
#include <iostream>
class pont
{
    private:
        double x,y;
    public:
        pont () : x(0),y(0){}
        pont(const double a,const double b):x(a),y(b) {}
        void kiir () const;
        double getX () const {return x;}
        double getY () const {return y;}
        void setX (const double a) {x=a;}
        void setY (const double b) {x=b;}
        void setXY (const double a,const double b) {x=a; y=b; }
        ///Itt vitathat�, hogy az Add �s a Sub-nak az eredeti objektumot kellene-e v�ltoztatnia, vagy egy m�solatot visszaadni
        ///Jelen esetben �j objektumot adunk vissza, de az is egy megold�s, hogy a megh�vott objektumot v�ltoztatn�nk ink�bb
        ///Ez szoftvertervez�si k�rd�s, teh�t att�l f�gg, hogy hogyan lesz haszn�lva a program...
        pont Add(const pont &b);
        pont Sub(const pont &b);
        friend pont operator+(pont lhs, const pont &rhs);
        friend pont operator-(pont lhs, const pont &rhs);
};

#endif // PONT_H_INCLUDED
