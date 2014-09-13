#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	string Source,Destination;
	cin >> Source >> Destination;
	int cost;
	int n = Source.length();
	int m = Destination.length();
	vector< vector<int> > d(m+1,vector<int>(n+1,0));
	for(int i=0;i<=n;i++)
		d[0][i] = i;
	for(int j =0;j<=m;j++)
		d[j][0] = j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(Source[i-1] == Destination[j-1])cost = 0;
			else cost = 1; 
			d[j][i] = min(d[j][i-1]+1,min(d[j-1][i]+1,d[j-1][i-1]+cost));
		}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
	while(m > 0 || n > 0)
	{
		int value = d[m][n];
		if(m > 0 && d[m-1][n] < value)
		{
			cout << "Insert: " << Destination[m-1] << endl;
			m--;
		}
		else if(n > 0 && d[m][n-1] < value)
		{
			cout << "Deletion: " << Source[n-1] << endl;
			n--;
		}
		else if(m >0 && n > 0 && d[m-1][n-1] < value)
		{
			cout << "Substitution: " <<  Source[n-1] <<  "  By  " << Destination[m-1] << endl;
			m--;
			n--;
		}
		else if(m > 0 && n > 0 && d[m-1][n-1] == value)
		{
			m--;
			n--;
		}
	}
}
