#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll mod=998244353;
bool a[1000][1000];
int n,m,au[1000][9],p[1000][1000],ee,fa[900],num[900];
ll two[1000];
struct edge {
    int x,y,next;
}e[8888888];
void addedge(int x,int y,int u,int v) {
    if(x==y) return;
    if(x>y) {x=x^y;y=x^y;x=x^y;}
    e[ee].x=u;e[ee].y=v;e[ee].next=p[x][y];p[x][y]=ee++;
}
void init() {
    int i,j,k,x,y;
    queue<int> qx,qy;ee=0;
    for(i=1;i<=n;i++) {fa[i]=i;num[i]=1;}
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            for(k=1;k<=m;k++)
                addedge(au[i][k],au[j][k],i,j);
    for(i=1;i<=n;i++) {
        a[0][i]=true;qx.push(0);qy.push(i);
    }
    while (!qx.empty()) {
        i=qx.front();j=qy.front();qx.pop();qy.pop();
        k=p[i][j];
        while(k!=-1) {
            x=e[k].x;y=e[k].y;
            if(a[x][y]) {k=e[k].next;continue;}
            else {
                a[x][y]=true;
                qx.push(e[k].x);qy.push(e[k].y);
            }
        }
    }
}
int find_fa(int u) {
    if(u==fa[u]) return u;
    return fa[u]=find_fa(fa[u]);
}
ll cal () {
    int i,j;ll ans=two[n]-1;
    for(i=1;i<n;i++) for(j=i+1;j<=n;j++) {
        if(!a[i][j]&&find_fa(i)!=find_fa(j)) {
            num[find_fa(i)]+=num[find_fa(j)];
            fa[fa[j]]=fa[i];
        }
    }
    for(i=1;i<=n;i++) {
        if(i==fa[i]) {
            ans=(ans+mod-two[num[i]]+1)%mod;
        }
    }
    return ans;
}
int main () 
{
    int i,j;
    two[0]=1;for(i=1;i<=900;i++) two[i]=2*two[i-1]%mod;
    while(~scanf("%d%d",&n,&m)) {
        for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&au[i][j]);
        memset(a,false,sizeof(a));
        for(i=0;i<n;i++) for(j=i+1;j<=n;j++) p[i][j]=-1;
        init();
        printf("%I64d\n",cal());
    }
}
