#include<iostream>
#include<algorithm>
using namespace std;

string str;

void ReverseString(int start, int end)
{
	while(start < end)
	{
		swap(str[start],str[end]);
		start++;
		end--;
	}
}

void ReverseWords(int start, int end)
{
	ReverseString(start,end);
	int startword = 0;
	for(int i=0;i<=str.length();i++)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			ReverseString(startword,i-1);
			startword = i+1;
		}
	}
}

int main(void)
{
	getline(cin,str);
	ReverseWords(0,str.length()-1);
	cout << str << endl;
}
