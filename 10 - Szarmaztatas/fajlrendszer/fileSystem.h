#ifndef FILESYSTEM_H_INCLUDED
#define FILESYSTEM_H_INCLUDED
#include "entry.h"
#include <vector>

class FileSystem
{
public:
    void addEntry(Entry* p)
    {
        content.push_back(p);
    }

    bool removeEntry(Entry* p);

    unsigned int getSize();
private:
    std::vector<Entry*> content;
};

#endif // FILESYSTEM_H_INCLUDED
