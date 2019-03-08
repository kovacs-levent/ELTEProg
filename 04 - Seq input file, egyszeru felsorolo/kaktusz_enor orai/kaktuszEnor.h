#ifndef KAKTUSZENOR_H_INCLUDED
#define KAKTUSZENOR_H_INCLUDED
#include "kaktusz.h"
#include <fstream>

class kaktuszEnor
{
public:
	enum Status{norm, abnorm};
    kaktuszEnor(const std::string &inputfile);

    void First();

    bool End() const
    {
        return sx == abnorm;
    }

    void Next();

    kaktusz Current() const
    {
        return dx;
    }
	
	void Read();
private:
    std::ifstream input;
	kaktusz dx;
	Status sx;
};

#endif // KAKTUSZENOR_H_INCLUDED
