#ifndef __COMPLEXLZ__
#define __COMPLEXLZ__

#include <iostream.h>

class complex
{
public:
    complex(double r = 0, double i = 0)
        : re(r), im(i)
    { }
    complex& operator += (const complex&);
    double real() const {return re;}
    double imag() const {return im;}

private:
    double re, im;
    friend complex& __doapl (complex*, const complex&);
};


complex& __doapl (complex* ths, const complex& r)
{   
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

complex& complex::operator += (const complex& r)
{
    return __doapl (this, r);
}

inline complex operator + (const complex& x, const complex& y) {
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline complex operator + (const complex& x, double y) {
    return complex(x.real() + y, x.imag());
}

inline complex operator + (double x, const complex& y) {
    return complex(x + y.real(), y.imag());
}

inline complex& operator << (ostream& os, const complex& x) {
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif