#include<iostream>
#include<math.h>
#include"kor.h"

using namespace std;

kor::kor():  kp(0,0), r(0) {}

kor::kor(const double a, const double b, const double c)  : kp(a,b), r(c)
{
    if (c<0)
    {
        std::cerr <<"Hiba: Negativ a sugar\n";
        exit(1);
    }
}

kor::kor(const pont &p, const double c) : kp(p), r(c)
{
    if (c<0)
    {
        std::cerr <<"Hiba: Negativ a sugar\n";
        exit(1);
    }
}

void kor::Kiir() const
{
    cout<<"Kor kozeppontja: ";
    kp.kiir();
    cout<<"Sugara: "<<r<<endl;
}

double kor::Terulet() const
{
    return r*r*pi;
}

double kor::tavolsag(const pont &p) const
{
    return sqrt(pow(p.getX()-getkp().getX(),2.0)+pow(p.getY()-getkp().getY(),2.0));
}

kor kor::Scale(const double &s)
{
    kor k(kp, r*s);
    return k;
}

kor operator*(kor lhs, const double &rhs)
{
    lhs.r*=rhs;
    return lhs;
}

kor operator*(const double &lhs, kor rhs)
{
    return rhs*lhs;
}
