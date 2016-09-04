#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
const int  inf=99999991;
using namespace std;
double  map[55][55],dis[55];
int n;
bool vs[55];
struct Node
{
    int x,y;
}node[55];
double Min(double a,double b)
{
    if(a>b)return b;
    else return a;
}
double  prim(int x)
{
    int i,k,mark;
    memset(vs,0,sizeof(vs));
    vs[x]=1;
    for(i=0;i<n;i++)
    {
        dis[i]=map[i][0];
    }vs[0]=1;
    if(x==0)
    {
        for(i=0;i<n;i++){
            dis[i]=map[i][1];
        }vs[1]=1;
    }
    double MIN,SUM=0;
    for(k=1;k<n-1;k++)
    {
        MIN=inf;
        for(i=0;i<n;i++)
           if(!vs[i]&&MIN>dis[i])
           {
               MIN=dis[i];
               mark=i;
           }
        SUM+=MIN;
        vs[mark]=1;
        for(i=0;i<n;i++)
            if(!vs[i]&&dis[i]>map[mark][i])
               dis[i]=map[mark][i];
    }
    return SUM;
}
int main()
{
    int i,j,CASE;
    double d,x1,y1;
    scanf("%d",&CASE);
    while(CASE--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            map[i][i]=0;
            scanf("%d%d",&node[i].x,&node[i].y);
            for(j=i-1;j>=0;j--)
            {
                x1=node[i].x-node[j].x;
                y1=node[i].y-node[j].y;
                d=sqrt(x1*x1+y1*y1);
                map[i][j]=map[j][i]=d;
            }
        }
        double h,g=inf;
        for(i=0;i<n;i++)
        {
           h=prim(i);
           g=Min(g,h);
        }
        printf("%.2lf\n",g);
    }
    return 0;
}
