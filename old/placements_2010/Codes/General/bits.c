#include <stdio.h>
#include <math.h>

int count_set(int N) {

	int count = 0;
	while(N) {
		N = N & N-1;
		count++;
	}
	return count;
}

int set(int Number, int offset, int range) {
	return ( Number | (((int)pow((double)2, (double)range) - 1) << (offset)) );
}

int main(int argc, char **argv) {

	printf("%d\n", count_set(atoi(argv[1])));
	printf("%d\n", set(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));

	return 0;
}


