#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
long long c[MAXN];
int lowbit(int x)
{
    return x&(-x);
}
long long sum(int i)
{
    long long ret = 0;
    while(i > 0)
    {
        ret += c[i];
        i -= lowbit(i);
    }
    return ret;
}
void add(int i,long long val)
{
    while(i <= 100000)
    {
        c[i] += val;
        i += lowbit(i);
    }
}
int s1[MAXN];
int s2[MAXN];
int sz1,sz2;
vector<int>vec1[10010];
vector<int>vec2[10010];
int a[10010];
int b[10010];
void calc(int u)
{
    int id = lower_bound(s1,s1+sz1,s2[u]) - s1;
    if(id == 0)
    {
        vec1[0].push_back(u);
        vec2[u].push_back(0);
    }
    else if(id == sz1)
    {
        vec1[sz1-1].push_back(u);
        vec2[u].push_back(sz1-1);
    }
    else 
    {
        if(s2[u] - s1[id-1] < s1[id] - s2[u] )
        {
            vec1[id-1].push_back(u);
            vec2[u].push_back(id-1);
        }
        else if(s2[u] - s1[id-1] > s1[id] - s2[u])
        {
            vec1[id].push_back(u);
            vec2[u].push_back(id);
        }
        else
        {
            vec1[id-1].push_back(u);
            vec2[u].push_back(id-1);
            vec1[id].push_back(u);
            vec2[u].push_back(id);
        }
    }
}
int get(int u)
{
    if(vec2[u].size() == 1)
    {
        return a[vec2[u][0]];
    }
    else
    {
        return max(a[vec2[u][0]],a[vec2[u][1]]);
    }
}
int link[10010];
int main()
{
    int T;
    int iCase = 0;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        printf("Case #%d:\n",iCase);
        sz1 = 0;sz2 = 0;
        memset(c,0,sizeof(c));
        int u,v;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            if(v == 0)
                s2[sz2++] = u;
            else
            {
                s1[sz1++] = u;
                link[i] = sz1-1;
                add(v,1);
                a[sz1-1] = v;
            }
            vec1[i].clear();
            vec2[i].clear();
        }
        for(int i = 0;i < sz2;i++)
            calc(i);
        for(int i = 0;i < sz2;i++)
        {
            b[i] = get(i);
            add(b[i],1);
        }
        char op[10];
        int m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                scanf("%d",&u);
                printf("%d\n",(int)sum(u));
            }
            else
            {
                scanf("%d%d",&u,&v);
                u = link[u];
                add(a[u],-1);
                a[u] = v;
                add(a[u],1);
                for(int i = 0;i < vec1[u].size();i++)
                {
                    int p = get(vec1[u][i]);
                    add(b[vec1[u][i]],-1);
                    b[vec1[u][i]] = p;
                    add(p,1);
                }
            }
        }
    }
    return 0;
}
