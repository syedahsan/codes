#include <stdio.h>

void TOH(char Source, char Intermediate, char Destination, int N) {
	if( N > 0 ) {
		TOH(Source,Destination,Intermediate,N-1);
		printf("Move Plate %d from %c to %c\n", N, Source, Destination);
		TOH(Intermediate,Source,Destination,N-1);
	}
	return;
}

int main() {

	int N;
	scanf("%d",&N);
	TOH('A', 'B', 'C', N);
	return 0;
}
