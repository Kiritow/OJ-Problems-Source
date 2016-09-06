#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=700000;
int Q,N,T;
__int64 PD,PN;
__int64 must;
int n;
__int64 d[maxn];
__int64 f[maxn];
void solve(__int64 t,__int64 P)
{
    __int64 k;
    if (t>T*2) k=(t-T*2)/T;
    else k=0;
    must+=k*P;
    for (int i=0;i<t-k*T;i++)
        d[++n]=P;
}
__int64 ff(int i)
{
    if (i<=0) return 0;
    else return f[i];
}
__int64 max(__int64 a,__int64 b)
{
    if (a>b) return a;
    else return b;
}
void Dp()
{
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        f[i]=max(ff(i-1),ff(i-T)+d[i]);
}
int main()
{
    scanf("%d",&Q);
    for (int ci=1;ci<=Q;ci++)
    {
        scanf("%d%d%I64d%I64d",&N,&T,&PD,&PN);
        must=n=0;
        for (int i=0;i<N;i++)
        {
            __int64 t1,t2;
            scanf("%I64d%I64d",&t1,&t2);
            solve(t1,PD);
            solve(t2,PN);
        }
        Dp();
        printf("Case %d: %I64d\n",ci,must+f[n]);
    }
}
