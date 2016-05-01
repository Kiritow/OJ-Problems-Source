#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
struct pack
{
    int profit,deadline;
};
pack p[MAXN];
bool cmp(const pack& a,const pack& b)
{
    return a.profit>b.profit;
}
bool isdayused[MAXN];

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        memset(p,0,sizeof(pack)*MAXN);
        memset(isdayused,false,sizeof(bool)*MAXN);
        for(int i=0;i<t;i++)
        {
            scanf("%d %d",&p[i].profit,&p[i].deadline);
        }
        sort(p,p+t,cmp);
        int sum=0;
        for(int i=0;i<t;i++)
        {
            for(int day=p[i].deadline;day>0;day--)
            {
                if(!isdayused[day])
                {
                    isdayused[day]=true;
                    sum+=p[i].profit;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
