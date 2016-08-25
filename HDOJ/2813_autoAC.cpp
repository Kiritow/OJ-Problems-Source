#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;
map<string,int>q;
const int M=201;
const int inf=999999999;
int Map[M][M],match[M],lx[M],ly[M],vx[M],vy[M];
int n,m;
int hungery(int u)
{
    int i;
    vx[u]=1;
    for(i=1;i<=m;i++)
    {
        if(!vy[i]&&lx[u]+ly[i]==Map[u][i])
        {
            vy[i]=1;
            if(match[i]==-1||hungery(match[i]))
            {
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void KM()
{
    int i,temp,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    lx[i]=max(lx[i],Map[i][j]);
    memset(ly,0,sizeof(ly));
    memset(match,-1,sizeof(match));
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            memset(vx,0,sizeof(vx));
            memset(vy,0,sizeof(vy));
            if(hungery(i))
            break;
            temp=inf;
            for(j=1;j<=n;j++)
            if(vx[j])
            for(int z=1;z<=m;z++)
            if(!vy[z]&&temp>lx[j]+ly[z]-Map[j][z])
            temp=lx[j]+ly[z]-Map[j][z];
            for(j=1;j<=n;j++)
            if(vx[j])
            lx[j]-=temp;
            for(j=1;j<=m;j++)
            if(vy[j])
            ly[j]+=temp;
        }
    }
}
int main()
{
    int i,k,w,num1,num2,j;
    char s1[21],s2[21];
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        Map[i][j]=-inf;
        num1=num2=0;
        for(i=1;i<=k;i++)
        {
            scanf("%s%s%d",s1,s2,&w);
            if(q[s1]==0)
            q[s1]=++num1;
            if(q[s2]==0)
            q[s2]=++num2;
            Map[q[s1]][q[s2]]=-w;
        }
        KM();
        int sum=0;
        for(i=1;i<=m;i++)
        if(match[i]!=-1&&Map[match[i]][i]!=-inf)
        sum+=Map[match[i]][i];
        printf("%d\n",-sum);
    }
}
