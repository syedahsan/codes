#include<iostream>
using namespace std;

int count = 0;

void solve(int row, int n, int *array)
{
	if(row == n)
	{
		for(int i=0;i<n;i++)
			cout << i << "," << array[i] << " ";
		cout << endl;
		count++;
		return;
	}
	for(int col=0;col<n;col++)
	{
		int flag = 1;
		for(int j=0;j<row;j++)
		{
			if(array[j] == col || (row + col) == (j + array[j]) || (row - col) == (j - array[j]))
			       flag = 0;
		}
		if(flag == 1)
		{
			array[row] = col;
			solve(row+1,n,array);
		}	
	}

}

int main(void)
{
	int n;
	cin >> n;
	int array[n];
	solve(0,n,array);
	cout << count << endl;
}
