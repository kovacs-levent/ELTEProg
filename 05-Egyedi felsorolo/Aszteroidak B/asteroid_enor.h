#ifndef ASTEROID_ENOR_H_INCLUDED
#define ASTEROID_ENOR_H_INCLUDED
#include "asteroid.h"
#include <fstream>

class asteroid_enor
{
public:
    asteroid_enor(const std::string& input);
    void Read();
    void First();
    void Next();
    bool End()
    {
        return isEnd;
    }
    asteroid_sighting Current()
    {
        return akt;
    }
private:
    bool isEnd;
    enum error {FILE_ERROR};
    enum status {norm, abnorm};
    status st;
    asteroid_sighting akt;
    asteroid_sighting next;
    std::ifstream ifstr;
};

#endif // ASTEROID_ENOR_H_INCLUDED
