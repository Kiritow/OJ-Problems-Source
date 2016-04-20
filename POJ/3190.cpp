
#include <cstdio>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;


struct cow
{
    int start,over;
    int pos;
    bool operator <(const cow& b) const
    {
        if(over==b.over)
            return start>b.start;
        return over>b.over;
    }
};

bool cmp(const cow& a,const cow& b)
{
    if(a.start==b.start) return a.over<b.over;
    return a.start<b.start;
}


priority_queue<cow> bus;
int use[50001];
cow cowx[50001];

int cnt=1;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {

        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            cowx[i].start=a;
            cowx[i].over=b;
            cowx[i].pos=i;
        }
        sort(cowx,cowx+n,cmp);
        use[cowx[0].pos]=1;
        bus.push(cowx[0]);
        for(int i=1; i<n; i++)
        {
            if(!bus.empty()&&bus.top().over<cowx[i].start)
            {
                use[cowx[i].pos]=use[bus.top().pos];
                bus.pop();
            }
            else
            {
                ++cnt;
                use[cowx[i].pos]=cnt;
            }
            bus.push(cowx[i]);
        }
        printf("%d\n",cnt);
        for(int i=0; i<n; i++)
        {
            printf("%d\n",use[i]);
        }
    }
    return 0;
}


