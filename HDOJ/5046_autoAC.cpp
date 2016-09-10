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
#include <assert.h>
using namespace std;
const int maxnode = 4000;
const int MaxM = 70;
const int MaxN = 70;
int K;
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN],S[MaxM];
    int ands,ans[MaxN];
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c)
    {
        for(int i = D[c];i != c;i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c)
    {
        for(int i = U[c];i != c;i = U[i])
            L[R[i]]=R[L[i]]=i;
    }
    bool v[maxnode];
    int f()
    {
        int ret = 0;
        for(int c = R[0];c != 0;c = R[c])v[c] = true;
        for(int c = R[0];c != 0;c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c];i != c;i = D[i])
                    for(int j = R[i];j != i;j = R[j])
                        v[Col[j]] = false;
            }
        return ret;
    }
    bool Dance(int d)
    {
        if(d + f() > K)return false;
        if(R[0] == 0)return d <= K;
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            if(Dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return false;
    }
};
DLX g;
struct Point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}city[MaxM];
long long dis(Point a,Point b)
{
    return (long long)abs(a.x-b.x)+(long long)abs(a.y-b.y);
}
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&K);
        assert(n >= 1 && n <= 60 && K >= 1 && K <= n);
        for(int i = 0;i < n;i++){
            city[i].input();
            assert(abs(city[i].x) <= 1000000000);
            assert(abs(city[i].y) <= 1000000000);
        }
        long long l = 0, r = 100000000000LL;
        long long ans = 0;
        while(l <= r)
        {
            long long mid = (l+r)/2;
            g.init(n,n);
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    if(dis(city[i],city[j]) <= mid)
                        g.Link(i+1,j+1);
            if(g.Dance(0)){r = mid-1;ans = mid;}
            else l = mid+1;
        }
        printf("Case #%d: %I64d\n",iCase,ans);
    }
    return 0;
}
