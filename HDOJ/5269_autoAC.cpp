#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#define zeros(a) memset(a,0,sizeof(a))
#define ones(a) memset(a,-1,sizeof(a))
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define rep(i,n) for(int i=0;i<n;i++)
#define lson (step<<1)
#define rson (lson+1)
#define esp 1e-6
#define oo 0x3fffffff
using namespace std;
typedef long long ll;
int n;
const int mod=998244353;
const int maxn=50000+10;
int bit[31];
ll ans;
struct trie
{
    int next[30*maxn][2];
    int tot[maxn*30];
    int cnt,root;
    int newNode()
    {
        tot[cnt]=0;
        next[cnt][0]=next[cnt][1]=-1;
        cnt++;
        return cnt-1;
    }
    void init()
    {
        cnt=0;
        root=newNode();
    }
    void Insert(int val)
    {
        int temp=root;
        int id;
        for(int i=0;i<30;i++)
        {
            if(val&bit[i])
                id=1;
            else
                id=0;
            if(next[temp][id^1]!=-1)
                ans=(ans+((ll)bit[i]*tot[next[temp][id^1]])%mod)%mod;
            if(next[temp][id]==-1)
                next[temp][id]=newNode();
            temp=next[temp][id];
            tot[temp]++;
        }
    }
}tree;
int main()
{
    int T_T;
    scanf("%d",&T_T);
    bit[0]=1;
    for(int i=1;i<=30;i++)
    {
        bit[i]=bit[i-1]<<1;
    }
    for(int kase=1;kase<=T_T;kase++)
    {
        scanf("%d",&n);
        int val;
        ans=0;
        tree.init();
        for(int i=1;i<=n;i++)
        {
            sc(val);
            tree.Insert(val);
        }
        ans=(ans<<1)%mod;
        printf("Case #%d: %I64d\n",kase,ans);
    }
    return 0;
}
