#include<stdio.h>
int main(){
        int n,L,D,i;
        scanf("%d %d %d",&n,&L,&D);
        float A[1002], final[1002];
        int Dist[1002];
        A[0]=1.0;
        final[0]=1.0;
        Dist[0]=0;
        A[n+1]=1.0;
        final[n+1]=0.0;
        Dist[n+1]=D;

        for (i=1;i<n+1;i++)
        {
                scanf("%f",&A[i]);
                final[i]=0.0;
        }
        for (i=1;i<n+1;i++)
                scanf("%d",&Dist[i]);
        int index,count;
        for(index=1 ;index<n+2;index++)
        {       int last=index-1;
                int flag=0;
                count=0;
                while(flag==0 && last>=0){
                        if ((Dist[index] - Dist[last]) <= L)
                        {       float newP = A[index]*final[last];
//                                if(index==n+1)
  //                                     printf("values %f %f %f",newP,A[index],final[last]);
                                if(final[index] < newP)
                                        final[index] = newP;
                                last--;
                                count++;
                        }
                        else
                                flag=1;
                }
    //            printf("\n\n");
      //          for (i=0;i<n+2;i++)
        //                printf("%f ",final[i]);
                if(count==0)
                        break;
                //printf("\n");

        }
        
        if(count==0 || (D - Dist[n]>L))
                printf("IMPOSSIBLE");
        else if(L>=D)
                printf("1.000000");
        else
                printf("%f",final[n+1]);
}
