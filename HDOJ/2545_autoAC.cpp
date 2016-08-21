#include <iostream>
#include <stdio.h>
using namespace std;
#define  Max 100001
int father[Max];
void Init()
{
    int i;
    for(i=0;i<Max;++i)
        father[i]=i;
}
int Findfather(int x)
{
    int count=0;
    while (x!=father[x])
    {
        count++;
        x=father[x];
    }
    return count;
}
void Union(int x,int y)
{
    father[y]=x;
}
int main()
{
    int n,m,x,y,i,t1,t2;
    while (scanf("%d%d",&n,&m),n&&m)
    {
        Init();
        for(i=0;i<n-1;++i)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        for(i=0;i<m;++i)
        {
            scanf("%d%d",&x,&y);
            t1=Findfather(x);
            t2=Findfather(y);
            if(t1<=t2)
            printf("lxh\n");
            else
            {
            printf("pfz\n");
            }
        }
    }
}
