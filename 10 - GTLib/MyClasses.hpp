#include "library\summation.hpp"
#include "library\linsearch.hpp"
#include "library\intervalenumerator.hpp"
#include <cmath>

class MySum : public Summation<int>
{
	protected:
	int func(const int& a) const
	{
		return a;
	}
	int neutral() const
	{
		return 0;
	}
	int add(const int &a, const int &b) const 
	{
		return a+b;
	}
};

class MySelect : public Summation<int, std::ostream>
{
	protected:
	std::string func(const int &a) const
	{
		return std::to_string(a) + " ";
	}
	
	bool cond(const int &a) const 
	{
		return (a % 2 == 0);
	}
	public:
	MySelect(std::ostream* ostr) : Summation(ostr)
	{
		
	}
};

class AllEven : public LinSearch<int, true>
{
	protected:
	bool cond(const int& a) const
	{
		return (a % 2 == 0);
	}
};

class DivisorSearch : public LinSearch<int, true>
{
	public:
	DivisorSearch(const int &n) : _n(n)
	{
		
	}
	protected:
	bool cond(const int &a) const
	{
		return (_n % a != 0);
	}
	private:
	int _n;
};

class PrimeSearch : public LinSearch<int, false>
{
	protected:
	bool cond(const int &a) const
	{
		if(a < 2)
		{
			return false;
		}
		DivisorSearch ds(a);
		IntervalEnumerator enor(2, sqrt(a));
		ds.addEnumerator(&enor);
		ds.run();
		return ds.found();
	}
};

class AddDivisors : public Summation<int>
{
	public:
	AddDivisors(const int &n) : _n(n)
	{
		
	}
	protected:
	int func(const int& a) const
	{
		return a;
	}
	int neutral() const
	{
		return 0;
	}
	int add(const int &a, const int &b) const 
	{
		return a+b;
	}
	bool cond(const int &a) const
	{
		return (_n % a) == 0;
	}
	private:
	int _n;
};