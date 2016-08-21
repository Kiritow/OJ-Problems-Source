#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max 10000+10
using namespace std;
int set[1010];
int city,road;
struct line
{
    int start;
    int end;
    int money;
}num[max];
bool cmp(line a,line b)
{
    return a.money<b.money;
}
int find(int p)
{
    int child=p;
    int t;
    while(p!=set[p])
    p=set[p];
    while(child!=p)
    {
        t=set[child];
        set[child]=p;
        child=t;
    }
    return p;
}
void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    set[fx]=fy;
}
int main()
{
    int i,j,x,y,c,t,need,exist;
    while(scanf("%d%d",&city,&road)!=EOF)
    {
        for(i=0;i<city;i++)
        set[i]=i;
        t=0;
        while(road--)
        {
            scanf("%d%d%d",&x,&y,&c);
            num[t].start=x;
            num[t].end=y;
            num[t].money=c;
            t++;
        }
        sort(num,num+t,cmp);
        need=0;
        for(i=0;i<t;i++)
        {
            if(find(num[i].start)!=find(num[i].end))
            {
                merge(num[i].start,num[i].end);
                need+=num[i].money;
            }
        }
        exist=0;
        for(i=0;i<city;i++)
        {
            if(set[i]==i)
            {
                exist++;
                if(exist>1)
                break;
            }
        }
        if(exist>1)
        printf("impossible\n\n");
        else
        printf("%d\n\n",need);
    }
    return 0;
}
