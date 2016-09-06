#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxx = 1010;
int Find(int x,int father[])
{
    while(x!=father[x]) x = father[x];
    return x;
}
void Union(int r1, int r2, int& counter,int father[])
{
    int a = Find(r1,father);
    int b = Find(r2,father);
    if(a!=b)
    {
        counter++;
        father[a] = b;
    }
}
void ini(int n,int father[])
{
    for(int i=1; i<=n; i++)
        father[i] = i;
}
int main()
{
    int n,m,k;
    int father_r[maxx];
    int father_b[maxx];
    while(scanf("%d %d %d",&n,&m,&k),n||m||k)
    {
        ini(n,father_r);
        ini(n,father_b);
        int counter_r,counter_b;
        counter_r = counter_b = 0;
        for(int i=1; i<=m; i++)
        {
            char ch=0;
            while(ch!='B'&&ch!='R')
                ch=getchar();
            int u,v;
            scanf("%d%d",&u,&v);
            if(ch=='B')
                Union(u,v,counter_b,father_b);
            else
                Union(u,v,counter_r,father_r);
        }
        if(k<=counter_b && k>=n-counter_r-1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
