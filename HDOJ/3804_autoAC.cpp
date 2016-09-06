#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <set>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
#define N 100005
struct res
{
    int i,x;
};
struct pt
{
    int p,v;
};
struct que
{
    int x,y,ans;
};
vector<pt> a[N];
vector<que> query;
vector<int> hasq[N];
stack<res> stk;
multiset<int> v;
multiset<int>::iterator it;
bool instack[N];
int iv[N];
int main(int argc, char** argv)
{
    int tcase,i,j,n,q,x,y,w;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            a[i].clear();
        iv[1]=-1;
        for(i=1;i<=n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            iv[y]=w;
            pt temp;
            temp.p=y;
            temp.v=w;
            a[x].push_back(temp);
            temp.p=x;
            temp.v=w;
            a[y].push_back(temp);
        }
        scanf("%d",&q);
        for(i=1;i<=n;i++)
            hasq[i].clear();
        for(i=1;i<=q;i++)
            query.clear();
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&x,&y);
            que temp;
            temp.x=x;
            temp.y=y;
            temp.ans=-1;
            query.push_back(temp);
            hasq[x].push_back(query.size()-1);
        }
        v.clear();
        v.insert(-1);
        v.insert(-1);
        v.insert(-1);
        while(!stk.empty()) stk.pop();
        memset(instack,0,sizeof(instack));
        res temp;
        temp.x=1;
        temp.i=0;
        instack[1]=1;
        stk.push(temp);
        while(!stk.empty())
        {
            res now=stk.top();
            stk.pop();
            if (now.i==0)
            {
                if (hasq[now.x].size()>0)
                    for(int i=0;i<hasq[now.x].size();i++)
                    {
                        int qi=hasq[now.x][i];
                        int qx=query[qi].x;
                        int qy=query[qi].y;
                        int ans;
                        it=v.upper_bound(qy);
                        it--;
                        ans=(*it);
                        query[qi].ans=ans;
                    }
            }
            if (now.i==a[now.x].size()) {v.erase(v.find(iv[now.x]));continue;}   
            now.i++;
            stk.push(now);
            res next;
            next.i=0;
            next.x=a[now.x][now.i-1].p;
            if (!instack[next.x])
            {
              v.insert(a[now.x][now.i-1].v);
              stk.push(next);
              instack[next.x]=1;
            }
        }
        for(i=0;i<query.size();i++)
            printf("%d\n",query[i].ans);
    }
    return 0;
}
