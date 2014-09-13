#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main(int argc, char **argv)
{
        Complex A;      /* Constructor */
        Complex B(1);   /* Constructor */
        Complex C(2, 3); /* Constructor */

        Complex D = C; /* Copy Constructor */
        Complex E(D); /* Copy Constructor */

        Complex F; /* Constructor */
        F = E; /* Copy Assignment Operator */

        A.print();
        B.print();
        C.print();
        D.print();
        E.print();
        F.print();

        (B + C).print();
        F += E += D;
        F.print();
        E.print();

        cout << ((D == C) ? "true" : "false") << endl;
        cout << ((E == C) ? "true" : "false") << endl;

        return 0;
}
