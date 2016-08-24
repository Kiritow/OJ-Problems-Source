#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=1010;
int c[N][N];
bool vis[N][N];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int val)
{
    int i=y;
    while(x<=N)
    {
        y=i;
        while(y<=N)
        {
            c[x][y]+=val;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
int sum(int x,int y)
{
    int i,sum=0;
    i=y;
    while(x)
    {
        y=i;
        while(y)
        {
            sum+=c[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int n,x1,x2,y1,y2;
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));
    while(n--)
    {
        getchar();
        char c;
        scanf("%c ",&c);
        if(c=='Q')
        {
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            x1++,x2++,y1++,y2++;
            if(x1>x2)swap(x1,x2);
            if(y1>y2)swap(y1,y2);
            printf("%d\n",(sum(x2,y2)+sum(x1-1,y1-1)-sum(x1-1,y2)-sum(x2,y1-1)));
        }
        else if(c=='B')
        {
            scanf("%d%d",&x1,&y1);
            if(vis[x1+1][y1+1]==1)
                continue;
            else
                add(x1+1,y1+1,1);
            vis[x1+1][y1+1]=1;
        }
        else if(c=='D')
        {
            scanf("%d%d",&x1,&y1);
            if(vis[x1+1][y1+1]==0)
                continue;
            else
                add(x1+1,y1+1,-1);
            vis[x1+1][y1+1]=0;
        }
    }
    return 0;
}
