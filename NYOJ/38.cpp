#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXPOINT 512

//#define dprintf(A,B...) printf(A,##B)
#define dprintf(A,B...)

int groupid[MAXPOINT];

struct EDGE
{
    int u,v;
    int w;
};

bool cmp_d(const EDGE& a,const EDGE& b)
{
    if(a.w==b.w)
    {
        if(a.u==b.u)
        {
            return a.v<b.v;
        }
        return a.u<b.u;
    }
    return a.w<b.w;
}
int findgroup(int pos)
{
    int f=groupid[pos];
    while(groupid[f]!=f) f=groupid[f];
    return f;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int V,E;
        scanf("%d %d",&V,&E);
        vector<EDGE> vec;
        EDGE tmp;
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d",&tmp.u,&tmp.v,&tmp.w);
            if(tmp.u>tmp.v)
                swap(tmp.u,tmp.v);
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end(),cmp_d);
        for(int i=0;i<MAXPOINT;i++)
        {
            groupid[i]=i;
        }
        int totalw=0;
        int choosed=0;
        for(int i=0;i<E&&choosed<V-1;i++)
        {
            int KA=findgroup(vec.at(i).u);
            int KB=findgroup(vec.at(i).v);
            if(KA!=KB)
            {
                /// Choose this Edge.
                dprintf("Choose %d %d %d\n",vec.at(i).u,vec.at(i).v,vec.at(i).w);
                choosed++;
                totalw+=vec.at(i).w;
                groupid[vec.at(i).u]=KA;
                groupid[vec.at(i).v]=KA;
                groupid[KB]=KA;
                dprintf("%d <- %d\n",vec.at(i).u,vec.at(i).v);
            }
        }
        vector<int> dpos;
        int dtmp;
        for(int i=0;i<V;i++)
        {
            scanf("%d",&dtmp);
            dpos.push_back(dtmp);
        }
        sort(dpos.begin(),dpos.end());
        totalw+=dpos.at(0);
        printf("%d\n",totalw);
    }
    return 0;
}
