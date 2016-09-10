#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define mod 100000000
#define inf 0x3f3f3f3f
#define eps 1e-6
#define N 1000010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PII pair<int,int>
using namespace std;
inline LL read()
{
    char ch=getchar();LL x=0,f=1;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=1000010;
const int HASH=1000007;
struct HASHMAP
{
    int head[HASH],next[MAXN],size;
    LL state[MAXN];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    bool check(LL val)
    {
        int h=(val%HASH+HASH)%HASH;
        for(int i=head[h];~i;i=next[i])
            if(state[i]==val)return true;
        return false;
    }
    int insert(LL val)
    {
        int h=(val%HASH+HASH)%HASH;
        for(int i=head[h];~i;i=next[i])
        {
            if(val==state[i])
                return 1;
        }
        state[size]=val;
        next[size]=head[h];
        head[h]=size++;
        return 0;
    }
}H1,H2;
LL a[N];
int main()
{
    int T,n,k,cas=1;
    T=read();
    while(T--)
    {
        n=read();k=read();
        for(int i=0;i<n;i++)a[i]=read();
        LL sum=0;
        H1.init();H2.init();
        H1.insert(0);H2.insert(0);
        int flag=0;
        for(int i=n-1;i>=0&&!flag;i--)
        {
            if(i&1)sum-=a[i];
            else sum+=a[i];
            if(i%2==0)
            {
                if(H1.check(sum-k))flag=1;
            }
            else
            {
                if(H2.check(-sum-k))flag=1;
            }
            H1.insert(sum);
            H2.insert(-sum);
        }
        printf("Case #%d: ",cas++);
        if(flag)puts("Yes.");
        else puts("No.");
    }
}
