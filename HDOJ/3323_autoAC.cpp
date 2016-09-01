#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#define MAX 22222
using namespace std;
vector<int>vt[MAX];
int vis[MAX];
int a;
int d[MAX];
int BFS(int n){
        queue<int> q;
        q.push(n);
        int cnt=0;
        while(!q.empty()){
            int now=q.front();
            for(int i=0;i<vt[now].size();i++){
                int to=vt[now][i];
                if(vis[to]==0){
                    vis[to]=1;
                    cnt++;
                    q.push(to);
                }
            }
            q.pop();
        }
        return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));  
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        scanf("%d",&a);
                for(int i=0;i<n;i++)vt[i].clear();
        for(int i=0;i<c;i++){
            scanf("%d",&d[i]);
        }
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            vt[u].push_back(v);
                        vt[v].push_back(u);
        }
        vis[a]=1;
        for(int i=0;i<c;i++){
            vis[d[i]]=1;
                BFS(d[i]);
        }
        printf("%d\n",BFS(a));
    }
}
