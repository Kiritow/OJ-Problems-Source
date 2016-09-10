#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Point{
    int x,y;
}point[22];
int dp[(1<<20)+2];
int n;
int cmp(const Point &p,const Point &q)
{
    if(p.y==q.y){
        return p.x<q.x;
    }
    return p.y<q.y;
}
bool Judge(int i,int j,int k,int l)
{
    if(point[i].x==point[j].x&&point[i].y==point[j].y)return false;
    if(point[i].y!=point[j].y||point[i].x!=point[k].x||point[j].x!=point[l].x||point[k].y!=point[l].y)
        return false;
    if(abs(point[i].x-point[j].x)!=abs(point[i].y-point[k].y))
        return false;
    return true;
}
vector<int>g[22];
int main()
{
    while(~scanf("%d",&n)){
        if(n==-1)break;
        for(int i=0;i<n;i++)scanf("%d%d",&point[i].x,&point[i].y);
        sort(point,point+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if(Judge(i,j,k,l)){
                            int state=0;
                            state|=(1<<i);
                            state|=(1<<j);
                            state|=(1<<k);
                            state|=(1<<l);
                            g[i].push_back(state);
                        }
                    }
                }
            }
        }
        for(int state=0;state<(1<<n);state++){
            for(int i=0;i<n;i++){
                if(state&(1<<i)){
                    for(int j=0;j<g[i].size();j++){
                        int S=g[i][j];
                        if((S|state)==state)dp[state]=max(dp[state],dp[state^S]+4);
                    }
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
