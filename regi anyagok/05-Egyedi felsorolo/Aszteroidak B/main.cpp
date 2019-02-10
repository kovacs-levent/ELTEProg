#include <iostream>
#include "asteroid_enor.h"

using namespace std;

bool felt_max_ker(const std::string &input, int &max, asteroid_sighting& elem)
{
    asteroid_enor ae(input);
    bool l = false;
    ae.First();
    while(!ae.End())
    {
        if(ae.Current().is_closing == false)
        {

        }
        else if(l && ae.Current().is_closing == true)
        {
            if(max < ae.Current().closed_distance)
            {
                max = ae.Current().closed_distance;
                elem = ae.Current();
            }
        }
        else if(!l && ae.Current().is_closing == true)
        {
            l = true;
            max = ae.Current().closed_distance;
            elem = ae.Current();
        }
        ae.Next();
    }
    return l;
}

int main()
{
    int max;
    asteroid_sighting elem;
    if(felt_max_ker("input.txt", max, elem))
    {
        std::cout << elem.id << " " << elem.closed_distance;
    }
    else
    {
        std::cout << "Nem volt kozeledo aszteroida.";
    }

    return 0;
}
