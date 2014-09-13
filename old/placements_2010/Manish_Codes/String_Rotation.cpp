#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	string s1,s2;
	cin >> s1 >>s2;
	char *str1,*str2;
	str1 = new char[s1.length() +1];
	str2 = new char[s2.length() +1];
	strcpy(str1,s1.c_str());
	strcpy(str2,s2.c_str());
	char *output =new char[s1.length() + s2.length() +1] ;
	if(s1.length() == s2.length())
		output = strstr(strcat(str1,str1),str2);
	cout << output << endl;

}
