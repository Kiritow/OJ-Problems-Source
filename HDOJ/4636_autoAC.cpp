#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#define MID(x,y) ((x+y)>>1)
#define iabs(x) ((x)>0?(x):-(x))
using namespace std;
vector <int>v[40];
inline void v_pb(int a,int b){
    v[a].push_back(b);
}
int num[40];
queue<int>q;
bool vis[40];
bool bfs(int s,int flag){
    while(!q.empty()) q.pop();
    q.push(s);
    int cnt = -1;
    while(!q.empty()){
        int k = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < v[k].size(); i++){
            int d = v[k][i];
            if (!vis[d] && num[d] == flag){
                vis[d] = 1;
                q.push(d);
            }
        }
    }
    if(flag == 0 && cnt == 0)return 1;
    return 0;
}
int main(){
    v_pb(1,2);v_pb(1,3);v_pb(1,17);v_pb(1,18);v_pb(1,20);v_pb(1,13);
    v_pb(2,1);v_pb(2,3);v_pb(2,4);v_pb(2,7);v_pb(2,12);v_pb(2,13);
    v_pb(3,1);v_pb(3,2);v_pb(3,4);v_pb(3,5);v_pb(3,20);
    v_pb(4,2);v_pb(4,3);v_pb(4,5);v_pb(4,6);v_pb(4,7);v_pb(4,8);
    v_pb(5,3);v_pb(5,4);v_pb(5,6);v_pb(5,20);v_pb(5,21);v_pb(5,24);
    v_pb(6,4);v_pb(6,5);v_pb(6,8);v_pb(6,9);v_pb(6,24);
    v_pb(7,2);v_pb(7,4);v_pb(7,8);v_pb(7,10);v_pb(7,12);
    v_pb(8,4);v_pb(8,6);v_pb(8,7);v_pb(8,9);v_pb(8,10);v_pb(8,11);
    v_pb(9,6);v_pb(9,8);v_pb(9,11);v_pb(9,24);v_pb(9,26);v_pb(9,27);
    v_pb(10,7);v_pb(10,8);v_pb(10,11);v_pb(10,12);v_pb(10,14);v_pb(10,16);
    v_pb(11,8);v_pb(11,9);v_pb(11,10);v_pb(11,16);v_pb(11,27);
    v_pb(12,2);v_pb(12,7);v_pb(12,10);v_pb(12,13);v_pb(12,14);v_pb(12,15);
    v_pb(13,12);v_pb(13,15);v_pb(13,2);v_pb(13,1);v_pb(13,17);
    v_pb(14,10);v_pb(14,12);v_pb(14,15);v_pb(14,16);v_pb(14,30);
    v_pb(15,12);v_pb(15,13);v_pb(15,14);v_pb(15,30);v_pb(15,32);v_pb(15,17);
    v_pb(16,10);v_pb(16,11);v_pb(16,14);v_pb(16,27);v_pb(16,29);v_pb(16,30);
    v_pb(17,1);v_pb(17,18);v_pb(17,19);v_pb(17,13);v_pb(17,15);v_pb(17,32);
    v_pb(18,1);v_pb(18,17);v_pb(18,19);v_pb(18,20);v_pb(18,22);
    v_pb(19,17);v_pb(19,18);v_pb(19,31);v_pb(19,22);v_pb(19,23);v_pb(19,32);
    v_pb(20,1);v_pb(20,3);v_pb(20,5);v_pb(20,18);v_pb(20,21);v_pb(20,22);
    v_pb(21,5);v_pb(21,20);v_pb(21,22);v_pb(21,24);v_pb(21,25);
    v_pb(22,19);v_pb(22,18);v_pb(22,20);v_pb(22,21);v_pb(22,23);v_pb(22,25);
    v_pb(23,19);v_pb(23,22);v_pb(23,25);v_pb(23,28);v_pb(23,31);
    v_pb(24,5);v_pb(24,6);v_pb(24,9);v_pb(24,21);v_pb(24,25);v_pb(24,26);
    v_pb(25,21);v_pb(25,22);v_pb(25,23);v_pb(25,24);v_pb(25,26);v_pb(25,28);
    v_pb(26,9);v_pb(26,24);v_pb(26,25);v_pb(26,27);v_pb(26,28);
    v_pb(27,9);v_pb(27,11);v_pb(27,16);v_pb(27,26);v_pb(27,28);v_pb(27,29);
    v_pb(28,25);v_pb(28,26);v_pb(28,27);v_pb(28,29);v_pb(28,31);v_pb(28,23);
    v_pb(29,16);v_pb(29,27);v_pb(29,28);v_pb(29,30);v_pb(29,31);
    v_pb(30,14);v_pb(30,15);v_pb(30,16);v_pb(30,29);v_pb(30,31);v_pb(30,32);
    v_pb(31,28);v_pb(31,29);v_pb(31,30);v_pb(31,32);v_pb(31,23);v_pb(31,19);
    v_pb(32,30);v_pb(32,31);v_pb(32,15);v_pb(32,19);v_pb(32,17);
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++){
        printf("Case %d: ", cas);
        int black = 0,white = 0;
        for (int i = 1; i <= 32; ++i){
            scanf("%d", &num[i]);
            if(num[i]) black ++;
        }
        if (black == 0) {puts("0");continue;}
        memset(vis,0,sizeof(vis));
        black = 0;
        for (int i = 1; i <= 32; ++i){
            if (!vis[i]){
                vis[i] = 1;
                if (num[i]){
                    black ++;
                    bfs(i,1);
                }else {
                    white ++;
                    if(bfs(i,0)) white --;
                }
            }
        }
        if(black <= 2) printf("%d\n", black);
        else if (white == 1) puts("2");
        else puts("3");
    }
    return 0;
}
