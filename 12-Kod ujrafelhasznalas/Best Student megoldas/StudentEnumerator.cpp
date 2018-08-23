#include "StudentEnumerator.h"

void StudentEnumerator::next()
{
    isEnd = f->end();
    if(!isEnd)
    {
        actstudent.name = f->current().name;
        int firstMark = f->current().mark;
        Average pr(actstudent.name, firstMark);
        pr.addEnumerator(f);
        pr.run();
        if(pr.result().count > 0)
        {
            actstudent.avr = (double)pr.result().sum/(double)pr.result().count;
            actstudent.isFailing = pr.result().isFailing;
        }
        else
        {
            actstudent.avr = 0;
        }
    }
}
