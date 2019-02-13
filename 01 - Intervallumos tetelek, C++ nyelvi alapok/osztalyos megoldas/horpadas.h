#ifndef HORPADAS_H_INCLUDED
#define HORPADAS_H_INCLUDED
#include <vector>
#include <fstream>

class Felszin
{
public:
    void beolvas_darabszam(const std::string &filename)
    {
        filestream.open(filename.c_str());
        if(filestream.fail())
        {
            std::cerr << "Hiba a fajl megnyitasa kozben";
            exit(1);
        }
        vec.clear();
        int db;
        filestream >> db;
        vec.resize(db);
        for(int i = 0; i < db; i++)
        {
            filestream >> vec[i];
        }
        ///Csukjuk be a streamet, ha �gy akarn�nk �j f�jlt nyitni a j�v�ben, hogy ez a stream m�r megnyitott egyet, akkor az fail-elni fog
        ///Ez az�rt sz�ks�ges, mert az oszt�lyunk ugyanazzal az ifstream objektummal dolgozik mindig, nem inicializ�l �jat minden f�ggv�nyh�v�sn�l
        filestream.close();
    }

    void beolvas_darab_nelkul(const std::string &filename)
    {
        filestream.open(filename.c_str());
        if(filestream.fail())
        {
            std::cerr << "Hiba a fajl megnyitasa kozben";
            exit(1);
        }
        vec.clear();
        int tmp;
        filestream >> tmp;
        while(!filestream.fail()) ///R�videbb �r�sm�d: A file.fail() ekvivalens a !file-al (a ! egy oper�tora az inputstreameknek)
        {
            vec.push_back(tmp);
            filestream >> tmp;
        }
        ///Csukjuk be a streamet, ha �gy akarn�nk �j f�jlt nyitni a j�v�ben, hogy ez a stream m�r megnyitott egyet, akkor az fail-elni fog
        ///Ez az�rt sz�ks�ges, mert az oszt�lyunk ugyanazzal az ifstream objektummal dolgozik mindig, nem inicializ�l �jat minden f�ggv�nyh�v�sn�l
        filestream.close();
    }

    bool max_horpadas(int &ind, int &max)
    {
        bool l = false;
        for(unsigned int i = 1; i < vec.size()-1; i++)
        {
            if(vec[i] >= vec[i-1] || vec[i] >= vec[i+1])
            {

            }
            else if(l && vec[i] < vec[i-1] && vec[i] < vec[i+1])
            {
                if(vec[i] > max)
                {
                    max = vec[i];
                    ind = i;
                }
            }
            else if(!l && vec[i] < vec[i-1] && vec[i] < vec[i+1])
            {
                l = true;
                max = vec[i];
                ind = i;
            }
        }
        return l;
    }
private:
    std::vector<int> vec;
    std::ifstream filestream;
};

#endif // HORPADAS_H_INCLUDED
