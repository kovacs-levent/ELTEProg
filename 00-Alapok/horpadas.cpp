//Információk
//Feladat: Keressük a legmagasabban fekvő horpadást, azaz egy tömb olyan legnagyobb értékét, amely a közvetlen szomszédjainál kisebb.
//Készítette: Racskó Balázs 2018.02.10
//Programozás 0. laborgyakorlat

#include <iostream>
#include <vector>
#include <cstdlib> //random miatt

using namespace std;

vector<int> feltolt(int db);
bool maxsearch(const vector<int> &v, int& maxelem, int& i);

int main()
{
    cout<<"Adja meg a generalando elemszamot"<<endl;
    int db;
    cin>>db;
    srand(_getpid());

    vector<int> vec=feltolt(db);

    int res=0, maxind=0;
    bool found = maxsearch(vec,res,maxind);

    if(found)
    {
        cout<<"A legmagasabb horpadas:" <<res<<endl;
    }
    else
    {
        cout<<"Nem volt megfelelo elem" <<res<<endl;
    }
    return 0;
}

bool maxsearch(const vector<int> &v, int& maxelem, int& ind) //visszaadja a maximum elemet és indexet, bár az index a feladat szempontjából mindegy.
{
    bool l=false;
    unsigned int i=1; //intervallum: m..n vagyis 1..(size-1) (1 azért, mert i-1-et vizsgálunk, size-1 meg mert i+1-et is.
    while(i<v.size()-1)  // lehetne for cikulussal is
    {
        if(!l && (v[i]<v[i+1] && v[i]<v[i-1]) ) //szomszédjainál kisebb-e
        {
            l=true;
            maxelem=v[i];
            ind=i;
        } else if (l && (v[i]<v[i+1] && v[i]<v[i-1]) )
        {
            if(v[i]>maxelem)
            {
                maxelem=v[i];
                ind=i;
            }
        }
        i++;
    }
    return l; //visszaadja, hogy volt-e megfelelo elem
}

vector<int> feltolt(int db) //feltölti a vectort random számmal, darabszámig
{
    vector<int> vec;
    for(int i=0;i<db;i++)
    {
        vec.push_back(rand() % 1000);
        cout<<vec[i]<<endl;
    }
    return vec;
}


