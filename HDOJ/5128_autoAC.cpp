#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10010
#define LL long long
using namespace std;
bool vis[MAXN][MAXN];
struct DOT {
    int x, y;
    DOT() {}
    DOT(int _x, int _y) {
        x = _x; y = _y;
    }
}dot[MAXN];
struct Matrix {
    DOT up, down; 
    Matrix() { }
    Matrix(DOT a, DOT b) {
        up = a;
        down = b;
    }
}maxrix[MAXN];
int area(Matrix m) {
    return (m.down.x-m.up.x)*(m.up.y-m.down.y);
}
vector<Matrix> vec;
bool cmp(DOT a, DOT b) {
    if(a.x < b.x)
        return true;
    if(a.x > b.x)
        return false;
    return a.y <= b.y;
}
int son_judge(DOT t, Matrix m) {
    int x1 = m.up.x;
    int y1 = m.up.y;
    int x2 = m.down.x;
    int y2 = m.down.y;
    if(t.x>=x1 && t.x<=x2 && t.y<=y1 && t.y>=y2) {
        if(t.x>x1 && t.x<x2 && t.y<y1 && t.y>y2)
            return 1;
        return 0;
    }
    return -1;
}
int judge(int i, int j) {
    DOT t1 = DOT(vec[i].up.x, vec[i].down.y);
    DOT t2 = DOT(vec[i].down.x, vec[i].up.y);
    int ok1 = son_judge(vec[i].up, vec[j]);
    int ok2 = son_judge(vec[i].down, vec[j]);
    int ok3 = son_judge(t1, vec[j]);
    int ok4 = son_judge(t2, vec[j]);
    if(ok1==1&&ok2==1&&ok3==1&&ok4==1)
        return 1;
    if(ok1==-1&&ok2==-1&&ok3==-1&&ok4==-1)
        return -1;
    return 0;
}
int main() {
    int n;
    while(scanf("%d", &n) && n) {
        if(n < 8) {
            puts("imp");
            continue;
        }
        vec.clear();
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i) {
            scanf("%d%d", &dot[i].x, &dot[i].y);
            vis[dot[i].x][dot[i].y] = true;
        }
        sort(dot, dot+n, cmp);
        int x1, x2, y1, y2;
        for(int i=0; i<n; ++i) {
            x1 = dot[i].x;
            y1 = dot[i].y;
            for(int j=i+1; j<n; ++j) {
                x2 = dot[j].x;
                y2 = dot[j].y;
                if(x2<=x1 || y2>=y1) continue;
                if(vis[x2][y1] && vis[x1][y2]) {
                    vec.push_back(Matrix(dot[i], dot[j]));
                }
            }
        }
        int ans = 0;
        for(int i=0; i<vec.size(); ++i) {
                    for(int j=i+1; j<vec.size(); ++j) {
                int tmp1 = judge(i, j);
                int tmp2 = judge(j, i);
                if(tmp1 == 1 || tmp2 == 1) {
                    ans = max(ans, max(area(vec[i]), area(vec[j])));
                } else if(tmp1 == -1 && tmp2 == -1) {
                        ans = max(ans, area(vec[i])+area(vec[j]));
                }
            }
        }
        if(ans == 0)
            puts("imp");
        else printf("%d\n", ans);
    }
    return 0;
}
