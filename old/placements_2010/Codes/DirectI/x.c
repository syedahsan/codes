#include <math.h>
int main() {
	int i=1;

	int num = pow(5,10) + pow(7,28);
	while(++i) {

		if(num%i==0)
		{ printf("%d\n",i);
			break;
		}
	}
	return 0;
}

