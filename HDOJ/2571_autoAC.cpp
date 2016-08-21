#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define max(a,b) (a>b?a:b)
#define smax(a,b,c) (max(max(a,b),c))
int a[22][1010];
int main()
{
    int t,i,j,han,lie,maxq,k;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            scanf("%d %d",&han,&lie);
            for(i=1;i<=han;i++)
            {
                for(j=1;j<=lie;j++)
                {
                    scanf("%d",&a[i][j]);
                }
            }
            for(i=1;i<=han;i++)
            {
                for(j=1;j<=lie;j++)
                {
                    if(i==1)
                    {
                        if(j==1);
                        else 
                        {
                            maxq=-200;
                            for(k=1;k<j;k++)
                            {
                                if(j%k==0)
                                {
                                    if(a[i][k]>maxq)maxq=a[i][k];
                                }
                            }
                            a[i][j]+=max(a[i][j-1],maxq);
                        }
                    }
                    else 
                    {
                        if(j==1)a[i][j]+=a[i-1][j];
                        else 
                        {
                            maxq=-200;
                            for(k=1;k<j;k++)
                            {
                                if(j%k==0)
                                {
                                    if(a[i][k]>maxq)maxq=a[i][k];
                                }
                            }
                            a[i][j]+=smax(a[i-1][j],a[i][j-1],maxq);
                        }
                    }
                }
            }
            printf("%d\n",a[han][lie]);
        }
    }
    return 0;
}
