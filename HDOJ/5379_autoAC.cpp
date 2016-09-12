#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define Max 100010
const int  MOD = 1e9+7;
vector <int > q[Max];
int vis[Max];
long long res=1;
int flag=1;
int n;
void dfs(int a)
{
    int k=q[a].size();
    int cnt=0;
    vis[a]=1;
    for(int i=0;i<k;i++)
    {
        if(vis[q[a][i]]) continue;
        if(q[q[a][i]].size()==1&&vis[q[a][i]]==0) cnt++;
        else dfs(q[a][i]);
    }
    if(a!=1)k--;
    if(k-cnt>2){flag=0;return ;}
    if(cnt!=k)
    {
        res*=2;
        res%=MOD;
    }
    while(cnt>0)
    {
        res*=cnt;res%=MOD;cnt--;
    }
    //cout<<a<<" "<<res<<endl;
    //cout<<res<<endl;
}
int main()
{
    int T;
    cin>>T;
    int _case=0;
    while(T--)
    {
        cin>>n;
        flag=1;
        for(int i=1;i<=n;i++) q[i].clear();
        memset(vis,0,sizeof(vis));
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            q[b].push_back(a);
            q[a].push_back(b);
        }
        res=2;
        if(n!=1)
        dfs(1);
        else res=1;
        if(!flag) res=0;
        cout<<"Case #"<<++_case<<": "<<res%MOD<<endl;
    }
    return 0;
}
