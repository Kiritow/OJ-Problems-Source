#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 1000000
using namespace std;
int city,road;
int mapp[205][205];
int spand[205];
int select[205];
void dij(int city)
{
    int minn,k,i,j;
    memset(select,0,sizeof(select));
    for(i=1;i<=city;i++)
    spand[i]=mapp[1][i];
    spand[1]=0;select[1]=1;
    for(i=2;i<=city;i++)
    {
        minn=INF;k=-1;
        for(j=1;j<=city;j++)
        {
            if(!select[j]&&spand[j]<minn)
            {
                k=j;minn=spand[j];
            }
        }
        if(k==-1)break;
        select[k]=1;
        for(j=1;j<=city;j++)
        {
            if(spand[j]>spand[k]+mapp[k][j]&&!select[j])
            spand[j]=spand[k]+mapp[k][j];
        }
    }
    printf("%d\n",spand[city]);
}
int main()
{
    int i;int x,y,z;
    while(scanf("%d%d",&city,&road)!=EOF)
    {
        if(city==0||road==0)
        break;
        memset(mapp,INF,sizeof(mapp));
        memset(spand,INF,sizeof(spand));
        for(i=1;i<=road;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(mapp[x][y]>z||mapp[y][x]>z)
            {
                mapp[x][y]=z;mapp[y][x]=z;
            }
        }
        dij(city);
    }
    return 0;
}
