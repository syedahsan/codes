#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int t[8] = {-1};

void print() {

	int i,j;
	printf("\n------------------------------\n");
	for(i=0;i<8;i++)
		printf(" _");
	for(i=0; i<8; i++) {
		printf("\n|");
		for(j=0; j<8; j++) {
			if(t[i]==j)
				printf("x|");
			else
				printf("_|");
		}
	}
	printf("\n");

	return;
}
void queens(int i) {

	int j;
	for(t[i]=0; t[i]<8; t[i]++) {

		for(j=0; t[i]!=t[j] && abs(t[i]-t[j])!=abs(i-j) && j<8; j++);
		if(i==j) {
			if(i==7) {
				print();
			}
			else
				queens(i+1);
		}
	}
}
int main() {

	queens(0);
	return 0;
}
