#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<iostream>
#include<queue>
#include <map>
using namespace std;
typedef long long ll;
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb(i) push_back(i)
#define exp 0.000000001
#define N 101
double a[N][N];
int n,m,tot;
char s[20];
bool vis[50];
vector<int>vec;
struct node
{
    bool sign;
    int len,fal;
    int next[26];
};
node ac[10000];
void init()
{
    ac[0].sign=false;tot=0;
    ac[0].len=0; ac[0].fal=0;
    memset(ac[0].next,-1,sizeof(ac[0].next));
    memset(a,0,sizeof(a));
    memset(vis,false,sizeof(vis));
    vec.clear();
}
void tree()
{
    int len=strlen(s);
    int u=0;
    rep(i,len)
    {
        int x=s[i]-'A';
        if(ac[u].next[x]==-1)
        {
 ++tot; ac[tot].sign=false; 
            memset(ac[tot].next,-1,sizeof(ac[tot].next));
            ac[u].next[x]=tot;
        }
        u=ac[u].next[x];
        if(i==len-1) ac[u].sign=true;
    }
}
int fail(int u,int k)
{
    if(ac[u].next[k]!=-1) return ac[u].next[k];
    if(u==0) return 0;
    return fail(ac[u].fal,k);
}
void bulid()
{
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        rep(i,26)
            if(ac[x].next[i]!=-1)
            {
                q.push(ac[x].next[i]);
                if(x==0) ac[ac[x].next[i]].fal=0;
                else ac[ac[x].next[i]].fal=fail(ac[x].fal,i);
            }
    }
    int len=0;
    q.push(0);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        if(ac[ac[x].fal].sign==true)
            ac[x].sign=true;
        if(ac[x].sign==false)
            ac[x].len=len++;
        rep(i,26)
            if(ac[x].next[i]!=-1)
                q.push(ac[x].next[i]);
    }
}
void work()
{ 
 queue<int>q; q.push(0);
     int len=vec.size();
     int Max=0;
     while(!q.empty())
     {
         int x=q.front(); q.pop();
         int l=ac[x].len;
         Max=max(Max,l);
         a[l][l]-=n;
         a[l][0]+=(n-len);
         rep(j,len)
         {
             int u=x; int y=vec[j]; 
             int sign=0;
             while(true)
             {
                 if(ac[u].next[y]!=-1)
                 {
                     if(ac[ac[u].next[y]].sign==false)
 a[l][ac[ac[u].next[y]].len]+=1;
                         sign=1;
                     break;
                 }
                 if(ac[u].next[y]!=-1) sign=1;
                 if(u==0) break;
                 u=ac[u].fal;
             }
             if(sign==0)
                 a[l][0]++;
         }
         rep(i,26) 
             if(ac[x].next[i]!=-1 && ac[ac[x].next[i]].sign==false)
                 q.push(ac[x].next[i]);
     }
     repf(i,0,Max) a[i][Max+1]=n;
     n=Max+1,m=Max+2;
}
void guess()
{
    rep(i,n)
    {
        int k=-1; 
        repf(j,i,n-1)
            if(a[j][i]!=0){
                k=j; break;
            }
        if(k==-1) continue;
        if(k!=i)
            rep(j,m) swap(a[i][j],a[k][j]);
        rep(j,n)
        {
            if(j!=i)
            {
                double x=a[i][i],y=a[j][i];
                rep(k,m)
                    a[j][k]=a[j][k]-a[i][k]*y/x;
            }
        }
    }
    if(fabs(0-a[0][0])<exp) printf("%0.00\n");
    else printf("%0.2lf\n",-a[0][m-1]*1.0/a[0][0]);
}
void solve()
{
    init();
    rep(i,m)
    {
        scanf("%s",s); tree();
        int len=strlen(s);
        rep(j,len) 
            if(vis[s[j]-'A']==false)
            {
                vec.pb(s[j]-'A'); vis[s[j]-'A']=true;
            }
    }
    bulid();
    work();
    guess();
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&m);
 solve();
    }
}
