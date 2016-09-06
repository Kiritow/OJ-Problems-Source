#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 10010;
int m;
int mat[8][8];
int blast[8][8];
const int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct Node{
    int x, y;
    int cnt;
    int dir;
}Q[500000];
void addQue(int x, int y, int cnt, int& rear){
    mat[x][y] = 0;
    for(int i=0; i<4; ++i){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx>=1&&dx<=6&&dy>=1&&dy<=6){
            Q[rear].x = dx;
            Q[rear].y = dy;
            Q[rear].cnt = cnt;
            Q[rear++].dir = i;
        }
    }
}
void bfs(int x, int y){
    int front=0, rear=0;
    addQue(x, y, 0, rear);
    int cur = 0; 
    while(front < rear){
        while(front < rear && Q[front].cnt==cur){ 
            Node &t = Q[front++];
            if(mat[t.x][t.y]){
                ++mat[t.x][t.y];
            } else{
                Node& now = Q[rear];
                now.x = t.x + dir[t.dir][0];
                now.y = t.y + dir[t.dir][1];
                now.cnt = t.cnt + 1;
                now.dir = t.dir;
                if(now.x>=1&&now.x<=6&&now.y>=1&&now.y<=6)
                    ++rear;
            }
        }
        for(int i=1; i<=6; ++i){
            for(int j=1; j<=6; ++j)if(mat[i][j]>4){
                addQue(i,j,cur+1,rear);
            }
        }
        ++cur;
    }
}
int main(){
    int x, y;
    while(~scanf("%d", &mat[1][1])){
        for(int i=1; i<=6; ++i){
            for(int j=(i==1?2:1); j<=6; ++j){
                scanf("%d", &mat[i][j]);
            }
        }
        scanf("%d", &m);
        for(int i=0; i<m; ++i){
            scanf("%d%d", &x, &y);
            if(++mat[x][y]>4){
                bfs(x, y);
            }
        }
        for(int i=1; i<=6; ++i){
            for(int j=1; j<=6; ++j)
                if(j!=1) printf(" %d", mat[i][j]);
                else printf("%d", mat[i][j]);
            putchar('\n');
        }
        putchar('\n'); 
    }
    return 0;
}
