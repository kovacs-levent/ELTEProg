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
        ///Itt vitatható, hogy az Add és a Sub-nak az eredeti objektumot kellene-e változtatnia, vagy egy másolatot visszaadni
        ///Jelen esetben új objektumot adunk vissza, de az is egy megoldás, hogy a meghívott objektumot változtatnánk inkább
        ///Ez szoftvertervezési kérdés, tehát attól függ, hogy hogyan lesz használva a program...
        pont Add(const pont &b);
        pont Sub(const pont &b);
        friend pont operator+(pont lhs, const pont &rhs);
        friend pont operator-(pont lhs, const pont &rhs);
};

#endif // PONT_H_INCLUDED
