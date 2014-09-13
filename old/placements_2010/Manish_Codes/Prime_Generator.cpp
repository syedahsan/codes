#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
     int n;
     int sum = 0;
     cin >> n;
     vector<int>flag(n+1,0);
     flag[0] = 1;
     flag[1] = 1;
     for(int i=2;i<=n;i++)
     {
	   if(i*i > n) break;  
	   if(flag[i] == 0)
	   {
		   for(int j = i;j*i <=n;j++)
			   flag[i*j] = 1;
	   }
     }
     for(int i=0;i<=n;i++)
     {
	     if(flag[i] == 0)
		     sum+=i;
     }
     cout << sum << endl;
}
