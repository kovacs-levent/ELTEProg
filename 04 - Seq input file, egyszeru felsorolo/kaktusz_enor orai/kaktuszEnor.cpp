#include "kaktuszEnor.h"

kaktuszEnor::kaktuszEnor(const std::string &filename) : input(filename.c_str())
{
	if(input.fail())
	{
		sx = abnorm;
	}
}

void kaktuszEnor::First()
{
	Read();
	if(input.fail())
	{
		sx = abnorm;
	}
	else
	{
		sx = norm;
	}
}

void kaktuszEnor::Next()
{
	Read();
	if(input.fail())
	{
		sx = abnorm;
	}
}

void kaktuszEnor::Read()
{
	input >> dx.nev;
	input >> dx.haza;
	input >> dx.szin;
	input >> dx.meret;
}