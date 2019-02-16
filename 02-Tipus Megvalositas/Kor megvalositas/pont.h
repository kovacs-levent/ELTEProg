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
};

#endif // PONT_H_INCLUDED
