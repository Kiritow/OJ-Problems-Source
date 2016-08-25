#include<stdio.h>
__int64 mmg[1005],n,k;
__int64 C[1005][1000],flag[1005][1000];
int main()
{
    int i,j;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        C[1][0]=C[1][1]=1%k;
        flag[1][0]=flag[1][1]=(1/k)%2;
        for(i=2;i<=n;i++)
        {
            C[i][0]=C[i][i]=1%k;
            flag[i][0]=flag[i][i]=(1/k)%2;
            for(j=1;j<i;j++)
            {
                C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
                flag[i][j]=flag[i-1][j]+flag[i-1][j-1]+(C[i-1][j]+C[i-1][j-1])/k;
                flag[i][j]=flag[i][j]%2;
            }
        }
        mmg[1]=1%k;
        mmg[2]=1%k;
        for(i=3;i<=n;i++)
        {
            mmg[i]=mmg[i-1];
            for(j=1;j<=(i-1)/2;j++)
            {
                if(i-1==2*j)
                {
                    if(flag[i-1][j]==1)
                        mmg[i]+=(((mmg[j]%k)*(mmg[i-j-1]%k))%k)*(((C[i-1][j]+k)/2)%k);
                    else
                        mmg[i]+=(((mmg[j]%k)*(mmg[i-j-1]%k))%k)*(((C[i-1][j])/2)%k);
                }
                else
                    mmg[i]+=(((mmg[j]%k)*(mmg[i-j-1]%k))%k)*(C[i-1][j]%k);
                mmg[i]=mmg[i]%k;
            }
        }
        printf("%I64d\n",mmg[n]);
    }
}
