#pragma comment(linker, "/STACK:102400000,102400000")  
#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<cstdio>  
#include<queue>  
#include<stack>  
#include<string>  
#include<map>  
#include<set>  
#include<cmath>  
#include<cassert>  
#include<cstring>  
#include<iomanip>  
using namespace std;  
#ifdef _WIN32  
#define i64 __int64  
#define out64 "%I64d\n"  
#define in64 "%I64d"  
#else  
#define i64 long long  
#define out64 "%lld\n"  
#define in64 "%lld"  
#endif  
#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)  
#define FF(i,a)        for( int i = 0 ; i < (a) ; i ++)  
#define FFD(i,a,b)      for( int i = (a) ; i >= (b) ; i --)  
#define S64(a)          scanf(in64,&a)  
#define SS(a)           scanf("%d",&a)  
#define LL(a)           ((a)<<1)  
#define RR(a)           (((a)<<1)+1)  
#define pb              push_back  
#define pf              push_front  
#define X               first  
#define Y               second  
#define CL(Q)           while(!Q.empty())Q.pop()  
#define MM(name,what)   memset(name,what,sizeof(name))  
#define MC(a,b)         memcpy(a,b,sizeof(b))  
#define MAX(a,b)        ((a)>(b)?(a):(b))  
#define MIN(a,b)        ((a)<(b)?(a):(b))  
#define read            freopen("in.txt","r",stdin)  
#define write           freopen("out.txt","w",stdout)  
const int inf = 0x3f3f3f3f;  
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;  
const double oo = 10e9;  
const double eps = 10e-9;  
const double pi = acos(-1.0);  
const int maxn = 100011;  
vector<int>v[maxn];  
vector<int>g[maxn];  
vector<int>s;  
int n;  
double nn;  
int t[maxn];  
int f[maxn];  
int dfn[maxn];  
int low[maxn];  
int df,nf;  
bool ins[maxn];  
int tot;  
bool hash[maxn];  
int yes[33];  
double go[33][33];  
double back[33][33];  
double dpx[maxn];  
double dpy[maxn];  
bool vis[maxn];  
int cnt[maxn];  
double dp[maxn];  
double dps[maxn];  
vector<double>ans;  
void tarjan(int now)  
{  
    low[now] = dfn[now] = df++;  
    s.push_back(now);  
    ins[now]=true;  
    int to;  
    for(int i=0;i<g[now].size();i++)  
    {  
        to = g[now][i];  
        if(!dfn[to])  
        {  
            t[to]=now;  
            tarjan(to);  
            low[now] = min(low[to],low[now]);  
        }  
        else if(to!=t[now])  
        {  
            low[now]=min(dfn[to],low[now]);  
        }  
    }  
    if(dfn[now] == low[now])  
    {  
        while(s.back() != now)  
        {  
            to = s.back();  
            f[to] = nf;  
            s.pop_back();  
            ins[to]=false;  
        }  
        to = s.back();  
        s.pop_back();  
        ins[to]=false;  
        f[to] = nf++;  
    }  
    return ;  
}  
void dfs(int now)  
{  
    vis[now] = true;  
    int to;  
    for(int i=0;i<g[now].size();i++)  
    {  
        to = g[now][i];  
        if(!ins[to] && !vis[to])  
        {  
            cnt[now]++;  
        }  
    }  
    for(int i=0;i<g[now].size();i++)  
    {  
        to = g[now][i];  
        if(!ins[to] && !vis[to])  
        {  
            dfs(to);  
            dps[now]+=dpx[to];  
            if(ins[now])  
            {  
                dpx[now]+=2.0*dpx[to]/double(cnt[now]+1.0);  
            }  
            else  
            {  
                dpx[now]+=dpx[to]/double(cnt[now]);  
            }  
        }  
    }  
    if(ins[now])  
    {  
        double temp = 2.0/double(cnt[now]+2.0);  
        dpx[now] += nn*temp;  
    }  
    else  
    {  
        double temp = 1.0/double(cnt[now]+1.0);  
        dpx[now] += nn*temp;  
    }  
    return ;  
}  
void df2(int now)  
{  
    vis[now]=true;  
    int to;  
    for(int i=0;i<g[now].size();i++)  
    {  
        to = g[now][i];  
        if(!ins[to] && !vis[to])  
        {  
            dpy[to] = dpy[now]/double(cnt[now]);  
            dpy[to] += nn*double(cnt[to])/double(cnt[to]+1.0);  
            if(ins[now])  
            {  
                dpy[to]+=(dps[now]-dpx[to])/(cnt[now]+1.0);  
            }  
            else  
            {  
                dpy[to]+=(dps[now]-dpx[to])/double(cnt[now]);  
            }  
            df2(to);  
        }  
    }  
    if(!cnt[now])  
    {  
        dp[now] = dpy[now];  
    }  
    return ;  
}  
void find()  
{  
    int now=s[0];  
    int to;  
    vis[now] = true;  
    bool ok;  
    while(true)  
    {  
        ok = false;  
        for(int i=0;i<g[now].size();i++)  
        {  
            to = g[now][i];  
            if(ins[to] && !vis[to])  
            {  
                vis[to]=true;  
                s.pb(to);  
                now = to;  
                ok = true;  
                break;  
            }  
        }  
        if(!ok) break;  
    }  
    return ;  
}  
void start()  
{  
    for(int i=0;i<=n;i++)  
    {  
        f[i]=0;  
        t[i]=0;  
        dfn[i]=0;  
        low[i]=0;  
        ins[i]=false;  
    }  
    s.clear();  
    df=nf=1;  
    tarjan(1);  
    nf--;  
    for(int i=1;i<=n;i++)  
    {  
        v[f[i]].pb(i);  
    }  
    int tv;  
    for(int i=1;i<=nf;i++)  
    {  
        if(v[i].size()>1)  
        {  
            tv=i;  
            break;  
        }  
    }  
    s.clear();  
    tot = v[tv].size();  
    for(int i=0;i<=n;i++)  
    {  
        ins[i]=false;  
        vis[i]=false;  
    }  
    for(int i=0;i<v[tv].size();i++)  
    {  
        ins[v[tv][i]] = true;  
    }  
    s.pb(v[tv][0]);  
    find();  
    int now,to;  
    MM(yes,0);  
    for(int i=0;i<s.size();i++)  
    {  
        now = s[i];  
        for(int j=0;j<g[now].size();j++)  
        {  
            to = g[now][j];  
            if(!ins[to])  
            {  
                yes[i]++;  
            }  
        }  
    }  
    MM(go,0);  
    MM(back,0);  
    int ss = s.size();  
    for(int i=0;i<ss;i++)  
    {  
        if(yes[i])  
        {  
            go[i][(i+1)%ss]=1.0/(yes[i]+1.0);  
            back[i][(i-1+ss)%ss]=1.0/(yes[i]+1.0);  
        }  
        else  
        {  
            go[i][(i+1)%ss]=1.0;  
            back[i][(i-1+ss)%ss]=1.0;  
        }  
    }  
    for(int u=2;u<ss;u++)  
    {  
        for(int i=0;i<ss;i++)  
        {  
            go[i][(i+u)%ss]=go[i][(i+u-1)%ss]*go[(i+u-1)%ss][(i+u)%ss];  
            back[i][(i-u+ss)%ss]=back[i][(i-(u-1)+ss)%ss]*back[(i-(u-1)+ss)%ss][(i-u+ss)%ss];  
        }  
    }  
    for(int i=0;i<=n;i++)  
    {  
        vis[i]=false;  
        dpx[i]=0;  
        dpy[i]=0;  
        dp[i]=0;  
        dps[i]=0;  
        cnt[i]=0;  
    }  
    double temp;  
    for(int i=0;i<ss;i++)  
    {  
        if(yes[i])  
        {  
            dfs(s[i]);  
        }  
    }  
    for(int i=0;i<ss;i++)  
    {  
        if(!yes[i]) continue;  
        for(int j=0;j<ss;j++)  
        {  
            if(j==i)  
            {  
                temp = double(yes[i])/(yes[i]+2.0);  
                dpy[s[j]]+=temp*nn;  
                continue;  
            }  
            if(!yes[j]) continue;  
            temp = dpx[s[i]]*go[i][j];  
            temp *= yes[i]+1.0;  
            temp /= 2.0;  
            if((i-j+ss)%ss==1)  
            {  
                dpy[s[j]]+=temp;  
            }  
            else  
            {  
                temp/=yes[j]+1.0;  
                temp*=yes[j];  
                dpy[s[j]]+=temp;  
            }  
            temp = dpx[s[i]]*back[i][j];  
            temp *= yes[i]+1.0;  
            temp /= 2.0;  
            if((i-j+ss)%ss==ss-1)  
            {  
                dpy[s[j]]+=temp;  
            }  
            else  
            {  
                temp/=yes[j]+1.0;  
                temp*=yes[j];  
                dpy[s[j]]+=temp;  
            }  
        }  
    }  
    for(int i=0;i<ss;i++)  
    {  
        if(yes[i]) continue;  
        for(int j=0;j<ss;j++)  
        {  
            if(yes[j])  
            {  
                temp = nn*go[i][j]*0.5;  
                if((i-j+ss)%ss==1)  
                {  
                    dpy[s[j]]+=temp;  
                }  
                else  
                {  
                    temp/=yes[j]+1.0;  
                    temp*=yes[j];  
                    dpy[s[j]]+=temp;  
                }  
                temp = nn*back[i][j]*0.5;  
                if((i-j+ss)%ss==ss-1)  
                {  
                    dpy[s[j]]+=temp;  
                }  
                else  
                {  
                    temp/=yes[j]+1.0;  
                    temp*=yes[j];  
                    dpy[s[j]]+=temp;  
                }  
            }  
        }  
    }    
    for(int i=0;i<=n;i++)  
    {  
        vis[i]=0;  
    }  
    for(int i=0;i<ss;i++)  
    {  
        if(yes[i])  
        {  
            df2(s[i]);  
        }  
    }  
    for(int i=0;i<ss;i++) if(yes[i])  
    {  
        if(!yes[(i+1)%ss])  
        {  
            temp = dpx[s[i]]*back[i][(i+1)%ss];  
            temp *= yes[i]+1.0;  
            temp /= 2.0;  
            dp[s[(i+1)%ss]] += temp;  
        }  
        if(!yes[(i-1+ss)%ss])  
        {  
            temp = dpx[s[i]]*go[i][(i-1+ss)%ss];  
            temp *= yes[i]+1.0;  
            temp /= 2.0;  
            dp[s[(i-1+ss)%ss]] += temp;  
        }  
    }  
    for(int i=0;i<ss;i++) if(!yes[i])  
    {  
        if(!yes[(i+1)%ss])  
        {  
            dp[s[(i+1)%ss]] += nn*back[i][(i+1)%ss]*0.5;  
        }  
        if(!yes[(i-1+ss)%ss])  
        {  
            dp[s[(i-1+ss)%ss]] += nn*go[i][(i-1+ss)%ss]*0.5;  
        }  
    }  
    ans.clear();  
    for(int i=1;i<=n;i++)  
    {  
        if(dp[i]>eps)  
        {  
            ans.pb(dp[i]);  
        }  
    }  
    for(int i=1;i<=5;i++)  
    {  
        ans.pb(0.0);  
    }  
    sort(ans.begin(),ans.end());  
    return ;  
}  
int main()  
{  
    while(cin>>n)  
    {  
        if(!n) return 0;  
        nn = n;  
        nn = 1.0/nn;  
        for(int i=0;i<=n;i++)  
        {  
            v[i].clear();  
            g[i].clear();  
        }  
        int now,to;  
        for(int i=1;i<=n;i++)  
        {  
            SS(now);  
            SS(to);  
            g[now].pb(to);  
            g[to].pb(now);  
        }  
        start();  
        double re=0.0;  
        int ix = ans.size()-1;  
        for(int i=1;i<=5;i++)  
        {  
            re+=ans[ix--];  
        }  
        printf("%.5lf\n",re);  
    }  
    return 0;  
}
