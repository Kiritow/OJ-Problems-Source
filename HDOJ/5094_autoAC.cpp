#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n, m, p;
int door[51][51][4], map[51][51];
bool vis[51][51][1<<10];
int xl[4]={-1,1,0,0};
int yl[4]={0,0,-1,1};
int getd(int a, int b, int c, int d){
    if(a==c){
        if(b<d)    return 3;
        return 2;
    }
    else{
        if(a<c)    return 1;
        return 0;
    }
}
struct Node{
    int x, y, st, u;
    Node(){}
    Node(int x, int y, int st, int u):x(x),y(y),st(st),u(u){}
};
int solve(){
    if(n==1 && m==1)    return 0;
    queue<Node> Q;
    Q.push(Node(1,1,map[1][1],0));
    while(!Q.empty()){
        Node nd = Q.front(); Q.pop();
        if(vis[nd.x][nd.y][nd.st])    continue;
        vis[nd.x][nd.y][nd.st] = 1;
        for(int i=0; i<4; i++){
            int a = nd.x+xl[i];
            int b = nd.y+yl[i];
            if(a<1 || a>n || b<1 || b>m)    continue;
            if(!door[nd.x][nd.y][i])    continue;
            int st = nd.st;
            if(door[nd.x][nd.y][i]>0){
                int d = 1<<(door[nd.x][nd.y][i]-1);
                if(!(st&d))    continue;
            }
            if(a==n && b==m)    return nd.u+1;
            st |= map[a][b];
            if(!vis[a][b][st])    Q.push(Node(a,b,st,nd.u+1));
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d %d %d", &n, &m, &p)){
        memset(door, -1, sizeof(door));
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        int k;
        scanf("%d", &k);
        int a, b, c, d, e;
        while(k--){
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            door[a][b][getd(a,b,c,d)] = e;
            door[c][d][getd(c,d,a,b)] = e;
        }
        scanf("%d", &k);
        while(k--){
            scanf("%d %d %d", &a, &b, &c);
            map[a][b] |= (1<<(c-1));
        }
        printf("%d\n", solve());
    }
    return 0;
}
