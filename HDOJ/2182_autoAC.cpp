#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int N=300;
int n,a,b,k,t,ans;
int ins[N],vis[N][N];
struct node{
    int x,val,t;
    node() {}
    node(int a, int b, int c): x(a), val(b), t(c) {}
};
void bfs()
{
    queue<node> v;
    node tmp;
    int i,px,pv,pt;
    v.push( node(0,ins[0],0) );
    while(!v.empty())
    {
        tmp=v.front(); v.pop();
        if(tmp.x>=n || tmp.t==k){
            ans=max(tmp.val,ans);
            continue;
        }
        for(i=a;i<=b;i++)
        {
            px=tmp.x+i; pv=tmp.val+ins[px]; pt=tmp.t+1;
            if(pv>vis[px][pt]){
                v.push( node(px,pv,pt) );
                vis[px][pt]=pv;
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(ins,0,sizeof(ins));
        memset(vis,0,sizeof(vis));
        scanf("%d %d %d %d",&n, &a, &b, &k);
        for(int i=0;i<n;i++)
            scanf("%d",&ins[i]);
        ans=0;
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}
