/*
 * 1/1 1/2 1/3 1/4 1/5 ...
 * 2/1 2/2 2/3 2/4
 * 3/1 3/2 3/3
 * 4/1 4/2
 * 5/1
 *
 * 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 ...
 *
 * solve the equation x(x+1)/2 <= n;
 *
 * nth fraction in the series:
 * sum(x) <= n
 *
 * if sum(x) = n: its the ending element of diagonal row x
 * if x is odd; element is 1/x
 * if x is even; element is x/1
 *
 * if sum(x) < n: its the i = n - sum(x) element in the next diagonal row of x+1
 * x = x+1
 * if x is even, start from top or 1/x. and move like 2/x-1, 3/x-2 ..| ie i/x-i+1
 * if x is odd, start from bot or x/1. and move like x-1/2, x-2/3 ...| ie x-i+1/i
 *
 * eg n = 14, x = 4 (10 elements have been swapped already)
 * sum(4) = 10 < 14
 * i = 14 - 10 = 4 elements in the row 5th is our element.
 * x = 4 + 1 = 5
 * start with 5/1, 4/2, 3/3, 2/4. ie 2/4 is our answer.
 * or (5 - 4 + 1)/4 or 2/4
 *
 */

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

#define	max(a, b)	((a > b) ? a : b)
#define	sum(n)		((n*(n+1)/2))
#define	odd(x)		((x%2) ? true : false)
#define	even(x)		((x%2) ? false : true)
#define	fmt		"TERM %d IS %d/%d\n"


/* sum(x) <= n */
int
solve_for_x(int a, int b, int c)
{
	double x = max((-b + sqrt(b*b -4*a*c))/(2*a), (-b - sqrt(b*b -4*a*c))/(2*a));
	return ((int) floor(x));
}

int
main()
{
	int t, n, x;
	int i, sum_x;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		x = solve_for_x(1, 1, -2 * n);
		sum_x = sum(x);

		if (sum_x == n) {
			if (odd(x))
				printf(fmt, n, 1, x);
			else
				printf(fmt, n, x, 1);
		} else if (sum_x < n) {
			i = n - sum_x;
			x = x + 1;

			if (odd(x))
				printf(fmt, n, x-i+1, i);
			else
				printf(fmt, n, i, x-i+1);
		} else {
			/* something went horribly wrong */
		}
	}

	return 0;
}
