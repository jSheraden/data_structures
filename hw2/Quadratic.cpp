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
double Quadratic::getA() const
{
    return a;
}

// Quadratic.getB() - Return the value of b.
double Quadratic::getB() const
{
    return b;
}

// Quadratic.getC() - Return the value of c.
double Quadratic::getC() const
{
    return c;
}

// Overloaded addition operator.
Quadratic operator+( const Quadratic &q1, const Quadratic &q2 )
{
    Quadratic quadratic;
    
    double newA = q1.getA() + q2.getA();
    double newB = q1.getB() + q2.getB();
    double newC = q1.getC() + q2.getC();
    
    quadratic.set( newA, newB, newC );
    
    return quadratic;
}
