/* ASSUMPTIONS: case insensitive and only alphabets as valid string. */
#include <iostream>
#include <algorithm>

using namespace std;

/* LOGIC:
 * for anagrams the pair of sum and product is
 * unique;
 * 
 * e.g abc & bac
 * sum = 6; prod = 6
 *
 * e.g nap & pan
 * sum = ; prod =
 */

int val(char a)
{
        /* if the input string is only lower-case alphabets */
        /* return (a - 'a' + 1); */
        return (int)a;
}
bool is_permutation_sum_prod(const string& a, const string& b)
{
        int sum1 = 0, prod1 = 1;
        for (string::const_iterator it = a.begin(); it != a.end(); ++it) {
                sum1 += val(*it);
                prod1 *= val(*it);
        }
        
        int sum2= 0, prod2 = 1;
        for (string::const_iterator it = b.begin(); it != b.end(); ++it) {
                sum2 += val(*it);
                prod2 *= val(*it);
        }

        return ((sum1 == sum2) && (prod1 == prod2));
}

bool is_permutation_sort(string a, string b)
{
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return (a == b);
}

string cleanup(string str)
{
        /* implement this if we want to force restrictions over
         * the input string
         */
        return str;
}


int main()
{
        string str1, str2;
        cin >> str1 >> str2;

        string a = cleanup(str1);
        string b = cleanup(str2);

        cout << "Is Permutation (" << a << ", " << b << "): " << (is_permutation_sum_prod(a, b) ? "True" : "False") << endl;
        cout << "Is Permutation (" << a << ", " << b << "): " << (is_permutation_sort(a, b) ? "True" : "False") << endl;

        return 0;
}
