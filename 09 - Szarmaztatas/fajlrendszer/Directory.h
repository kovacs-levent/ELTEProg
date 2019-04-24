#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include "entry.h"
#include <vector>

class Directory : public Entry
{
public:
    Directory(const std::vector<Entry*> &startContent) : content(startContent)
    {

    }

    Directory()
    {

    }

    virtual unsigned int getSize();

    void addEntry(Entry* p)
    {
        content.push_back(p);
    }

    bool deleteEntry(Entry* p);
private:
    std::vector<Entry*> content;
};

#endif // DIRECTORY_H_INCLUDED
