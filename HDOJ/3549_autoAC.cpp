#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 22
#define inf 1<<28
int map[MAXN][MAXN];
int pre[MAXN];
int level[MAXN];
int gap[MAXN];
int SAP(int vs,int vt){
    memset(pre,-1,sizeof(pre));
    memset(level,0,sizeof(level));
    memset(gap,0,sizeof(gap));
    int v,u=pre[vs]=vs,maxflow=0,aug=inf;
    gap[0]=vt;
    while(level[vs]<vt){
        for(v=1;v<=vt;v++){
            if(map[u][v]>0&&level[u]==level[v]+1){
                break;
            }
        }
        if(v<=vt){
            pre[v]=u;
            u=v;
            if(v==vt){
                aug=inf;
                for(int i=v;i!=vs;i=pre[i]){
                    if(aug>map[pre[i]][i])aug=map[pre[i]][i];
                }
                maxflow+=aug;
                for(int i=v;i!=vs;i=pre[i]){
                    map[pre[i]][i]-=aug;
                    map[i][pre[i]]+=aug;
                }
                u=vs;
            }
        }else {
            int minlevel=vt;
            for(v=1;v<=vt;v++){
                if(map[u][v]>0&&minlevel>level[v]){
                    minlevel=level[v];
                }
            }
            gap[level[u]]--;
            if(gap[level[u]]==0)break;
            level[u]=minlevel+1;
            gap[level[u]]++;
            u=pre[u];
        }
    }
    return maxflow;
}
int main(){
    int _case,t=1,n,m,u,v,cap;
    scanf("%d",&_case);
    while(_case--){
        memset(map,0,sizeof(map));
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&u,&v,&cap);
            map[u][v]+=cap;
        }
        printf("Case %d: ",t++);
        printf("%d\n",SAP(1,n));
    }
    return 0;
}
