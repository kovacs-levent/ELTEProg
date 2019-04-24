#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include "entry.h"

class File : public Entry
{
public:
    File(const std::string &name, const std::string &content) : Entry(name), data(content)
    {

    }

    virtual unsigned int getSize()
    {
        return data.size();
    }

    std::string ReadData()
    {
        return data;
    }

    void WriteData(const std::string &newData)
    {
        data = newData;
    }
private:
    std::string data;
};


#endif // FILE_H_INCLUDED
