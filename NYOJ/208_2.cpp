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

int father[MAXN];

bool cmp(const pack& a,const pack& b)
{
    return a.profit>b.profit;
}

int GetFather(int pos)
{
    if(father[pos]==-1)
    {
        /// This pos is itself's father
        return pos;
    }
    /// Else , this pos has a father. So it should know who is his Eldest Father.
    father[pos]=GetFather(father[pos]);
    /// And then , report back to it's caller.
    return father[pos];
}

int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        /// Reset father
        /** This way caused TLE.
        for(int i=0;i<t;i++)
        {
            father[i]=i;
        }
        */
        memset(father,-1,sizeof(int)*MAXN);
        for(int i=0;i<t;i++)
        {
            scanf("%d %d",&p[i].profit,&p[i].deadline);
        }
        sort(p,p+t,cmp);
        int sum=0;
        for(int i=0;i<t;i++)
        {
            int ans=GetFather(p[i].deadline);
            if(ans>0)
            {
                /// This pos's father is not 0 : which means it's possible to sell this thing.
                sum+=p[i].profit;
                /// And This pos become a son of the pos on its left.
                father[ans]=GetFather(ans-1);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
