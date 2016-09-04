#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=100002;
const int oo=1000000000;
const int mod=9901;
int c[maxn],n,d,b[maxn],a[maxn];
void add(int x,int val)
{
    while(x<=maxn)
    {
        c[x]+=val;
        c[x]%=mod;
        x+=(x&-x);
    }
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        s%=mod;
        x-=(x&-x);
    }
    return s;
}
int main()
{
    int i,id,up,down,val,ans;
    while(~scanf("%d%d",&n,&d))
    {
        map<int,int>flag;
        map<int,int>::iterator it;
        flag[0]=0;
        memset(c,0,sizeof(c));
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int cnt=2;
        flag[b[0]]=1;
        for(i=1; i<n; i++)
            if(b[i]!=b[i-1])
                flag[b[i]]=cnt++;
        flag[oo]=cnt++;
        for(i=0; i<n; i++)
        {
            it=flag.lower_bound(a[i]);
            id=it->second;
            it=flag.upper_bound(a[i]+d);
            up=it->second-1;
            it=flag.lower_bound(a[i]-d);
            down=it->second;
            val=sum(up)-sum(down-1)+1;
            val=(val%mod+mod)%mod;
            add(id,val);
        }
        ans=sum(cnt);
        ans=((ans-n)%mod+mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}
