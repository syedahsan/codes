#include<iostream>
#include<vector>
using namespace std;

typedef struct nn
{
	int value;
	int count;
}node;

int main(void)
{
	int n;
	cin >> n;
	vector<int> sequence(n+1);
	for(int i=1;i<=n;i++)
		cin >> sequence[i];
	int sum;
	cin >> sum;
	node table[n+1][sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++)
			table[i][j].count = 0;
			
	for(int i=0;i<=n;i++)
	{
		table[i][0].value = 0;
		table[i][0].count = 1;
	}
	for(int i=0;i<=sum;i++)
	{
		table[0][i].value = 0;
		table[0][i].count = 1;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j >= sequence[i])
			{
				if(table[i-1][j].value > table[i-1][j-sequence[i]].value + sequence[i])
					table[i][j].value = table[i-1][j].value;
				else
					table[i][j].value = table[i-1][j-sequence[i]].value + sequence[i];
				if(table[i-1][j].value == j)
					table[i][j].count+=table[i-1][j].count;
				if(table[i-1][j-sequence[i]].value + sequence[i] == j)
					table[i][j].count+=table[i-1][j-sequence[i]].count;
				if(table[i][j].count == 0)
				{
					if(table[i-1][j].value < table[i-1][j-sequence[i]].value + sequence[i])
						 	table[i][j].count = table[i-1][j-sequence[i]].count;
					else
						table[i][j].count = table[i-1][j].count;
				}
			}
			else
			{
				table[i][j].value = table[i-1][j].value;
				table[i][j].count = table[i-1][j].count;
			}	
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
			cout << table[i][j].value << "," << table[i][j].count << " ";
		cout << endl;
	}
}
