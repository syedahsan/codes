#include<iostream>
using namespace std;

void IsPalindrome(string str)
{
	int start=0;
	int end = str.length()-1;
	while(start < end && str[start] == str[end])
	{
		start++;
		end--;
	}
	if(start >= end) cout << "IS PAlindrome" << endl;
	else cout << "No Palindrome"  << endl;
}

int main(void)
{
	string str;
	getline(cin,str);
	IsPalindrome(str);
}
