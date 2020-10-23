#ifndef __COMPARABLE_H
#define __COMPARABLE_H

class Comparable
{
public:
    virtual int compareTo(Comparable *other);
    virtual void print();
};

#endif
