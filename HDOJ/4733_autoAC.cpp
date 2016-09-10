#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<bitset>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
const int mod=1000000000+7;
char A[maxn],B[maxn];
int n,lsts[maxn][2],zero[maxn];
ll dp[maxn][2];
bool check(int i)
{
    return (i+1>n)||(A[i+1]!='0'&&B[i+1]!='0'&&zero[i+2]);
}
void solve()
{
    lsts[0][0]=dp[0][0]=1;
    lsts[0][1]=dp[0][1]=0;
    for(int i=1;i<=n;++i)
    {
        if(A[i]=='?'&&B[i]=='?')
        {
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
            dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
            lsts[i][0]=lsts[i-1][0]+lsts[i-1][1];
            lsts[i][1]=lsts[i-1][0]+lsts[i-1][1];
            if(lsts[i][0]>2) lsts[i][0]=2;
            if(lsts[i][1]>2) lsts[i][1]=2;
        }
        else if(A[i]=='?'||B[i]=='?'||(A[i]==B[i]))
        {
            if(A[i]=='0'||B[i]=='0')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
                lsts[i][0]=lsts[i-1][0];
                lsts[i][1]=lsts[i-1][1];
            }
            else
            {
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0];
                lsts[i][0]=lsts[i-1][1];
                lsts[i][1]=lsts[i-1][0];
            }
        }
        else
        {
            dp[i][0]=dp[i][1]=0;
            lsts[i][0]=lsts[i][1]=0;
        }
    }
    zero[n+1]=1;
    for(int i=n;i>=1;--i)
    {
        if(A[i]=='1'||B[i]=='1')
            zero[i]=0;
        else zero[i]=zero[i+1];
    }
    ll sum=0,tmp;
    int dt=0,pos=-1,dtmp;
    for(int i=1;i<=n;++i)
    {
        if(A[i]=='?'&&B[i]=='?')
        {
            tmp=(dp[i-1][0]+dp[i-1][1])%mod;
            dtmp=lsts[i-1][0]+lsts[i-1][1];
            if(dtmp&&check(i))
            {
                pos=i;
                sum=(sum+tmp)%mod;
                dt+=dtmp;
                if(dt>2) dt=2;
            }
        }
        else if(A[i]=='?'||B[i]=='?'||(A[i]!=B[i]))
        {
            if(A[i]=='0'||B[i]=='1')
            {
                tmp=dp[i-1][0];
                dtmp=lsts[i-1][0];
            }
            else
            {
                tmp=dp[i-1][1];
                dtmp=lsts[i-1][1];
            }
            if(dtmp&&check(i))
            {
                pos=i;
                sum=(sum+tmp)%mod;
                dt+=dtmp;
                if(dt>2) dt=2;
            }
        }
    }
    if(dt==0) printf("Impossible\n");
    else if(dt>1) printf("Ambiguous %I64d\n",sum);
    else
    {
        for(int i=pos+1;i<=n;++i)
            A[i]='1',B[i]='0';
        char ch,last;
        if(A[pos]=='0'||B[pos]=='1') ch='0';
        else ch='1';
        A[pos]='0';B[pos]='1';
        for(int i=pos-1;i>=1;--i)
        {
            last=ch;
            if(A[i]=='1'||B[i]=='1') ch=(ch=='0')?'1':'0';
            A[i]=B[i]=last;
        }
        for(int i=n;i>1;--i)
        {
            if(A[i-1]==A[i]) A[i]='0';
            else A[i]='1';
            if(B[i-1]==B[i]) B[i]='0';
            else B[i]='1';
        }
        printf("%s\n",A+1);
        printf("%s\n",B+1);
    }
}
int main()
{
    int t,tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",A+1);
        scanf("%s",B+1);
        n=strlen(A+1);
        printf("Case #%d:\n",++tcase);
        solve();
    }
    return 0;
}
