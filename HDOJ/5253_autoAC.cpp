#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 1005
int father[N*N];
struct EDGE
{
    int u,v;
    int len;
    bool operator<(const EDGE& a)const  
    {
        return len<a.len;
    }
};
EDGE edge[N*N*4];
int map[N][N],m,n,k;
int Find(int x)
{
    return x==father[x]?x:father[x]=Find(father[x]);
}
bool Union(int x,int y)
{
    int a,b;
    a=Find(x);
    b=Find(y);
    if(a!=b)
    {
        father[a]=b;
        return true;
    }
    return false;
}
int process()
{
    int i;
    int sum=0;
    for(i=0;i<k;i++)
        if(Union(edge[i].u,edge[i].v))
            sum+=edge[i].len;
    return sum;
}
int main()      
{
    int T,t=0,i,j;
    EDGE e;
    scanf("%d",&T);
    t=0;
    while(T--)
    {
        k=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                father[i*n+j]=i*n+j;
                scanf("%d",&map[i][j]);
                if(j>0)
                {
                    e.u=i*n+j;
                    e.v=i*n+j-1;
                    e.len=abs(map[i][j]-map[i][j-1]);
                    edge[k++]=e;
                }
                if(i>0)
                {
                    e.u=i*n+j;
                    e.v=i*n+j-n;
                    e.len=abs(map[i][j]-map[i-1][j]);
                    edge[k++]=e;
                }
            }
        sort(edge,edge+k);
        printf ("Case #%d:\n", ++t);
        printf ("%d\n", process());
    }
    return 0;      
}
