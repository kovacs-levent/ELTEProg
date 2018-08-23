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
    ///virutális oldják meg, hogy melyik függvény fusson le, ha az õsosztályra hivatkozunk pointerrel
    ///és ez alapján futtatunk függvényeket. Ha nem virtuális a függvény, akkor az õszosztályé fog meghívódni!
    virtual void transmute(int &ground) = 0;

    virtual ~Creature ()
    {

    }
};

class Greenfinch : public Creature
{
public:
    ///konstruktor nem lehet virtuális
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
