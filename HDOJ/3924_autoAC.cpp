#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef __int64 LL;
const int MAX=30;
const int LIM=21;
LL num[MAX],rig[MAX],total[MAX];
int b[4];
LL gs(int L)
{
    LL res=0;
    for(int i=0;i<=L;i++)
    {
        for(int j=i;j<=L;j++)
        {
            int k=L-i-j;
            if(j>k) continue;
            b[0]=i;
            b[1]=j;
            b[2]=k;
            do
            {
                res+=num[b[0]]*num[b[1]]*num[b[2]];
            }while(next_permutation(b,b+3));
        }
    }
    return res;
}
LL getR(int L)
{
    LL res=0;
    for(int i=0;i<=L;i++)
    {
        res+=num[i]*num[L-i];
    }
    return res;
}
void init()
{
    num[0]=num[1]=1;
    for(int i=2;i<=LIM;i++) num[i]=gs(i-1);
    total[0]=0;
    for(int i=1;i<=LIM;i++) total[i]=total[i-1]+num[i];
    rig[0]=1;
    for(int i=1;i<=LIM;i++) rig[i]=getR(i);
}
int getNN(LL N)
{
    for(int i=1;i<=LIM;i++) if(total[i]>=N) return i;
}
void dfs(int L,LL N)
{
    if(L==1) {printf("X");return ;}
    int x=L-1;
    int ll,mm,rr;
    for(ll=0;N>num[ll]*rig[x-ll];ll++) N-=num[ll]*rig[x-ll];
    if(ll)
    {
        printf("(");
        dfs(ll,(N-1)/rig[x-ll]+1);
        printf(")");
    }
    N%=rig[x-ll];
    if(N==0) N=rig[x-ll];
    x-=ll;
    for(mm=0;N>num[mm]*num[x-mm];mm++) N-=num[mm]*num[x-mm];
    if(mm)
    {
        printf("(");
        dfs(mm,(N-1)/num[x-mm]+1);
        printf(")");
    }
    N%=num[x-mm];
    if(N==0) N=num[x-mm];
    x-=mm;
    if(x)
    {
        printf("(");
        dfs(x,N);
        printf(")");
    }
    printf("X");
}
int main()
{
    init();
    int T;scanf("%d",&T);
    int CN=0;
    while(T--)
    {
        LL N;scanf("%I64d",&N);
        int nn=getNN(N);
        printf("Case #%d: ",++CN);
        dfs(nn,N-total[nn-1]);
        puts("");
    }
    return 0;
}
