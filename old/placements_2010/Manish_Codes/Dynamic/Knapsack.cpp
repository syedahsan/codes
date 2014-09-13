#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> v(n+1,0);
	vector<int> w(n+1,0);
	int W;
	for(int i=1;i<=n;i++)
		cin >> v[i];
	for(int i=1;i<=n;i++)
		cin >> w[i];
	cin >> W;
	vector < vector<int> > array(n+1,vector<int>(W+1,0));
	vector< vector<int> > keep(n+1,vector<int>(W+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(w[i] <= j && array[i][j-w[i]] + v[i] > array[i-1][j])
			{
				array[i][j] = array[i-1][j-w[i]] + v[i];
				keep[i][j] = 1;
			}
			else
				array[i][j] = array[i-1][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for( int j=0;j<=W;j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	int k = W;
        for(int i=n;i>0;i--)	
	{
		if(keep[i][k] == 1)
		{
			cout << i << " ";
			k = k- w[i];
		}
	}
	cout << endl;



}
