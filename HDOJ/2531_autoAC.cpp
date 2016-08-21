#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;
const int inf = 0x7FFFFFFF;
const int maxn = 10000;
struct node{
    int x[21],y[21];
    int time;
}rt,ne;
int n,m,k;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
char f[105][105];
int dis[105][105];
int Is_Ok(node& ne,int u){ ///娉: '&'涓灏
    int q=1;
    for(int i=0;i<k;++i){
        ne.x[i]+=dx[u];
        ne.y[i]+=dy[u];
        if(ne.x[i]<0||ne.y[i]<0||ne.x[i]>=n||ne.y[i]>=m||f[ne.x[i]][ne.y[i]]=='O')
            return 0;
        if(f[ne.x[i]][ne.y[i]]=='Q') q=2;
    }
    return q;
}
int BFS(){
    queue<node>M;
    rt.time=0;
    M.push(rt);
    while(!M.empty()){
        rt=M.front(); M.pop();
        for(int i=0;i<4;++i){
            ne=rt;
            int q=Is_Ok(ne,i);
            if(!q) continue;
            ne.time++;
            if(q==2) return ne.time; 
            if(dis[ne.x[0]][ne.y[0]]>ne.time){
                dis[ne.x[0]][ne.y[0]]=ne.time;
                M.push(ne);
            }
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d%d",&n,&m),n+m){
        k=0;
        for(int i=0;i<n;++i){
            scanf("%s",f[i]);
            for(int j=0;j<m;++j){
                if(f[i][j]=='D')
                    rt.x[k]=i, rt.y[k++]=j;
                dis[i][j]=inf;
            }
        }
        for(int i=0;i<k;++i)
            f[rt.x[i]][rt.y[i]]='.';
        int ans=BFS();
        if(ans==-1) puts("Impossible");
        else printf("%d\n",ans);
    }
    return 0;
}
