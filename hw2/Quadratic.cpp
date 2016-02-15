#include "Quadratic.hpp"

// The default constructor initializes all values to 0.
Quadratic::Quadratic()
{
    a = 0;
    b = 0;
    c = 0;
}

// Quadratic.set() - Assign new values to a, b, and c.
void Quadratic::set( double newA, double newB, double newC )
{
    a = newA;
    b = newB;
    c = newC;
}

// Quadratic.getA() - Return the value of a.
double Quadratic::getA()
{
    return a;
}

// Quadratic.getB() - Return the value of b.
double Quadratic::getB()
{
    return b;
}

// Quadratic.getC() - Return the value of c.
double Quadratic::getC()
{
    return c;
}

