#include <iostream>
#include <vector>
#include <set>
#include<cstdio>
using namespace std;
vector<int> a[23];
int ans,nn;
int b[22];
int tp=1<<22;
void init()
{
    for(int i=1;i<tp;i++)
    {
        int tmp=i;
        int k=0;
        int sum=0;
        while(tmp)
        {
            ++k;
            if(tmp&1)
            {
                sum+=k;
                if(sum>22) break;
            }
            tmp>>=1;
        }
        if(!tmp) a[sum].push_back(i);
    }
}
inline int total_one(int p)
{
    int c=0;
    while(p)
    {
        p&=p-1;
        c++;
    }
    return c;
}
int main()
{
    int T=0;
    int n,m;
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n+m==0) break;
        nn=1<<n;
        ++T;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        ans=0;
        set<int> now;
        now.insert(0);
        for(int i=0;i<m;i++)
        {
            set<int> next;
            for(set<int>::iterator it=now.begin();it!=now.end();it++)
            {
                int temp=a[b[i]].size();
                int sign=0;
                int tmp=*it;
                for(int j=0;j<temp;j++)
                {
                    if(a[b[i]][j]>=nn) continue;
                    if((tmp & a[b[i]][j]) ==0)
                    {
                        sign=1;
                        next.insert(tmp | a[b[i]][j]);
                    }
                }
                if(!sign) 
                {
                    int _tmp=total_one(tmp);
                    ans=ans>_tmp?ans:_tmp;
                }
            }
            now=next;
            if(now.size()==0) break;
        }            
        for(set<int>::iterator it=now.begin();it!=now.end();it++)
        {
            int _tmp=total_one(*it);
            ans=ans>_tmp?ans:_tmp;
        }
        printf("Game %d: %d\n",T,ans);
    }
    return 0;
}
