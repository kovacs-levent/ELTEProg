#ifndef STUDENTENUMERATOR_H_INCLUDED
#define STUDENTENUMERATOR_H_INCLUDED
#include "seqinfileenumerator.hpp"
#include "Line.h"
#include "Student.h"
#include "Average.h"

class StudentEnumerator:public Enumerator<Student>
{
public:
    ~StudentEnumerator()
    {
        delete f;
    }

    StudentEnumerator(const std::string &fname)
    {
        f = new SeqInFileEnumerator<Line>(fname);
    }

    void first()
    {
        f->first();
        next();
    }

    void next();

    Student current() const
    {
        return actstudent;
    }

    bool end() const
    {
        return isEnd;
    }
private:
    Student actstudent;
    SeqInFileEnumerator<Line>* f;
    bool isEnd;
};

#endif // STUDENTENUMERATOR_H_INCLUDED
