#include<iostream>
#include<malloc.h>
#include<cstring>
using namespace std;

int main(void)
{
	char src[25] = "My name is Manish Ag...";
        char *dest;
	dest = (char*) malloc(sizeof (src));
	memcpy(dest,src,sizeof(src));
	cout << dest << endl;	
	//memset(src,'-',7);
	memmove(src+20,src+15,11);
	cout << src << endl;
}

