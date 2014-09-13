using namespace std;
#include<iostream>
#include<string>

int parent[26];
int getParent(int k)
{
	while(parent[k]!=k)
		return getParent(parent[k]);
}
int main()
{
	int n,i,n1,j,k,flag,indeg,outdeg,num=2,indeg1,outdeg1,j1,k1,x,y,p;
	char tempChr;
	string in;
	cin >> n;

	for(i=0;i<n;i++)
	{
		int a[200][200]={0};
		int b[200][200]={0};
		int c[26][26] = {0};
		int eit[26] = {0};
		int f;
		for(p=0;p<26;p++)
			parent[p] = p;
		cin >> n1;
		for(j=0;j<n1;j++)
		{
			cin>>in;
			f = in[0]-97;
			a[in[0]][in[in.size()-1]]++;
			eit[in[0]-97]=1;
			eit[in[in.size()-1]-97]=1;
			if(c[in[0]-97][in[in.size()-1]-97]==0)
				c[in[0]-97][in[in.size()-1]-97]=1;
//			b[in[0]][in[in.size()-1]]++;

		}
		//	for(j=0;j<200;j++)for(k=0;k<200;k++)if(a[j][k]>0)cout << j << '\t' << k << endl;
		k=0;
		num=2;
		flag=0;
		for(j='a';j<='z';j++)
		{
			indeg=0;
			outdeg=0;
			indeg1=1;outdeg1=1;
			for(k='a';k<='z';k++)
			{
			//	if(b[j][k]==0&&b[k][j]==0){for(j1=0;j1<200;j1++){for(k1=0;k1<200;k1++){if(b[k1][j1]>0){flag=1;break;}}}}
				indeg=indeg+a[j][k];
				outdeg=outdeg+a[k][j];
			}


			if(indeg-outdeg==1){num--;indeg--;}
			else if(indeg-outdeg==-1){num--;outdeg--;}
			else if(indeg-outdeg==0)continue;
			else {flag=1;cout<<"The door cannot be opened."<<endl;break;}


		}
		if(flag==1){flag=0;continue;}
		else if((num==0||num==2))
		{
			//Connectivity

			for(x=0;x<26;x++)
				for(y=0;y<26;y++)
				{
					if(c[x][y]==1)
					{
						int t1 = getParent(x);
						int t2 = getParent(y);
						if(t1==x && t2==y)
							parent[y] = x;
						else if(t1!=x && t2==y)
							parent[y] = t1;
						else if(t1==x && t2!=y)
							parent[x] = t2;
						else
							parent[t1] = t2;
					}
				}
//			for(x=1;x<26;x++)
//				cout << getParent(x) << " ";
//			cout << endl;
			int ch = getParent(f),ans=1;
			for(x=0;x<26;x++)
				if(eit[x]==1 && getParent(x)!=ch)
					ans=0;
			if(ans)
				cout<<"Ordering is possible."<<endl;
			else
				cout<<"The door cannot be opened."<<endl;
		}
		else {cout<<"The door cannot be opened."<<endl;}
	}
	return 0;
}
