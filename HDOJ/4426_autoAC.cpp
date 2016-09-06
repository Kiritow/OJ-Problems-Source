#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
const int maxn=4e5+9,maxm=11371111;;
const long long mod=777777777;
char a[maxn];
int dp[maxn];
unsigned long long sum[maxn],po[maxn];
int n,m;
int score[maxn];
int has[maxm],lon;
struct D
{
    int next,pos,size;
    long long sum;
    unsigned long long _key;
    long long key;
    bool operator <(const D & xx) const
    {
        return key<xx.key;
    }
}data[maxn];
void getpal()
{
    int top=0;
    dp[0]=0,a[0]=-1,a[n+1]=-2;
    for(int i=1,t,s;i<=n;i++)
    {
        if(top+dp[top]<i)
        {
            top=i;
            t=i-1,s=i+1;
            while(a[t]==a[s]) t--,s++;
            dp[i]=s-i-1;
        }
        else
        {
            if(dp[top-(i-top)]+i<top+dp[top])
            dp[i]=dp[top-(i-top)];
            else
            {
                s=top+dp[top]+1;
                t=i-(s-i);
                while(a[t]==a[s]) t--,s++;
                dp[i]=s-i-1;
                top=i;
            }
        }
    }
}
bool insert(int pos,int size,long long ff)
{
    if(a[pos]=='#') pos++;
    unsigned long long _key=(sum[pos+(size-1)*2]-sum[pos-2]);
    _key*=po[n-pos];
    int key=_key%maxm;
    for(int k=has[key];k!=-1;k=data[k].next)
    {
        if(data[k]._key==_key)
        {
            data[k].sum+=ff;
            return false;
        }
    }
    data[++lon].sum=ff;
    data[lon].pos=pos;
    data[lon].size=size;
    data[lon]._key=_key;
    data[lon].next=has[key];
    has[key]=lon;
    return true;
}
void getkey()
{
    sum[0]=0;
    for(int i=2;i<=n;i+=2)
    {
        sum[i]=sum[i-2];
        sum[i]+=(a[i]-'a'+1)*po[i];
    }
}
struct R
{
    int t,key;
    bool operator <(const R & xx) const
    {
        return key<xx.key;
    }
};
void gethash()
{
    memset(has,-1,sizeof(has));
    lon=0;
    getkey();
    for(int i=1;i<=n;i++)
    if(dp[i]>0)
    insert(i,dp[i]+1>>1,1);
    priority_queue <R> q;
    while(!q.empty()) q.pop();
    for(int i=1;i<=lon;i++)
    {
        R now;
        now.key=data[i].size;
        now.t=i;
        q.push(now);
    }
    while(!q.empty())
    {
        int pos=data[q.top().t].pos;
        int size=data[q.top().t].size;
        long long ff=data[q.top().t].sum;
        size--;
        q.pop();
        if(size&&insert(pos,size,ff))
        {
            R now;
            now.t=lon;
            now.key=size;
            q.push(now);
        }
    }
}
long long nn[maxn],pp[maxn];
void getkey(int t)
{
    data[t].key=nn[data[t].pos];
    int ff=data[t].pos+data[t].size*2;
    if(ff>n) return ;
    long long tmp=(nn[ff]*pp[data[t].size])%mod;
    data[t].key=((data[t].key+mod-tmp))%mod;
}
void getnow()
{
    pp[0]=1;
    for(int i=1;i<=n+1;i++)
    {
        pp[i]=(pp[i-1]*26)%mod;
    }
    nn[n+1]=0;
    for(int i=n-1;i>=1;i-=2)
    {
        nn[i]=(nn[i+2]*26)%mod;
        nn[i]=(nn[i]+score[(a[i]-'a'+1)])%mod;
    }
}
void solve(long long num)
{
    getnow();
    for(int i=1;i<=lon;i++)
    getkey(i);
    sort(data+1,data+1+lon);
    long long now=0;
    for(int i=1;i<=lon;i++)
    {
        now+=data[i].sum;
        if(now>=num)
        {
            printf("%I64d\n",data[i].key);
            break;
        }
    }
    if(now<num)
    printf("0\n");
}
int main()
{
    po[0]=1;
    for(int i=1;i<maxn;i++)
    po[i]=po[i-1]*27;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",a+1);
        for(int i=n;i>=1;i--)
        {
            a[i*2]=a[i];
            a[i*2-1]='#';
        }
        n<<=1;
        a[++n]='#';
        getpal();
        gethash();
        for(int i=1;i<=m;i++)
        {
            long long tmp;
            scanf("%I64d",&tmp);
            for(int j=1;j<=26;j++)
            scanf("%d",&score[j]);
            solve(tmp);
        }
        cout<<endl;
    }
    return 0;
}
