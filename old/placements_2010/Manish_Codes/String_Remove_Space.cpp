#include<iostream>
using namespace std;

void RevSpace(char *s)
{
	char *ns, *p;
	ns=s;
	p=s;
	while(*p)
	{
		if(*p!=' ')
		{
			*ns=*p;
			ns++;
		}
		p++;

	}
	*ns='\0';
	cout << ns << endl;

}


int main(void)
{
	char *str = new char;
	cin >> str;
	RevSpace(&str);
}
