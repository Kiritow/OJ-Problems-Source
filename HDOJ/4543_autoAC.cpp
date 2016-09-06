#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct P{
    int x,y,dis;
};
int N,M,pnum;
int map[80][80],a[80][80];
P queue[100000];
int front,rear;
char s[200];
P point[10000];
void push(P p){
    queue[rear++] = p;
}
P pop(){
    ++front;
    return queue[front - 1];
}
P D(P p,int dir){
    P p2 = p;
    if(dir == 0) --p2.x;
    else if(dir == 1) ++ p2.x;
    else if(dir == 2) -- p2.y;
    else ++p2.y;
    return p2;
}
bool check(P p){
    if(p.x >=0 && p.x < N && p.y >=0 && p.y < M && a[p.x][p.y] == 0)
        return true;
    return false;
}
void BFS()
{
    rear = front = 0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j){
            if(a[i][j] == 1){
                P p;
                p.x = i;
                p.y = j;
                push(p);
            }
        }
    while(rear > front){
        P p = pop();
        for(int dir =0; dir < 4; dir ++){
            P p2;
            p2 = D(p,dir);
            if(check(p2)){
                a[p2.x][p2.y] = a[p.x][p.y] + 1;
                push(p2);
            }
        }
    }
}
bool cmp(P p1, P p2){
    return p1.dis < p2.dis;
}
int DIS(P p1,P p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
int solve()
{
    BFS();
    pnum = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(a[i][j] > 1){
                P p;
                p.x = i;
                p.y = j;
                p.dis = a[i][j] - 1;
                point[pnum++] = p;
            }
        }
    }
    if(pnum == 0){
        if(N == 1) return (M-1) / 2;
        if(M == 1) return (N-1) / 2;
        return (2*N + 2*M - 4)/3;
    }
    sort(point,point+pnum,cmp);
    int q = 0,d = 1;
    while(q < pnum){
        bool flag = false;
        for(int i=q; i<pnum; ++i){
            for(int j=i+1;j<pnum; ++j){
                if(DIS(point[i],point[j]) < d) continue;
                for(int k=j+1; k<pnum; ++k){
                    if(DIS(point[i],point[k]) >= d &&
                            DIS(point[j],point[k]) >= d){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag == false) break;
        ++d;
        while(q < pnum && point[q].dis < d){
            ++q;
        }
    }
    return d-1;
}
int main()
{
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        ++cas;
        int ans  = 1;
        scanf("%d %d",&N,&M);
        gets(s);
        for(int i=0; i<N; ++i){
            gets(s);
            for(int j=0; j<M; ++j){
                map[i][j] = (s[j] == '.' ? 0 : 1);
                a[i][j] = map[i][j];
            }
        }
        ans = solve();
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
