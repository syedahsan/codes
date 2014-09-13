#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
#include <cmath>

using namespace std;

class Complex {

        public:
                /* Constructor */
                Complex(double r = 0, double i = 0) : _r(r), _i(i) {};

                /* #Copy Constuctor */
                Complex(const Complex &rv)
                {
                        std::cout << "@debug: Copy Constructor" << std::endl;
                        _r = rv._r;
                        _i = rv._i;
                }

                /* #Copy Assignment Operator */
                Complex& operator=(const Complex &rhs);

                /* #Destructor */
                ~Complex() {};

                /* Operator Overloading */

                        /* +, -, +=, -= */
                Complex& operator+=(const Complex &rhs);
                Complex& operator-=(const Complex &rhs);
                const Complex operator+(const Complex &rhs) const;
                const Complex operator-(const Complex &rhs) const;

                        /* <, >, >=, <=, ==, != */
#if 0           /* These operations are not defined for complex numbers */
                bool operator<(const Complex &rhs) const;
                bool operator>(const Complex &rhs) const;
                bool operator<=(const Complex &rhs) const;
                bool operator>=(const Complex &rhs) const;
#endif
                bool operator==(const Complex &rhs) const;
                bool operator!=(const Complex &rhs) const;

                        /* a++, ++a */
                        /* cout << a */
                        /* new & delete - NOT DOING RIGHT NOW */
                        /* Read Placement New */

                /* Some functions */
                double abs() const;
                void print() const; /* remove when '<<' is implemented */

        private:
                double _r;       /* real */
                double _i;       /* imaginary */
};

#endif

/* # - Exist by default */
