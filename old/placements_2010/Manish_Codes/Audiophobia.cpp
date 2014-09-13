#include<stdio.h>


int Path[100][100];
int C,S,Q,c1,c2,d,q1,q2;

int Min(int n1,int n2)
{
	if(n1<n2)
		return n1;
	else
		return n2;
}

int Max(int n1,int n2)
{
	if(n1>n2)
		return n1;
	else
		return n2;
}

void FW()
{
	int k,i,j;
	for(i=1;i<=C;i++)
		Path[i][i]=0;

	for(k=1;k<=C;k++)
		for(i=1;i<=C;i++)
			for(j=1;j<=C;j++)
				Path[i][j] = Min( Path[i][j], Max( Path[i][k], Path[k][j] ) );
}

int main()
{
	int i,j,ca=0;
	while(1)
	{
		scanf("%d %d %d",&C,&S,&Q);
		if(C<=0||S<=0||Q<=0)
			break;

		for(i=1;i<=C;i++)
			for(j=1;j<=C;j++)
				Path[i][j]=10000;

		for(i=1;i<=S;i++)
		{
			scanf("%d %d %d",&c1,&c2,&d);
			Path[c1][c2]=d;
			Path[c2][c1]=d;
		}

		FW(); /* Floyed Warshall Alg Function*/

		if(ca>0)
			printf("\n");
		printf("Case #%d\n",++ca);
		for(i=1;i<=Q;i++)
		{
			scanf("%d %d",&q1,&q2);
			if(Path[q1][q2]==10000)
				printf("no path\n");
			else
				printf("%d\n",Path[q1][q2]);
		}
	}
}

