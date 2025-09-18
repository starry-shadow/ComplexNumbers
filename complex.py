class complex:
    def __init__(self, real, imaginary):
        self.real=real
        self.imaginary=imaginary
    def __add__(self, other):
        if isinstance(other, (int, float)):
            newReal=self.real+other;
            return complex(newReal,self.imaginary)
        elif isinstance(other, complex):
            newReal=self.real+other.real;
            newImaginary=self.imaginary+other.imaginary
            return complex(newReal,newImaginary)
        else:
            raise TypeError
    def __sub__(self, other):
        if isinstance(other, (int, float)):
            newReal=self.real-other;
            return complex(newReal,self.imaginary)
        elif isinstance(other, complex):
            newReal=self.real-other.real
            newImaginary=self.imaginary-other.imaginary
            return complex(newReal,newImaginary)
        else:
            raise TypeError
    def __mul__(self, other):
        if isinstance(other, (int, float)):
            newReal=self.real*other;
            newImaginary=self.imaginary*other
            return complex(newReal,newImaginary)
        elif isinstance(other, complex):
            newReal=(self.real*other.real)+(self.imaginary*other.imaginary*-1)
            newImaginary=(self.real*other.imaginary)+(other.real*self.imaginary)
            return complex(newReal,newImaginary)
        else:
            raise TypeError
    def __truediv__(self, other):
        if isinstance(other, (int, float)):
            newReal=self.real/other
            newImaginary=self.imaginary/other
            return complex(newReal,newImaginary)
        elif isinstance(other, complex):
            dividendReal= (self.real*other.real)+(self.imaginary*((other.imaginary*-1)*-1));
            dividendImaginary=(self.real*(other.imaginary*-1))+(self.imaginary*(other.real));
            divisorReal=(other.real*other.real)+(other.imaginary*(other.imaginary*-1)*-1);
            newReal= round(dividendReal/divisorReal,10);
            newImaginary=round(dividendImaginary/divisorReal,10);
            return complex(newReal,newImaginary)
        else:
            raise TypeError
    def __radd__(self, other):
        return self+other
    def __rsub__(self, other):
        return complex(other,0)-self
    def __rmul__(self, other):
        return self * other
    def __rtruediv__(self, other):
        return complex(other,0) / self
    def __str__(self):
        real_part=round(self.real,10)
        imaginary_part=round(self.imaginary,10)
        if(imaginary_part<0):
            return f'({real_part}{imaginary_part}i)'
        else:
            return f'({real_part}+{imaginary_part}i)'

if __name__ == '__main__':
    a=complex(1.0,2.0)
    b=complex(1.0,3.0)
    i = 5
    print('%s + %s = %s' % (a, b, a + b))
    print('%s - %s = %s' % (a, b, a - b))
    print('%s * %s = %s' % (a, b, a * b))
    print('%s / %s = %s' % (a, b, a / b))

    print('%s + %i = %s' % (a, i, a + i))
    print('%s - %i = %s' % (a, i, a - i))
    print('%s * %i = %s' % (a, i, a * i))
    print('%s / %i = %s' % (a, i, a / i))

    print('%i + %s = %s' % (i, a, i + a))
    print('%i - %s = %s' % (i, a, i - a))
    print('%i * %s = %s' % (i, a, i * a))
    print('%i / %s = %s' % (i, a, i / a))