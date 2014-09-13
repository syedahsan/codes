#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef pair<int,int> Pair;

int main(void)
{
	int n;
	cin >> n;
	vector<int> array(n,0);
	for(int i=0;i<n;i++)
	    cin >> array[i];
	map<int,int>Repeated;
	for(int i=0;i<n;i++)
	{
		if(Repeated.find(array[i])!= Repeated.end())
		{
		   cout << array[i] << endl;
		   break;
		}
		Repeated[array[i]] = i;
	}

}
