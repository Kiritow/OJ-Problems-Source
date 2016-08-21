#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn=50005;
int m,t;
struct node
{
    int day;
    int start;
    int end;
} p[maxn];
int cmp(node a,node b)
{
    if(a.day==b.day)
    {
        return a.end<b.end;
    }
    else
        return a.day<b.day;
}
int main()
{
    int i;
    int tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&p[i].day,&p[i].start,&p[i].end);
        }
        sort(p,p+m,cmp);
        int temp=0;
        int sum=1;
        int k=0;
        for(i=1; i<m; i++)
        {
            if(p[i].day==p[k].day&&p[i].start>=p[temp].end)
            {
                temp=i;
                sum++;
            }
            if(p[i].day!=p[k].day)
            {
                k=i;
                temp=i;
                sum++;
            }
        }
        printf("Scenario #");
        printf("%d:\n",++tcase);
        printf("%d\n\n",sum);
    }
    return 0;
}
