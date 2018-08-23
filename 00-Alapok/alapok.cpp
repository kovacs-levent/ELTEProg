#include <iostream>
#include <vector>
#include <fstream>
//Ez a program az ELTE IK-n oktatott Programoz�s t�rgyhoz k�sz�lt seg�danyag
//�n�ll� felk�sz�l�sre nem felt�tlen�l alkalmas!
//Az �r�n elhangzottakat �rja le egyszer� p�ld�kkal, a teljess�g ig�nye n�lk�l
//Tartalom: A program c�lja, hogy egyszer� p�ld�kon kereszt�l ismertesse meg standard k�nyvt�rban l�v�
//vector containert, f�ggv�nyeket �s a param�ter�tad�s m�djait
//Egyszer� p�lda egym�sba �gyazott intervallumos progt�telekkel

//A f�ggv�nyek valamilyen param�terlist�val rendelkeznek �s ez alapj�n valamilyen �rt�kkel t�rnek vissza
//int visszat�r�si �rt�k� f�ggv�ny, param�ter n�lk�li
int f();
//Lehet void visszat�r�si �rt�k� is, ez esetben nincs visszat�r�si �rt�k
void g();

//A param�terlista azt mondja meg, hogy a f�ggv�nyh�v�skor milyen adatokat vagyunk k�telesek
//�tadni a f�ggv�nynek, hogy azt meg tudjuk h�vni
//int visszat�r�si �rt�k�, int param�tert kap� f�ggv�ny (identit�s f�ggv�ny)
int identity(int i)
{
    return i;
}

//Ugyanolyan nev� f�ggv�nynek t�bbf�le param�terlist�ja �s visszat�r�si �rt�ke lehet, ekkor a h�v�sb�l
//tudja eld�nteni a ford�t�, hogy melyik f�ggv�nyt akarjuk megh�vni. Ezt h�vjuk function overloadnak. P�ld�k:
double identity(double d)
{
    return d;
}

float identity(float f)
{
    return f;
}
//Azonban helytelen ha ugyanolyan param�terlist�val t�bbf�le defin�ci�nk l�tezik
//Pl.: Az al�bbi, kikommentezett f�ggv�ny ford�t�si hib�hoz vezet
/*double identity(int i)
{
    return i;
}*/

//A fenti f�ggv�nyekben a param�terek �rt�k szerint ad�dnak �t, de ez nem felt�tlen�l gazdas�gos
//Mi van, ha egy vectort szeretn�nk param�ternek? Pl.:
void f(std::vector<int> v); //Ez a f�ggv�ny �rt�k szerinti param�ter�tad�st haszn�l

//Ha a param�ter�l kapott adat nagy m�ret� (pl. egy vector), akkor nem felt�tlen�l gazdas�gos a fenti param�ter�tad�s
//A fenti esetben a vector m�sol�dik a stackre, ezzel �rt�kes mem�ri�t �s id�t pazarolva
//Megtehetj�k, hogy az eredeti objektummal dolgozunk a f�ggv�nybe, referenciak�nt adjuk �t Pl.:
void g(std::vector<int> &v);

//Ezzel el�rj�k, hogy a vector nem m�sol�dik feleslegesen, az eredeti objektummal dolgozunk ami a param�ter volt
//Ez azonban vesz�lyes, ez esetben a f�ggv�ny megv�ltoztathatja a vector tartalm�t
//Ha ezt nem akarjuk engedni akkor a const kulcssz�t haszn�lhatjuk
void h(const std::vector<int> &v);

//template f�ggv�ny, tetsz�leges param�ter�, T-vel t�r vissza, 1 darab T template param�tere van
template <class T>
T t(T t1);

//Hogyan olvassunk be egy tetsz�leges vectorba? Az al�bbi elj�r�s console-r�l olvas be a vectorba:
template<class T>
void g(std::vector<T> &v)
{
    std::cout << "Hany elem kerul a vectorba? ";
    int n;
    std::cin >> n;
    for(int i = 0; i<n; i++)
    {
        T t;
        std::cin >> t; //Mi van, ha a T t�pusnak nincs >> oper�tora? Overloadolhatjuk az oper�tort, err�l k�s�bb
        v.push_back(t); //A vector v�g�re helyezz�k az elemet
        //Alternat�va: indexel� opert�orral (vigy�zni kell, hogy a vector nem felt�tlen�l �res) �s resize-al v[i] = t;
    }
}

//Mi van ha f�jlb�l szeretn�nk?
template<class T>
void fileInput(std::vector<T> &v, std::ifstream &ifstr)
{
    T t;
    ifstr >> t;
    while(!ifstr.fail())
    {
        v.push_back(t);
        ifstr >> t;
    }
}

//Alternat�va: a f�jlban legyen benne az input m�rete resize ut�n indexelve helyezz�k bele az elemeket
//Ez esetben az egyszer�s�g kedv��rt felt�telezz�k, hogy �res vectorba olvasunk be
template<class T>
void fileInWithCount(std::vector<T> &v, std::ifstream &ifstr)
{
    int n;
    ifstr >> n;
    v.resize(n);
    for(int i = 0; i<n; i++)
    {
        T t;
        ifstr >> t;
        v[i] = t;
    }
}

//Mi legyen, ha tetsz�leges input streamr�l szeretn�nk olvasni? �rhatunk >> oper�tort a vectorunknak
template<class T>
std::istream& operator>>(std::istream &istr, std::vector<T> &v)
{
    int n;
    istr >> n;
    v.resize(n);
    for(int i = 0; i<n; i++)
    {
        T t;
        istr >> t;
        v[i] = t;
    }
    return istr; //returnoljuk az istr-t, hogy tudjuk l�ncolni a beolvas�s oper�tort
}

bool Horpadas_e(const std::vector<int> &v, const int &ind)
{
    return v[ind] > v[ind-1] && v[ind] > v[ind+1];
}

//Feladat: Keress�k meg a legmagasabban fekv� horpad�st, azaz egy t�mb olyan legnagyobb index� elem�t, amely kisebb
//mint az azt megel�z� �s az azt k�vet� �rt�k.
//A megold�s a felt�teles maximum keres�ssel t�rt�nik
bool Horpadas(const std::vector<int> &v, int &result)
{
    bool l = false;
    int maxind; //alapvet�en mindk�t param�ter kell, de a max most elhanyagolhat� (max = maxind miatt)
    for(int i = 2; i < v.size()-1; i++)
    {
        bool tmp = Horpadas_e(v,i);
        if(!tmp)
        {
        }
        else if(l && tmp)
        {
            maxind = i;
        }
        else if (!l && tmp)
        {
            l = true;
            maxind = i;
        }
    }
    if(l)
    {
        result = maxind+1;
    }
    return l;
}

int main()
{
    std::vector<int> v;
    for(int i = 1; i<= 10;i++)
    {
        v.push_back(i);
    }
    v.push_back(2);
    for(int i = 11; i > 0; i--)
    {
        v.push_back(i);
    }
    int result;
    bool l = Horpadas(v, result);
    if(l)
    {
        std::cout << "A legmagasabban elhelyezkedo horpadas: " << result;
    }
    else
    {
        std::cout << "Nincs horpadas a vektorban!";
    }
    return 0;
}
