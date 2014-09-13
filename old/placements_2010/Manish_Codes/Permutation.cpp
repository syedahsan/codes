#include<iostream>
using namespace std;

string str;

void permute(int start, int end)
{
	int range = end - start;
	if(range == 1) cout << str << " ";
	for(int i=0;i<range;i++)
	{
		swap(str[start],str[start+i]);
		permute(start+1,end);
		swap(str[start],str[start+i]);
	}
}

int main(void)
{
	cin >> str;
	permute(0,str.length());
	cout << endl;

}
