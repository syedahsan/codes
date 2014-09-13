#include<stdio.h>

int main() {

	int P=10000;
	int a = 5;
	int b=12;
	int c=15;

	int i,cnt=0;

	for(i=1; i<=P;i++) {
		if((i%5)==0) {
			if((i%12)!=0 && (i%15)!=0)
				cnt++;
			continue;
		}
		if((i%12)==0) {
			if((i%5)!=0 && (i%15)!=0)
				cnt++;
			continue;
		}

		if((i%15)==0) {
			if((i%5)!=0 && (i%12)!=0)
				cnt++;
			continue;
		}
	}

	printf("%d\n",cnt);
	return 0;
}

