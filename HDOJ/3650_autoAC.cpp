#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define N 86444
using namespace std;
int s[N],e[N],n;
inline void read()
{
    memset(s,0,sizeof s);
    memset(e,0,sizeof e);
    for(int i=1,a,b;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b); 
        s[a]++; e[b]++;
    }
}
inline void go()
{
    int ans=0,res=0;
    for(int i=0;i<=86400;i++)
    {
        res+=s[i];
        ans=max(ans,res);
        res-=e[i];
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&n),n) read(),go();
    return 0;
}
