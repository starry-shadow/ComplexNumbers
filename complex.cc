/*Start of complex.h*/
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using std::ostream;

struct complex{
    complex(double=0.0, double=0.0);
    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator/(const complex &) const;

    complex operator+(double) const;
    complex operator-(double) const;
    complex operator*(double) const;
    complex operator/(double) const;

    friend complex operator+(double, const complex &);
    friend complex operator-(double, const complex &);
    friend complex operator*(double, const complex &);
    friend complex operator/(double, const complex &);

    friend ostream &operator<<(ostream &, const complex &);

private:
    double real;
    double imaginary;
};

#endif
/*end of complex.h*/


/*Start of complex.cc*/
#include "complex.h"
using std::cout;
using std::endl;

complex::complex(double real, double imaginary) : real(real), imaginary(imaginary){}

complex complex::operator+(const complex &o) const{
    double newReal=real+o.real;
    double newImaginary=imaginary+o.imaginary;
    return complex(newReal,newImaginary);
}
complex complex::operator-(const complex &o) const{
    double newReal=real-o.real;
    double newImaginary=imaginary-o.imaginary;
    return complex(newReal,newImaginary);
}
complex complex::operator*(const complex &o) const{
    double newReal=(real*o.real)+(imaginary*o.imaginary*-1);
    double newImaginary=(real*o.imaginary)+(o.real*imaginary);
    return complex(newReal,newImaginary);
}
complex complex::operator/(const complex &o) const{
    double dividendReal= (real*o.real)+(imaginary*((o.imaginary*-1)*-1));
    double dividendImaginary=(real*(o.imaginary*-1))+(imaginary*(o.real));
    double divisorReal=(o.real*o.real)+(o.imaginary*(o.imaginary*-1)*-1);
    double newReal= dividendReal/divisorReal;
    double newImaginary=dividendImaginary/divisorReal;
    return complex(newReal,newImaginary);
}

//double second
complex complex::operator+(double n) const{
    double newReal= real+n;
    return complex(newReal,imaginary);
}
complex complex::operator-(double n) const{
    double newReal= real-n;
    return complex(newReal,imaginary);
}
complex complex::operator*(double n) const{
    double newReal= real*n;
    double newImaginary=imaginary*n;
    return complex(newReal,newImaginary);
}
complex complex::operator/(double n) const{
    double newReal= real/n;
    double newImaginary=imaginary/n;
    return complex(newReal,newImaginary);
}

//double first
complex operator+(double n, const complex &o){
    return o+n;
}
complex operator-(double n, const complex &o){
    return complex(n)-o;
}
complex operator*(double n, const complex &o){
    return o*n;
}
complex operator/(double n, const complex &o){
    return complex(n)/o;
}

ostream &operator<<(ostream &out, const complex &o){
    if(o.imaginary<0){
        out << '(' << o.real << o.imaginary << 'i' <<')';
    }
    else{
        out << '(' << o.real<< "+" << o.imaginary << 'i' <<')';
    }
    return out;
}

int main(void){
    complex a(1.0,2.0);
    complex b(1.0, 3.0);
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl; 
    cout << a << " / " << b << " = " << a / b << endl;
    //cout << "-------------------------------------------" << endl;
    cout << a << " + " << 5 << " = " << a + 5 << endl;
    cout << a << " - " << 5 << " = " << a - 5 << endl;
    cout << a << " * " << 5 << " = " << a * 5 << endl;
    cout << a << " / " << 5 << " = " << a / 5 << endl;
    //cout << "-------------------------------------------" << endl;
    cout << 5 << " + " << a << " = " << 5 + a << endl;
    cout << 5 << " - " << a << " = " << 5 - a << endl;
    cout << 5 << " * " << a << " = " << 5 * a << endl;
    cout << 5 << " / " << a << " = " << 5 / a << endl;
    return 0;
}
/*end of complex.cc*/