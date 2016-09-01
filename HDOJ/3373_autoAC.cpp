#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 200010
#define eps 1e-6
#define maxaxis 1000000000
#define ll __int64
typedef int Type;
Type bin[maxn];
int size, tot;
int B(Type val) {
    int l = 0;
    int r = tot-1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(bin[m] == val)
            return m;
        if(val > bin[m]) {
            l = m + 1;
        }else
            r = m - 1;
    }
}
struct point {
    int x, y;
    int _ix, _iy;
}P[maxn];
struct Tree {
    int son[4];
    Type Sum;
    void clear() {
        Sum = 0;
        for(int i = 0; i < 4; i++)
            son[i] = -1;
    }
}T[maxn*6];
int root, all;
void Insert(int& root, int x, int y, int lx, int rx, int ly, int ry) {
    if(x > rx || x < lx || y > ry || y < ly)
        return ;
    if(root == -1) {
        root = all++;
        T[root].clear();
    }
    if(lx == rx && x == lx && y == ly && ly == ry) {
        T[root].Sum ++;
        return ;
    }
    int midx0 = (lx + rx) >> 1;
    int midy0 = (ly + ry) >> 1;
    int midx1 = (lx==rx) ? midx0 : midx0 + 1;
    int midy1 = (ly==ry) ? midy0 : midy0 + 1;
    if(lx == rx) {
        Insert(T[root].son[0], x, y, lx, midx0, ly, midy0);
        Insert(T[root].son[1], x, y, lx, midx0, midy1, ry);
    }else if(ly == ry) {
        Insert(T[root].son[1], x, y, lx, midx0, midy1, ry);
        Insert(T[root].son[2], x, y, midx1, rx, ly, midy0);
    }else {
        Insert(T[root].son[0], x, y, lx, midx0, ly, midy0);
        Insert(T[root].son[1], x, y, lx, midx0, midy1, ry);
        Insert(T[root].son[2], x, y, midx1, rx, ly, midy0);
        Insert(T[root].son[3], x, y, midx1, rx, midy1, ry);
    }
    int i;
    T[root].Sum = 0;
    for(i = 0; i < 4; i++) {
        if(T[root].son[i] != -1) {
            T[root].Sum += T[ T[root].son[i] ].Sum;
        }
    }
}
void Query(int root, int x0, int x1, int y0, int y1, 
                      int lx, int rx, int ly, int ry, Type& Num) {
    if(x0 > rx || x1 < lx || y0 > ry || y1 < ly || root == -1)
        return ;
    if(Num > 1)
        return ;
    if(x0 <= lx && rx <= x1 && y0 <= ly && ry <= y1) {
        Num += T[root].Sum;
        return ;
    }
    int midx0 = (lx + rx) >> 1;
    int midy0 = (ly + ry) >> 1;
    int midx1 = (lx==rx) ? midx0 : midx0 + 1;
    int midy1 = (ly==ry) ? midy0 : midy0 + 1;
    if(lx == rx) {
        Query(T[root].son[0], x0, x1, y0, y1, lx, midx0, ly, midy0, Num);
        Query(T[root].son[1], x0, x1, y0, y1, lx, midx0, midy1, ry, Num);
    }else if(ly == ry) {
        Query(T[root].son[1], x0, x1, y0, y1, lx, midx0, midy1, ry, Num);
        Query(T[root].son[2], x0, x1, y0, y1, midx1, rx, ly, midy0, Num);
    }else {
        Query(T[root].son[0], x0, x1, y0, y1, lx, midx0, ly, midy0, Num);
        Query(T[root].son[1], x0, x1, y0, y1, lx, midx0, midy1, ry, Num);
        Query(T[root].son[2], x0, x1, y0, y1, midx1, rx, ly, midy0, Num);
        Query(T[root].son[3], x0, x1, y0, y1, midx1, rx, midy1, ry, Num);
    }
}
int LargeThan(int val, int pre) {
    int l = 0;
    int r = pre;
    int ans = l;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(val <= bin[m]) {
            r = m - 1;
            ans = m;
        }else
            l = m + 1;
    }
    return ans;
}
int LessThan(int val, int pre) {
    int l = pre;
    int r = tot - 1;
    int ans = r;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(val >= bin[m]) {
            l = m + 1;
            ans = m;
        }else
            r = m - 1;
    }
    return ans;
}
int Process(int idx, int dis) {
    int xleft  = LargeThan( P[idx].x - dis, P[idx]._ix );
    int yleft  = LargeThan( P[idx].y - dis, P[idx]._iy );
    int xright =  LessThan( P[idx].x + dis, P[idx]._ix );
    int yright =  LessThan( P[idx].y + dis, P[idx]._iy );
    int Num = 0;
    Query(root, xleft, xright, yleft, yright, 0, tot-1, 0, tot-1, Num);
    return Num;
}
int n;
int main() {
    int i;
    int Max;
    while(scanf("%d", &n) != EOF) {
        size = 0;
        tot = 0;
        all = 0;
        Max = 0;
        for(i = 0; i < n; i++) {
            scanf("%d %d", &P[i].x, &P[i].y);
            bin[ size++ ] = P[i].x;
            bin[ size++ ] = P[i].y;
            if(P[i].x > Max) Max = P[i].x;
            if(P[i].y > Max) Max = P[i].y;
        }
        sort(bin, bin + size);
        for(i = 0; i < size; i++) {
            if(i == 0 || bin[i] != bin[i-1])
                bin[tot++] = bin[i];
        }
        root = -1;
        for(i = 0; i < n; i++) {
            P[i]._ix = B(P[i].x);
            P[i]._iy = B(P[i].y);
            Insert(root, P[i]._ix, P[i]._iy, 0, tot-1, 0, tot-1);
        }
        ll ans = 0;
        for(i = 0; i < n; i++) {
            int l = 0;
            int r = Max;
            int dis = 0;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(Process(i, m) > 1) {
                    r = m - 1;
                    dis = m;
                }else
                    l = m + 1;
            }
            ans += dis;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
