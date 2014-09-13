#include<iostream>
#include<malloc.h>
using namespace std;

void generateparen(char *str , int n, int lp, int rp,int index)
{
	if(index >= 2*n)
		cout << str << endl;
	if(lp < n)
	{
		str[index] = '{';
		generateparen(str,n,lp+1,rp,index+1);
	}
	if(rp < lp)
	{
		str[index] = '}';
		generateparen(str,n,lp,rp+1,index+1);
	}
	return;
}

int main(void)
{
	int n;
	cin >> n;
	char* str = (char*) malloc(sizeof (char*) * 2*n+1);
	generateparen(str,n,0,0,0);
}

