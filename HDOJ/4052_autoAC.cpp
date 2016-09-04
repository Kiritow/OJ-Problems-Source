#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define LL long long
const int maxn = 100110;
int sum[maxn << 2], cover[maxn << 2];
int V[maxn], p[maxn][4];
int n, w, h, cnt, tot;
struct ST{
    int l, r, h, c;
    ST(){}
    ST(int L, int R, int H, int C):l(L), r(R), h(H), c(C){};
    bool operator < (const ST &cmp) const{
        return h < cmp.h;
    }
}ss[maxn];
void PushUp(int rt, int l, int r)
{
    if(cover[rt]) sum[rt] = V[r + 1] - V[l];
    else if(l == r) sum[rt] = 0;
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void update(int L, int R, int c, int l, int r, int rt)
{
    if(L <= l && r <= R){
        cover[rt] += c;
        PushUp(rt, l, r);
        return ;
    }
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(m < R) update(L, R, c, rson);
    PushUp(rt, l, r);
}
int Bin(int x)
{
    int l = 0, r = tot - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(x == V[mid]) return mid;
        else if(x > V[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
LL gao()
{
    LL res = 0;
    tot = 1;
    sort(V, V + cnt);
    sort(ss, ss + cnt);
    for(int i = 1; i < cnt; i++){
        if(V[i] != V[i - 1])
            V[tot++] = V[i];
    }
    memset(sum, 0, sizeof(sum));
    memset(cover, 0, sizeof(cover));
    for(int i = 0; i < cnt - 1; i++){
        int l = Bin(ss[i].l), r= Bin(ss[i].r) - 1;
        if(l <= r){
            update(l, r, ss[i].c, 0, tot, 1);
            res += (LL)sum[1] * (ss[i + 1].h - ss[i].h);
        }
    }
    return res;
}
LL sloveX(int n1, int m)
{
    cnt = 0;
    for(int i = 0; i < n1; i++){
        V[cnt] = max(0, p[i][0] - m);
        ss[cnt++] = ST(max(0, p[i][0] - m), p[i][2], p[i][1] - 1, 1);
        V[cnt] = p[i][2];
        ss[cnt++] = ST(max(0, p[i][0] - m), p[i][2], p[i][3], -1);
    }
    V[cnt] = w - m + 1;
    ss[cnt++] = ST(w - m + 1, w, 0, 1);
    V[cnt] = w;
    ss[cnt++] = ST(w - m + 1, w, h, -1);
    return gao();
}
LL sloveY(int n1, int m)
{
    cnt = 0;
    for(int i = 0; i < n1; i++){
        V[cnt] = p[i][0] - 1;
        ss[cnt++] = ST(p[i][0] - 1, p[i][2], max(0, p[i][1] - m), 1);
        V[cnt] = p[i][2];
        ss[cnt++] = ST(p[i][0] - 1, p[i][2], p[i][3], -1);
    }
    V[cnt] = 0;
    ss[cnt++] = ST(0, w, h - m + 1, 1);
    V[cnt] = w;
    ss[cnt++] = ST(0, w, h, -1);
    return gao();
}
int main()
{
    int n1, m;
    while(scanf("%d %d %d %d", &w, &h, &n1, &m) == 4){
        for(int i = 0; i < n1; i++)
            scanf("%d %d %d %d", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);
        LL ans = 0;
        if(w >= m)ans = (LL)w * h - sloveX(n1, m);
        if(m != 1 && h >= m) ans += (LL)w * h - sloveY(n1, m);
        printf("%I64d\n", ans);
    }
    return 0;
}
