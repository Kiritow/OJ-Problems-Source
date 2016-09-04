#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n;
char maze[20];
bool vis[1<<16];
int bfs(){
    queue<pair<int,int> > que;
    que.push(make_pair(0,0));
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    while(!que.empty()){
        int u=que.front().first;
        int d=que.front().second;
        que.pop();
        for(int i=0;i<(n<<1);i++){
            if(u&(1<<i)) continue;
            int v=0;
            for(int j=i;j<(i/n+1)*n;j++){
                if(u&(1<<j)) break;
                if(maze[j]==maze[i]) v|=(1<<j);
            }
            for(int j=i-1;j>=(i/n)*n;j--){
                if(u&(1<<j)) break;
                if(maze[j]==maze[i]) v|=(1<<j);
            }
            if((u|v)==(1<<(n<<1))-1) return d+1;
            for(int j=v;j;j=v&(j-1)){
                if(vis[j|u]) continue;
                vis[j|u]=true;
                que.push(make_pair(j|u,d+1));
            }
            if(i/n) continue;
            if(u&(1<<(i+n))) continue;
            v=0;
            for(int j=i;j<n;j++){
                if((u&(1<<j))|(u&(1<<(j+n)))) break;
                if(maze[j]==maze[i]) v|=1<<j;
                if(maze[j+n]==maze[i]) v|=1<<(j+n);
            }
            for(int j=i-1;j>=0;j--){
                if((u&(1<<j))|(u&(1<<(j+n)))) break;
                if(maze[j]==maze[i]) v|=1<<j;
                if(maze[j+n]==maze[i]) v|=1<<(j+n);
            }
            if((u|v)==(1<<(n<<1))-1) return d+1;
            for(int j=v;j;j=v&(j-1)){
                if(vis[j|u]) continue;
                vis[j|u]=true;
                que.push(make_pair(j|u,d+1));
            }
        }
    }
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",maze);
        scanf("%s",maze+n);
        int ans=bfs();
        printf("Case #%d: %d\n",++cas,ans);
    }
}
