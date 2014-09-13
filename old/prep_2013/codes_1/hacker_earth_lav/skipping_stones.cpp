#include<stdio.h>
int main(){
        int n,L,D,i;
        scanf("%d %d %d",&n,&L,&D);
        float A[n+1], final[n+1];
        int Dist[n+1];
        A[0]=1.0;
        final[0]=1.0;
        Dist[0]=0;
        for (i=1;i<n+1;i++)
        {
                scanf("%f",&A[i]);
                final[i]=0;
        }
        for (i=1;i<n+1;i++)
                scanf("%d",&Dist[i]);
        int index,count;
        for(index=1 ;index<n+1;index++)
        {       int last=index-1;
                int flag=0;
                count=0;
                while(flag==0){
                        if ((Dist[index] - Dist[last]) <= L)
                        {       float newP = A[index]*final[last];
                                if(final[index] < newP)
                                        final[index] = newP;
                                last--;
                                count++;
                        }
                        else
                                flag=1;
                }
                if(count==0)
                        break;

        }
        if(count==0)
                printf("IMPOSSIBLE");
        else
                printf("%f",final[n]);
}
