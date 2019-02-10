#pragma once

#include <string>

class Creature
{
protected:
    std::string _name;
    int _power;
    Creature (const std::string &str):_name(str)
    {

    }
public:
    std::string name() const
    {
        return _name;
    }
    bool alive() const
    {
        return _power > 0;
    }
    ///virut�lis oldj�k meg, hogy melyik f�ggv�ny fusson le, ha az �soszt�lyra hivatkozunk pointerrel
    ///�s ez alapj�n futtatunk f�ggv�nyeket. Ha nem virtu�lis a f�ggv�ny, akkor az �szoszt�ly� fog megh�v�dni!
    virtual void transmute(int &ground) = 0;

    virtual ~Creature ()
    {

    }
};

class Greenfinch : public Creature
{
public:
    ///konstruktor nem lehet virtu�lis
    Greenfinch(const std::string &str):Creature(str)
    {
         _power = 10;
    }
    void transmute(int &ground) override;
};

class Sandbug : public Creature
{
public:
    Sandbug(const std::string &str):Creature(str)
    {
        _power = 15;
    }
    void transmute(int &ground) override;
};

class Squelchy : public Creature
{
public:
    Squelchy(const std::string &str):Creature(str)
    {
         _power = 20;
    }
    void transmute(int &ground) override;
};
