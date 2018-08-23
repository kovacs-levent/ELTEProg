//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Prioritásos sor forrás kódja

#include "priorsor.h"

using namespace std;

PrSor::PrSor()
{
    _h=0; _n=size;
    _vec= new Elem[_n];
}

PrSor::PrSor(int m) throw (PrSorHiba)
{
    if(m<=0) throw HIBAS_MERET;
    _h=0; _n=m;
    _vec=new Elem[_n];
}

void PrSor::prSorba(Elem a) throw(PrSorHiba)
{
    if(_n==_h){ //ha betelt a tömb...
        //Elem *w=new Elem[2*_n]; //lefoglalunk egy dupla méretű tömböt
        Elem* w=new (nothrow) Elem[2*_n]; //ha nem sikerül a foglalás, w-be NULL kerül
        if(w==NULL) throw NINCS_ELEG_MEMORIA; //elfogyott a szabad memória
        for(int i=0; i<_n; ++i) w[i]=_vec[i]; //átmásoljuk az elemeket
        delete [] _vec; //töröljük az eredeti tömböt
        _vec=w; //új tömb címe _vec-be kerül
        _n*=2; //méret megduplázódik
    }
    _vec[_h++]=a; //új elemet berakjuk
}

Elem PrSor::maxKivesz() throw (PrSorHiba)
{
    if(_h==0) throw URES_PRSOR;
    int ind=maxindex();
    Elem uj=_vec[ind];
    _vec[ind]=_vec[_h-1]; //Az utolsó elemet áttesszük a kivett elem helyére
    _h--;
    return uj;
}

Elem PrSor::max() const throw (PrSorHiba)
{
    if(_h==0) throw URES_PRSOR;
    int ind=maxindex();
    //Elem uj=_vec[ind];
    //return uj;
    return Elem(_vec[ind]);
}

ostream& operator<<(std::ostream& s, const PrSor& q)
{
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s<<"PrSor jellemzoi:\n";
    s<<"A sor merete:"<<q._n<<" Elemszam:"<<q._h<<"\nTartalma: "<<endl;
    for(int i=0; i<q._h; ++i){
        s<<" ("<<q._vec[i].pr<<","<<q._vec[i].adat<<")";
    }
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

PrSor::PrSor(const PrSor& q)
{
    _vec=new Elem[q._n];
    _n=q._n;
    _h=q._h;
    for(int i=0;i<_h;++i)
        _vec[i]=q._vec[i];
}

PrSor& PrSor::operator=(const PrSor& q)
{
    if (this==&q) {return *this;}
    delete [] _vec; //eredeti tömb felszabadítása
    _vec=new Elem[q._n];
    _n=q._n;
    _h=q._h;
    for (int i=0;i<q._h;i++) {_vec[i]=q._vec[i];}
    return *this;
}

int PrSor::maxindex() const
{
    int ind=0;
    for(int i=1; i<_h; ++i)
    {
        if(_vec[i].pr>_vec[ind].pr)
        {
            ind=i;
        }
    }
    return ind;
}

vector<Elem> PrSor::getElemek() const
{
    vector<Elem> v;
    for(int i=0; i<_h; ++i)
        v.push_back(_vec[i]);
    return v;
}
