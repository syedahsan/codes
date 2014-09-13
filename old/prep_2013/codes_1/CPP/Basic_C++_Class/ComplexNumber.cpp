#include "ComplexNumber.h"

using namespace std;

Complex& Complex::operator=(const Complex &rhs)
{
        std::cout << "@debug: Copy Assignment Operator" << std::endl;
        _r = rhs._r;
        _i = rhs._i;
        return (*this);
}

Complex& Complex::operator+=(const Complex &rhs)
{
        _r += rhs._r;
        _i += rhs._i;
        return (*this);
}

Complex& Complex::operator-=(const Complex &rhs)
{
        _r -= rhs._r;
        _i -= rhs._i;
        return (*this);
}

const Complex Complex::operator+(const Complex &rhs) const
{
        return (Complex(*this) += rhs);
}

const Complex Complex::operator-(const Complex &rhs) const
{
        return (Complex(*this) -= rhs);
}

bool Complex::operator==(const Complex &rhs) const
{
        return ((_r == rhs._r) && (_i == rhs._i));
}

bool Complex::operator!=(const Complex &rhs) const
{
        return (!((_r == rhs._r) && (_i == rhs._i)));
}

double Complex::abs() const
{
        return (sqrt(_r*_r + _i*_i));
}

void Complex::print() const
{
        std::cout << _r << " + " << _i << "i" << std::endl;
}
