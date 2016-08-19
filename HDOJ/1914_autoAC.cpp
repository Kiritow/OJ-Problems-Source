#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <queue>
#include <map>
using namespace std;
const int maxn=50;
int g[maxn][maxn], b[maxn][maxn], visit[maxn][maxn];
int bf[maxn], gf[maxn];
char ch[maxn], str[maxn];
map<char,int>G,M;
map<int,char>GG,MM;
queue<int>q;
int n, T;
void init()
{
    G.clear(), M.clear(), GG.clear(), MM.clear();
    memset(visit,0,sizeof(visit));
    memset(bf,0,sizeof(bf));
    while(!q.empty()) q.pop();
}
void find(int x)
{
    for(int i=n; i>=1; i--)
    {
        if(visit[x][i]) continue;
        visit[x][i]=1;
        int y=b[x][i];
        if(!bf[y])
        {
            bf[y]=x;
            gf[x]=y;
            return ;
        }
        else
        {
            if(g[y][x]>g[y][ bf[y] ])
            {
                q.push(bf[y]);
                bf[y]=x;
                gf[x]=y;
                return ;
            }
        }
    }
}
void Solve()
{
    for(int i=1; i<=n; i++) q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        find(x);
    }
    sort(ch+1,ch+n+1);
    for(int i=1; i<=n; i++)
        printf("%c %c\n",ch[i],MM[ gf[ G[ch[i]] ] ]);
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        init();
        for(int i=1; i<=n; i++) cin >> ch[i], G[ ch[i] ]=i, GG[i]=ch[i];
        for(int i=1; i<=n; i++) cin >> ch[n+i],  M[ ch[n+i] ]=i, MM[i]=ch[n+i];
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str+1);
            int x=G[ str[1] ];
            for(int j=3; j<=n+2; j++)
            {
                int y=M[ str[j] ];
                b[x][n-j+3]=y;
            }
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str+1);
            int x=M[ str[1] ];
            for(int j=3; j<=n+2; j++)
            {
                int y=G[ str[j] ];
                g[x][y]=n-j+3;
            }
        }
        Solve();
        if(T)puts("");
    }
}
