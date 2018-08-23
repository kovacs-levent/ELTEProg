#include <iostream>
#include <vector>
#include <fstream>
//Ez a program az ELTE IK-n oktatott Programozás tárgyhoz készült segédanyag
//Önálló felkészülésre nem feltétlenül alkalmas!
//Az órán elhangzottakat írja le egyszerû példákkal, a teljesség igénye nélkül
//Tartalom: A program célja, hogy egyszerû példákon keresztül ismertesse meg standard könyvtárban lévõ
//vector containert, függvényeket és a paraméterátadás módjait
//Egyszerû példa egymásba ágyazott intervallumos progtételekkel

//A függvények valamilyen paraméterlistával rendelkeznek és ez alapján valamilyen értékkel térnek vissza
//int visszatérési értékû függvény, paraméter nélküli
int f();
//Lehet void visszatérési értékû is, ez esetben nincs visszatérési érték
void g();

//A paraméterlista azt mondja meg, hogy a függvényhíváskor milyen adatokat vagyunk kötelesek
//átadni a függvénynek, hogy azt meg tudjuk hívni
//int visszatérési értékû, int paramétert kapó függvény (identitás függvény)
int identity(int i)
{
    return i;
}

//Ugyanolyan nevû függvénynek többféle paraméterlistája és visszatérési értéke lehet, ekkor a hívásból
//tudja eldönteni a fordító, hogy melyik függvényt akarjuk meghívni. Ezt hívjuk function overloadnak. Példák:
double identity(double d)
{
    return d;
}

float identity(float f)
{
    return f;
}
//Azonban helytelen ha ugyanolyan paraméterlistával többféle definíciónk létezik
//Pl.: Az alábbi, kikommentezett függvény fordítási hibához vezet
/*double identity(int i)
{
    return i;
}*/

//A fenti függvényekben a paraméterek érték szerint adódnak át, de ez nem feltétlenül gazdaságos
//Mi van, ha egy vectort szeretnénk paraméternek? Pl.:
void f(std::vector<int> v); //Ez a függvény érték szerinti paraméterátadást használ

//Ha a paraméterül kapott adat nagy méretû (pl. egy vector), akkor nem feltétlenül gazdaságos a fenti paraméterátadás
//A fenti esetben a vector másolódik a stackre, ezzel értékes memóriát és idõt pazarolva
//Megtehetjük, hogy az eredeti objektummal dolgozunk a függvénybe, referenciaként adjuk át Pl.:
void g(std::vector<int> &v);

//Ezzel elérjük, hogy a vector nem másolódik feleslegesen, az eredeti objektummal dolgozunk ami a paraméter volt
//Ez azonban veszélyes, ez esetben a függvény megváltoztathatja a vector tartalmát
//Ha ezt nem akarjuk engedni akkor a const kulcsszót használhatjuk
void h(const std::vector<int> &v);

//template függvény, tetszõleges paraméterû, T-vel tér vissza, 1 darab T template paramétere van
template <class T>
T t(T t1);

//Hogyan olvassunk be egy tetszõleges vectorba? Az alábbi eljárás console-ról olvas be a vectorba:
template<class T>
void g(std::vector<T> &v)
{
    std::cout << "Hany elem kerul a vectorba? ";
    int n;
    std::cin >> n;
    for(int i = 0; i<n; i++)
    {
        T t;
        std::cin >> t; //Mi van, ha a T típusnak nincs >> operátora? Overloadolhatjuk az operátort, errõl késõbb
        v.push_back(t); //A vector végére helyezzük az elemet
        //Alternatíva: indexelõ opertáorral (vigyázni kell, hogy a vector nem feltétlenül üres) és resize-al v[i] = t;
    }
}

//Mi van ha fájlból szeretnénk?
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

//Alternatíva: a fájlban legyen benne az input mérete resize után indexelve helyezzük bele az elemeket
//Ez esetben az egyszerûség kedvéért feltételezzük, hogy üres vectorba olvasunk be
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

//Mi legyen, ha tetszõleges input streamrõl szeretnénk olvasni? Írhatunk >> operátort a vectorunknak
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
    return istr; //returnoljuk az istr-t, hogy tudjuk láncolni a beolvasás operátort
}

bool Horpadas_e(const std::vector<int> &v, const int &ind)
{
    return v[ind] > v[ind-1] && v[ind] > v[ind+1];
}

//Feladat: Keressük meg a legmagasabban fekvõ horpadást, azaz egy tömb olyan legnagyobb indexû elemét, amely kisebb
//mint az azt megelõzõ és az azt követõ érték.
//A megoldás a feltételes maximum kereséssel történik
bool Horpadas(const std::vector<int> &v, int &result)
{
    bool l = false;
    int maxind; //alapvetõen mindkét paraméter kell, de a max most elhanyagolható (max = maxind miatt)
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
