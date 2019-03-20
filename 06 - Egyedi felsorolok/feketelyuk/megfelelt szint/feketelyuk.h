#ifndef FEKETELYUK_H_INCLUDED
#define FEKETELYUK_H_INCLUDED
#include <string>

struct feketelyuk
{
    std::string ID;
    //Ebbe d�ntj�k el, hogy volt-e nagyon messze
    bool wasClose;
    int lastWeight;
};

struct megfigyeles
{
    std::string date;
    unsigned int weight;
    unsigned int distance;
};

#endif // FEKETELYUK_H_INCLUDED
