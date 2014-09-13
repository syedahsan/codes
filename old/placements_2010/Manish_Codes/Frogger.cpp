#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main(void)
{

	int  graph[300][300],x[300],y[300],v=1;
	int n,i,j,k,k1,k2;
	while(scanf("%d",&n) && n)
	{

		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				graph[i][j]=graph[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}  

		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]));
				}
			}
		}
		printf("Scenario #%d\n",v++);
		printf("Frog Distance = %.3lf\n",sqrt((double)graph[0][1]));
	}
}

