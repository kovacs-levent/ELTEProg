#include "fileSystem.h"

bool FileSystem::removeEntry(Entry* p)
{
    bool l = false;
    int i = 0, ind;
    while(!l && i < content.size())
    {
        l = (content[i] == p);
        ind = i;
        ++i;
    }
    if(l)
    {
        content[ind] = content[content.size()-1];
        content.pop_back();
    }
    return l;
}

unsigned int FileSystem::getSize()
{
    unsigned int sum = 0;
    for(int i = 0; i < content.size(); i++)
    {
        sum += content[i]->getSize();
    }
    return sum;
}
