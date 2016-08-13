#include<stdio.h>
#include<algorithm>
#define max 50*99+10
using namespace std;
int set[110];
struct line
{
    int dis;
    int start;
    int end;
}num[max];
bool cmp(line a,line b)
{
    return a.dis<b.dis;
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
    int city,need;
    int n,i,j;
    while(scanf("%d",&city)&&(city!=0))
    {
        for(i=1;i<=city;i++)
        set[i]=i;
        n=city*(city-1)/2;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&num[i].start,&num[i].end,&num[i].dis);
        }
        sort(num,num+n,cmp);
        need=0;
        for(i=0;i<n;i++)
        {
            if(find(num[i].start)!=find(num[i].end))
            {
                merge(num[i].start,num[i].end);
                need+=num[i].dis;
            }
        }
        printf("%d\n",need);
    }
    return 0;
}
