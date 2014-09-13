#include<iostream>
using namespace std;

int matrix[2][2] = {{0,1},{1,1}};
int A[2][2] = {{0,1},{1,1}};
int C[2][2] = {{0,0},{0,0}};
int F[1][2] = {1,1};
void mulm(int n)
{
	if(n== 0)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				C[i][j] = 0;
				for(int k=0;k<2;k++)
					C[i][j]+=matrix[i][k]*matrix[k][j];
			}
	}
	else
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				C[i][j] = 0;
				for(int k=0;k<2;k++)
					C[i][j]+=A[i][k]*matrix[k][j];
			}
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			matrix[i][j] = C[i][j];
}

void fibbonacci(int n)
{
	if(n > 1)
	{
		fibbonacci(n/2);
		mulm(0);
		if(n%2 != 0)
		mulm(1);
	}
}

int main(void)
{
	int n;
	cin >> n;
	fibbonacci(n-1);
	for(int i=0;i<1;i++)
		for(int j=0;j<2;j++)
		{
			C[i][j] = 0;
			for(int k =0;k<2;k++)
				C[i][j]+=F[i][k]*matrix[k][j];
		}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			cout << matrix[i][j] << " " ;
		cout << endl;
	}
	cout << endl;
	cout << C[0][0] << endl;
}
