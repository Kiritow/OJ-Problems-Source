#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
#define inf 100000000
char s[35],ps[35];
map<string,int> mp;
const int limit[5]={0,1,4,4,2};
int v[25],g[25][25],id[25],cnt[5],t[12],ans;
int gao(char x[])
{
    if (x[0]=='g') return 1;
    if (x[0]=='d') return 2;
    if (x[0]=='m') return 3;
    return 4;
}
void init()
{
    int m,x;
    mp.clear();
    memset(g,0,sizeof(g));
    for (int i=1;i<=23;++i)
    {
        mp[s]=i;
        id[i]=gao(ps);
        if (i<23) scanf("%s%d%s",s,&v[i+1],ps);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%s%s%d",s,ps,&x);
        g[mp[s]][mp[ps]]=x;
        g[mp[ps]][mp[s]]=x;
    }
}
void updata()
{
    int temp=0;
    for (int i=1;i<=11;++i)
        temp+=v[t[i]];
    for (int i=1;i<=11;++i)
        for (int j=i+1;j<=11;++j)
            temp+=g[t[i]][t[j]];
    if (temp>ans) ans=temp;
}
void dfs(int x,int y)
{
    if (y==11)
    {
        updata();
        return;
    }
    if (x>23) return;
    for (int i=0;i<=1;++i)
    {
        cnt[id[x]]+=i;
        if (cnt[id[x]]<=limit[id[x]])
        {   if (i) t[y+1]=x;
            dfs(x+1,y+i);
        }
        cnt[id[x]]-=i;
    }
}
void solve()
{
    memset(cnt,0,sizeof(cnt));
    ans=-inf;
    dfs(1,0);
    if (ans==-inf) printf("impossible\n");
    else printf("%d\n",ans);
}
int main()
{
    while (scanf("%s%d%s",s,&v[1],ps)!=EOF)
    {
        init();
        solve();
    }
    return 0;
}
