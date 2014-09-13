#include <iostream>
using namespace std;


void matrixSpiral(int A[][6], int top, int left, int length, int width)
{
	if(length==0 or width ==0) return;

	for ( int i= left;i<left+length;i++)
		cout << A[i][top];

	for ( int j= top;j<top+width;j++)
		cout <<  A[left+length][j];

	for ( int i= left+length-1; i<=left;i--) //decrement
		cout << A[i][top+width];

	for ( int j= top+width-1;j<=top;j--) //decrement
		cout << A[left][j];

	matrixSpiral(A, top+1, left+1, length-1, width-1);

}

int main(void)
{
	int n;
	cin >> n;
	int matrix[n][6];
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			cin >> matrix[i][j];
	matrixSpiral(matrix,0,0,n,6);
}
