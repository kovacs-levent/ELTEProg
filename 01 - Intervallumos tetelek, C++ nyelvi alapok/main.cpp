#include <iostream>

using namespace std;

///Feladat: Legmagasabban fekvõ horpadás keresése. Egy felszínen adott távolságonként mérték a tengerszint feletti magasságot.
/// Horpadásnak veszünk egy értéket, ha a körülötte (balra és jobbra) lévõ magasságok nagyobbak ennél az értéknél.
/// A feltételes maximum keresés programozási tétellel oldjuk meg a feladatot.

void feltolt(std::vector<int> &v, const std::string filename)
{
    std::ifstream file(filename.c_str());
    if(file.fail())
    {
        std::cerr << "Hiba a fajl megnyitasa kozben" << std::endl;
        exit(1);
    }
    int tmp;
    file >> tmp;
    while(!file.fail()) ///Rövidebb írásmód: A file.fail() ekvivalens a !file-al (a ! egy operátora az inputstreameknek)
    {
        v.push_back(tmp);
        file >> tmp;
    }
}

bool max_horpadas(int &ind, int &max, const std::vector<int> &v)
{
    bool l = false;
    for(unsigned int i = 1; i < v.size()-1; i++)
    {
        if(v[i] >= v[i-1] || v[i] >= v[i+1])
        {

        }
        else if(l && v[i] < v[i-1] && v[i] < v[i+1])
        {
            if(v[i] > max)
            {
                max = v[i];
                ind = i;
            }
        }
        else if(!l && v[i] < v[i-1] && v[i] < v[i+1])
        {
            l = true;
            max = v[i];
            ind = i;
        }
    }
    return l;
}

int main()
{
    std::vector<int> vec;
    feltolt(vec, "input.txt");
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    int ind, max;
    if(max_horpadas(ind, max, vec))
    {
        std::cout << "A legmagasabb horpadas: " << max;
    }
    else
    {
        std::cout << "Nem volt horpadas";
    }
    return 0;
}
