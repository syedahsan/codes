#include<iostream>
#include<cstring>
#include<cstdio>
#include<climits>
#include<malloc.h>
using namespace std;

int atoi(char str[], int radix)
{
	if(str == NULL) return 0;
	int len = strlen(str);
	if(len <=0) return 0;
	int index = 0;
	while(str[index] == ' ') index++;
	bool isNeg = false;
	if(str[index] == '-')
	{
		isNeg = true;
		index++;
		while(str[index] == ' ')index++;
	}
	int oldValue = 0;
	while(index < len)
	{
		char value = str[index++];
		if(value >= '0' && value <= '9')
		{
			oldValue*=radix; 
			int intvalue = value -'0';
			oldValue+=intvalue;
			if(oldValue < intvalue)
			{
				if(isNeg)
					oldValue = INT_MIN;
				else
					oldValue = INT_MAX;
			}
		}
		else break;
	}
	if(isNeg)
		oldValue*=-1;
	return oldValue;
}

int main(void)
{
	char *str;
	int radix;
	str = (char*) malloc(30);
	scanf("%[^\n]",str);
	cin >> radix;
	cout << atoi(str,radix) << endl;
}
