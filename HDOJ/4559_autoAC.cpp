#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<vector>
#define ll __int64
#define pi acos(-1.0)
#define MAX 5000
using namespace std;
int an[2][MAX],sg[MAX];
bool vis[MAX];
int getsg(int x)
{
    int i;
    if(sg[x]>=0) return sg[x];
    memset(vis,0,sizeof(vis));
    for(i=0;i<=x-i-1;i++)
        vis[getsg(i)^getsg(x-i-1)^1]=1;
    for(i=0;i<=x-i-2;i++)
        vis[getsg(i)^getsg(x-i-2)]=1;
    i=0;
    while(vis[i]) i++;
    return sg[x]=i;
}
int main(){
    int t,m,n,s,c,ans,i,k=0,len;
    memset(sg,-1,sizeof(sg));
    sg[0]=0;
    for(i=1;i<=4747;i++) sg[i]=getsg(i);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        memset(an,0,sizeof(an));
        for(i=0;i<m;i++){
            scanf("%d %d",&s,&c);
            an[s-1][c-1]=1;
        }
        ans=0;len=0;
        for(i=0;i<n;i++){
            if(an[0][i]||an[1][i]){
                ans^=sg[len];
                ans^=an[0][i];
                ans^=an[1][i];
                len=0;
            }
            else len++;
        }
        ans^=sg[len];
        printf("Case %d: %s\n",++k,ans?"Alice":"Bob");
    }
    return 0;
}
