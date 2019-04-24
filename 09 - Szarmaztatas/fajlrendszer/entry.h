#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED
#include <string>

class Entry
{
public:
    virtual unsigned int getSize() = 0;
    Entry()
    {
        name = "";
    }
    Entry(const std::string &str) : name(str)
    {

    }
    std::string getName()
    {
        return name;
    }
    void setName(const std::string &newName)
    {
        name = newName;
    }
protected:
    std::string name;
};

#endif // ENTRY_H_INCLUDED
