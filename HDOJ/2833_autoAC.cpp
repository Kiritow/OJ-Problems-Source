#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 311
int num[N][N];
int len[N][N];
int main()
{
    int n,m;
    int i,l,k,t;
    int s,e,dis;
    int a,b,c,d;
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        {
            for(l=1;l<=n;l++)
            {
                if(i==l)    len[i][l]=0;
                else        len[i][l]=22222222;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&s,&e,&dis);
            if(len[s][e]<dis)    continue;
            len[s][e]=len[e][s]=dis;
            num[s][e]=num[e][s]=1;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(l=1;l<=n;l++)
                {
                    t=len[i][k]+len[k][l];
                    if(t>len[i][l])    continue;
                    if(t<len[i][l])
                    {
                        len[i][l]=t;
                        num[i][l]=num[i][k]+num[k][l];
                    }
                    else if(num[i][k]+num[k][l]>num[i][l])
                        num[i][l]=num[i][k]+num[k][l];
                }
            }
        }
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int ans=-1;
        for(i=1;i<=n;i++)
        {
            for(l=1;l<=n;l++)
            {
                if(num[i][l]>ans
                    && (len[a][b]==len[a][i]+len[i][l]+len[l][b])
                    && (len[c][d]==len[c][i]+len[i][l]+len[l][d])
                    )
                    ans=num[i][l];
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
