#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

int main(void)
{
	int a =25;
	float b = 3.14;
	char *str;
	str = (char*)malloc(40);
	sprintf(str,"%d%f",a,b);
	cout << str << endl;
}
