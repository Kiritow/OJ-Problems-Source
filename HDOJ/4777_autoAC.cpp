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
const int MAXN = 200010;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && prime[j] <= MAXN/i;j++)
        {
            prime[prime[j]*i] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for(int i = 1;prime[i] <= tmp/prime[i];i++)
    {
        factor[fatCnt][1] = 0;
        if(tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while(tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}
int L[MAXN],R[MAXN];
int a[MAXN];
int b[MAXN];
int n,m;
int lowbit(int x)
{
    return x & (-x);
}
int c[MAXN];
void add(int i,int val)
{
    if(i == 0)return;
    while(i <= n)
    {
        c[i] += val;
        i += lowbit(i);
    }
}
int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}
vector<int>vec[MAXN];
struct Node
{
    int l,r;
    int index;
    void input()
    {
        scanf("%d%d",&l,&r);
    }
};
bool cmp(Node p1,Node p2)
{
    return p1.r < p2.r;
}
Node node[MAXN];
int ans[MAXN];
int pp[MAXN][15];
int main()
{
    getPrime();
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 0;i < m;i++)
        {
            node[i].input();
            node[i].index = i;
        }
        for(int i = 1;i < MAXN;i++)b[i] = n+1;
        for(int i = n;i >= 1;i--)
        {
            getFactors(a[i]);
            R[i] = n+1;
            pp[i][0] = fatCnt;
            for(int j = 0;j < fatCnt;j++)
            {
                R[i] = min(R[i],b[factor[j][0]]);
                b[factor[j][0]] = i;
                pp[i][j+1] = factor[j][0];
            }
        }
        for(int i = 1;i < MAXN;i++)b[i] = 0;
        for(int i = 1;i <= n;i++)
        {
            L[i] = 0;
            fatCnt = pp[i][0];
            for(int j = 0;j < fatCnt;j++)
            {
                factor[j][0] = pp[i][j+1];
                L[i] = max(L[i],b[factor[j][0]]);
                b[factor[j][0]] = i;
            }
        }
        sort(node,node+m,cmp);
        memset(c,0,sizeof(c));
        for(int i = 1; i <= n+1;i++)
        {
            c[i] = 0;
            vec[i].clear();
        }
        for(int i = 1;i <= n;i++)vec[R[i]].push_back(i);
        int id = 1;
        for(int i = 0;i < m;i++)
        {
            while(id <= n && id <= node[i].r)
            {
                add(L[id],1);
                int sz = vec[id].size();
                for(int j = 0;j < sz;j++)
                {
                    int v = vec[id][j];
                    add(L[v],-1);
                    add(v,1);
                }
                id++;
            }
            ans[node[i].index] = sum(node[i].r) - sum(node[i].l-1);
            ans[node[i].index] = node[i].r - node[i].l +1 - ans[node[i].index];
        }
        for(int i = 0;i < m;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
