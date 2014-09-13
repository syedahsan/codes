#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
string one,two;

int palindrome(string str, int p, int q, int length, int n)
{
	one.assign("");
	two.assign("");
	one.append(1,str[p]);
	two.append(1,str[q]);
	while(p >=0 && q < n && str[p--] == str[q++])
	{
		one.append(1,str[p]);
		two.append(1,str[q]);
		length+=2;
	}
	reverse(one.begin(),one.end());
	return length;
}

int main(void)
{
	string str;
	cin >> str;
	int maximum_length = INT_MIN;
	int n = str.length();
	int length = 0;
	string palin;
	string result;
	for(int i=0;i<n-1;i++)
	{
		palin.assign("");
		if(str[i] == str[i+1])
		{
			length = palindrome(str,i,i+1,0,n);
			palin.append(one.begin()+1,one.end());
			palin.append(two.begin(),two.end()-1);
		}
		else if(i >0 && str[i-1] == str[i+1])
		{
			length = palindrome(str,i-1,i+1,1,n);
			palin.append(one.begin()+1,one.end());
			palin.append(1,str[i]);
			palin.append(two.begin(),two.end()-1);
		}
		if(length > maximum_length)
		{
			maximum_length = length;
			result.assign(palin);
		}
	}
	if(maximum_length == 0)
		cout << "No Palndrome exists in this string" << endl;
	else
		cout <<"Maximum lenigth of palindromic string is  " << maximum_length << " " << "of string" <<" " << result <<  endl;
}


