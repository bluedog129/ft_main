#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
public:
    virtual ~Base() {}
    virtual char getType() const = 0;
    Base *generate(void);
    void identify(Base *p);
    void identify(Base &p);
};

class A : public Base 
{
public:
    virtual char getType() const { return 'A'; }
};

class B : public Base 
{
public:
    virtual char getType() const { return 'B'; }
};

class C : public Base 
{
public:
    virtual char getType() const { return 'C'; }
};

#endif