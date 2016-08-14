#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 33
#define inf 1<<30
int map[MAXN][MAXN];
int n,MIN,k;
int num[MAXN];
bool mark[MAXN];
void dfs(int start,int count,int dist){
    if(count==k){
        MIN=min(dist,MIN);
        return ;
    }
    for(int i=1;i<=k;i++){
        if(!mark[i]){
            mark[i]=true;
            dfs(num[i],count+1,dist+map[start][num[i]]);
            mark[i]=false;
        }
    }
}
int main(){
    int _case;
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
        }
        k=0,MIN=inf;
        scanf("%d",&_case);
        memset(mark,false,sizeof(mark));
        while(_case--){
            int x;
            scanf("%d",&x);
            if(mark[x])continue;
            mark[x]=true;
            num[++k]=x;
        }
        memset(mark,false,sizeof(mark));
        dfs(0,0,0);
        printf("%d\n",MIN);
    }
    return 0;
}
