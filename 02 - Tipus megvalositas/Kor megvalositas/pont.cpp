#include<iostream>
#include<math.h>
#include"pont.h"

void pont::kiir () const
{
    std:: cout<<"X koordinata:"<<x<<" Y koordinata:"<<y<<std::endl;
}

pont pont::Add(const pont& b)
{
    pont c(x+b.x, y+b.y);
    return c;
}

pont pont::Sub(const pont& b)
{
    pont c(x-b.x, y-b.y);
    return c;
}

pont operator+(pont lhs, const pont& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

pont operator-(pont lhs, const pont& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}
