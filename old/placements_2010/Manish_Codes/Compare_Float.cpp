#include<iostream>
using namespace std;

void CompareFloat(float a, float b)
{
	char *b1,*b2;
	b1 = (char*)&a;
	b2 = (char*)&b;
	int flag =0;
	for(int i=0;i<4;i++)
	{
		if(*b1 != *b2) flag =1;
		b1++;b2++;
	}
	if(flag == 1) cout << "Not Equal" << endl;
	else cout << "Equal" << endl;
}

int main(void)
{
	float a,b;
	cin >> a >> b;
	CompareFloat(a,b);
}
