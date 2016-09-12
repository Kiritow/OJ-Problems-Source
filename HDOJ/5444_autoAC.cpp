#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1100;
struct tree{
    int v, l, r, f;
    tree(){}
    tree(int v, int l, int r, int f):v(v), l(l), r(r), f(f){}
} t[maxn<<2];
int T, n;
int pt, sz;
int st[maxn];
int a[maxn];
int ps[maxn];
bool v[maxn];
void work(int x){
    int pos = 0, ed = ps[x];
    while(1){
        if (pt > ed) break;
        v[a[pt]] = true;
        if (t[pos].v > a[pt]){
            if (t[pos].r == -1){
                st[a[pt]] = sz;
                t[sz] = tree(a[pt++], -1, -1, pos);
                t[pos].r = sz;
                pos = sz++;
            }
            else pos = t[pos].r;
        }
        else{
            if (t[pos].l == -1){
                st[a[pt]] = sz;
                t[sz] = tree(a[pt++], -1, -1, pos);
                t[pos].l = sz;
                pos = sz++;
            }
            else pos = t[pos].l;
        }
    }
}
char s[1100];
void output(int x){
    int len = 0, px;
    while(1){
        px = x;
        x = t[x].f;    
        if (x == -1) break;
        if (t[x].l == px) s[len++] = 'W';
        else s[len++] = 'E';
    }
    for (int i = 0, j = len-1; i < j; i++, j--)
        swap(s[i], s[j]);
    s[len] = 0;
    printf("%s\n", s);
}
int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            v[i+1] = false;
            scanf("%d", &a[i]);
            ps[a[i]] = i;
        }
        sz = 0, pt = 1;
        t[sz++] = tree(a[0], -1, -1, -1);
        v[a[0]] = true;
        for (int i = 1; i <= n; i++)
            if (!v[i]){ work(i); }
        int q, qq;
        scanf("%d", &q);
        for (int i = 0; i < q; i++){
            scanf("%d", &qq);
            output(st[qq]);
        }
    }
    return 0;
}
