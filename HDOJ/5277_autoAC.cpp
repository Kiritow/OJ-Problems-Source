#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 1005
#define mod 10007
#define eps 1e-9
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
    int x,y;
};
node a[maxn];
int g[maxn][maxn];
vector<int> G[maxn];
int one,two,three,four;
int n,m;
void init()
{
    one=two=three=four=0;
    memset(a,0,sizeof(a));
    memset(g,0,sizeof(g));
    for(int i=0;i<n;i++)
        G[i].clear();
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=0;i<n;i++)
            a[i].x=read(),a[i].y=read();
        for(int i=1;i<=m;i++)
        {
            int x=read(),y=read();
            x--,y--;
            g[x][y]=g[y][x]=1;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                for(int k=0;k<G[i].size();k++)
                {
                    if(G[i][j]!=G[i][k]&&g[G[i][j]][G[i][k]])
                    {
                        three++;
                        for(int t=0;t<G[i].size();t++)
                        {
                            if(G[i][j]!=G[i][k]&&G[i][j]!=G[i][t]&&G[i][k]!=G[i][t]&&g[G[i][j]][G[i][k]]&&g[G[i][j]][G[i][t]]&&g[G[i][k]][G[i][t]])
                            {
                                four++;
                            }
                        }
                    }
                }
            }
        }
        if(four)
            cout<<"4 "<<four/24<<endl;
        else if(three)
            cout<<"3 "<<three/6<<endl;
        else if(m)
            cout<<"2 "<<m<<endl;
        else
            cout<<"1 "<<n<<endl;
    }
}
