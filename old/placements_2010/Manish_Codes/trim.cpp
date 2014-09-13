#include<iostream>
using namespace std;

void trim(string str)
{
	int i=0,j=0;
	while(str[i] !='\0')
	{
		if(str[i] != ' ')
		{
			str[j++] = str[i++];
		}
		else 
			i++;
	}
	str[j] = '\0';
	for(int i=0;i<j;i++)
		cout << str[i];
	cout << endl;
}

int main()
{
	string str;
	getline(cin,str);
	trim(str);
}
