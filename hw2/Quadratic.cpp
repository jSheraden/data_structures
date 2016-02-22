#include "Quadratic.hpp"

// The default constructor initializes all values to 0.
Quadratic::Quadratic()
{
    a = 0;
    b = 0;
    c = 0;
}

// An overloaded constructor that sets the values of its
// parameters to a, b, and c.
Quadratic::Quadratic( double a, double b, double c )
{
    a = a;
    b = b;
    c = c;
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

// Quadratic.display() - Prints the current state of the quadratic object.
void Quadratic::display() const
{
    std::cout << a << "x^2 + " << b << "x + " << c;
}

// Quadratic.evaluate() - Prints the value of the quadratic object
// for a given value x.
double Quadratic::evaluate( double x ) const
{
    return pow( a * x, 2 ) + ( b * x ) + c;
}

// Quadratic.getNumRoots() - Returns the quadratic's number of roots.
int Quadratic::getNumRoots() const
{
    // If a, b, and c are all 0, the quadratic has 2 real roots.
    if ( a == 0 && b == 0 && c == 0 )
    {
        return 2;
    }
    
    // If a and b are zero and c is non-zero, the quadratic has no real roots.
    else if ( a == 0 && b == 0 && c != 0 )
    {
        return 0;
    }
    
    // If a is zero and b is non-zero, the quadratic has only 1 real root.
    else if ( a == 0 && b != 0 )
    {
        return 1;
    }
    
    // If a is non-zero and b squared is less than 4ac,
    // the quadratic has no real roots.
    else if ( a != 0 && pow( b, 2 ) < 4 * a * c )
    {
        return 0;
    }

    // If a is non-zero and b squared is equal to 4ac,
    // the quadratic has only 1 real root.
    else if ( a != 0 && pow( b, 2 ) == 4 * a * c )
    {
        return 1;
    }

    // If a is non-zero and b squared is greater than 4ac,
    // the quadratic has 2 real roots.
    else if ( a != 0 && pow( b, 2 ) > 4 * a * c )
    {
        return 2;
    }
}

// Quadratic.getSmallRoot() - Returns the small root of the quadratic.
double Quadratic::getSmallRoot() const
{
    
}

// Quadratic.getLargeRoot() - Returns the large root of the quadratic.
double Quadratic::getLargeRoot() const
{
    
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

// Overloaded multiplication operator.
Quadratic operator*( double r, const Quadratic &q )
{
    Quadratic quadratic;
    
    double newA = q.getA() * r;
    double newB = q.getB() * r;
    double newC = q.getC() * r;
    
    quadratic.set( newA, newB, newC );
    
    return quadratic;
}
