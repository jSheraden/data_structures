#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

class Quadratic
{
    private:
        double a;
        double b;
        double c;
    public:
        Quadratic();
        Quadratic( double a, double b, double c );
        void set( double newA, double newB, double newC );
        double getA() const;
        double getB() const;
        double getC() const;
        void display() const;
        double evaluate( double x ) const;
        int getNumRoots() const;
        double getSmallRoot() const;
        double getLargeRoot() const;
};

#endif
