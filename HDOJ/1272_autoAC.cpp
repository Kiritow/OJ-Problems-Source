#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<list>
#include<deque>
#include<map>
#include <stdio.h>
#include <queue>
#include <stack>
#define maxn 100010
#define ull unsigned long long
#define ll long long
#define reP(i,n) for(i=1;i<=n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define cle(a) memset(a,0,sizeof(a))
#define mod 90001
#define PI 3.141592657
#define INF 1<<30
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int fa[maxn];
int ans,cnt;
int mark[maxn];
void init(){
    for(int i=0;i<=maxn;i++)
        fa[i]=-1;
        ans=0;cnt=0;
        cle(mark);
}
int findfa(int x){
    while(fa[x]>=0)
        x=fa[x];
    return x;
}
void Union(int x,int y){
    int fa_x=findfa(x);
    int fa_y=findfa(y);
    if(fa_x!=fa_y)
        fa[fa_x]=fa_y;
    else{
             ans++;
    }
    mark[x]=mark[y]=1;
}
int x,y;
int main()
{
    init();
    while(cin>>x>>y){
        if(x==-1&&y==-1)break;
        if(x==0&&y==0){
            for(int i=1;i<=maxn;i++){
                if((mark[i])&&(fa[i]==-1))
                    cnt++;
            }
            if(ans>0||cnt>1)printf("No\n");
            else printf("Yes\n");
            init();
            continue;
        }
        Union(x,y);
    }
    return 0;
}
