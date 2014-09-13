/*Bloomberg LP  » Algorithm
theOne on January 27, 2007 | Question #2848 (Report Dup) | Edit | 12 
Write a small program that takes two strings as input and prints two
numbers (n1 and n2) as output, where:

n1 is the number of letters in the first string that each has a match in
the second string in the same position in the string.
n2 is the number of letters in the first string that each has a match in
the second string but does not have a match in the same position.

Note that each match is unique. That is, no letter in either string can
participate in more than one match.
I.e., each letter instance can contribute at most once to n1+n2.

Some examples:
abc abcd -> 3 0
aab aacd -> 2 0
aba aab -> 1 2
aba bab -> 0 2
*/

#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	string str1,str2;
	cin >> str1 >> str2;
	int n1=0,n2=0;
	vector<int>alphabet(26,0);
	for(int i=0;i<str1.length();i++)
	{
		if(str1[i] == str2[i]) n1++;
		else alphabet[str1[i] -'a']++;
	}
	for(int i=0;i<str2.length();i++)
	{
		if(alphabet[str2[i] -'a'] !=0) 
		{
			alphabet[str2[i] -'a']--;
			n2++;
		}
	}	
	cout << n1 << " " << n2 << endl;
}
