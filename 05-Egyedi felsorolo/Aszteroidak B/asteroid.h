#ifndef ASTEROID_H_INCLUDED
#define ASTEROID_H_INCLUDED
#include <string>

struct asteroid_sighting
{
    std::string id;
    std::string date;
    int weight;
    int distance;
    bool is_closing;
    int closed_distance;
};

#endif // ASTEROID_H_INCLUDED
