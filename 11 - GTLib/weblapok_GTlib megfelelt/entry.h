#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED

struct entry
{
    std::string time;
    int pages;
    friend std::istream& operator>>(std::istream& istr, entry& e)
    {
        istr >> e.time;
        istr >> e.pages;
        return istr;
    }
};

#endif // ENTRY_H_INCLUDED
