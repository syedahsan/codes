#include<iostream>
#include<vector>
using namespace std;

typedef struct nn
{
	int count;
	int value;
}node;

int main(void)
{
	int n;
	cout << "Enter total number of items" << endl;
	cin >> n;
	vector<int> b(n+1);
	cout << "Enter elements of the vector" << endl;
	for(int i=1;i<=n;i++)
		cin >> b[i];
	int W;
	cout << "Enter the sum" << endl;
	cin >> W;
	node B[n+1][W+1];
	for(int i=0;i<=n;i++)
		B[i][0].value = 0;
	for(int i=0;i<=W;i++)
		B[0][i].value = 0;
	for(int i=0;i<=n;i++)
		for(int w=0;w<=W;w++)
			B[i][w].count = 0;
	for(int i=0;i<=n;i++)
		B[i][0].count = 1;
	for(int i=0;i<=W;i++)
		B[0][i].count = 1;

	for(int i=1;i<=n;i++)
	{
		for(int w=1;w<=W;w++)
		{
			if(w >= b[i])
			{
				if(B[i-1][w].value < (B[i-1][w-b[i]].value+b[i]))
					B[i][w].value= B[i-1][w-b[i]].value+b[i];
				else
					B[i][w].value = B[i-1][w].value;
				if(B[i-1][w].value == w) 
				{
					B[i][w].count += B[i-1][w].count;
				}
				if((B[i-1][w-b[i]].value) == w-b[i])
				{
					B[i][w].count += B[i-1][w-b[i]].count; 
				}
				if(B[i][w].count==0)
				{
					if(B[i-1][w].value < B[i-1][w-b[i]].value+b[i])
					{
						if(B[i-1][w-b[i]].count == 0)
							B[i][w].count = 1;
						else
							B[i][w].count = B[i-1][w-b[i]].count;
					}
					else
						B[i][w].count=B[i-1][w].count;
				}
			}
			else
			{
				B[i][w].value = B[i-1][w].value;
				B[i][w].count =B[i-1][w].count;
			}
		}
	}
	for(int i =0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			cout << B[i][w].count<<","<<B[i][w].value << " ";
		}
		cout << endl;
	}
}

