#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void  merge(int *a, int *b, int n, int m)
{
	int index = m+n+1;
	while(m>=0 && n>=0)
	{
		if(a[n] >= b[m])
		{
		    a[index] = a[n];
		    n--; 
		}
		else
		{
		    a[index]= b[m];
                    m--;
		}
		index--;
	}
	if(m>=0)memcpy(a,b,(m+1)*sizeof(int));
}

int main(void)
{
	int n,m;
	cin >> n;
	cin >> m;
	int a[n+m];
	int b[m];
	for(int i=0;i<n;i++)
	    cin >> a[i];
	for(int i=0;i<m;i++)
            cin >> b[i];
	merge(a,b,n-1,m-1);
	for(int i=0;i<m+n;i++)
		cout << a[i] << " ";
	cout << endl;

}
