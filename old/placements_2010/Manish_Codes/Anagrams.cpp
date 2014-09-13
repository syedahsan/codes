#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>

using namespace std;

int main(void)
{
	string str;
	getline(cin,str);
	int alphabet[26];
	for(int i=0;i<str.length();i++)
	{
		for(int j=0;j<26;j++) alphabet[j] =0;
		while(str[i] != ' ' && str[i] != '\0')
		{
		     alphabet[str[i]-'a']++;
	             i++;
		}
		for(int j=0;j<26;j++)
		{
			if(alphabet[j] !=0)
			{
				char c1 = (char)j + 'a';
	                        char c2 = char(alphabet[j]) + '0';
				char str1[2];
				sprintf(str1,"%c%c",c1,c2);
				cout << str1 << endl;
			}
		}

	}
}
