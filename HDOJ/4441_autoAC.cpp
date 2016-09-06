#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 200010
typedef long long LL;
namespace SP
{
    int T, node;
    struct Splay
    {
        int ls, rs, pre, size, num[2], key;
        LL sum;
        void update(); void zig(int x); void zag(int x); void splay(int x, int goal);
        void init()
        {
            ls = rs = pre = 0;
            key = size = sum = num[0] = num[1] = 0;
        }
    }sp[MAXD];
    void init()
    {
        T = 1, node = 2;
        sp[0].init(), sp[1].init(), sp[2].init();
        sp[1].rs = 2, sp[2].pre = 1;
        sp[1].size = 2, sp[2].size = 1;
    }
    inline void Splay::update()
    {
        size = sp[ls].size + sp[rs].size + 1;
        sum = sp[ls].sum + sp[rs].sum + key;
        num[0] = sp[ls].num[0] + sp[rs].num[0] + (key < 0);
        num[1] = sp[ls].num[1] + sp[rs].num[1] + (key > 0);
    }
    inline void Splay::zig(int x)
    {
        int y = rs, fa = pre;
        rs = sp[y].ls, sp[rs].pre = x;
        sp[y].ls = x, pre = y;
        sp[y].pre = fa;
        if(fa == 0) T = y;
        else sp[fa].ls == x ? sp[fa].ls = y : sp[fa].rs = y;
        update();
    }
    inline void Splay::zag(int x)
    {
        int y = ls, fa = pre;
        ls = sp[y].rs, sp[ls].pre = x;
        sp[y].rs = x, pre = y;
        sp[y].pre = fa;
        if(fa == 0) T = y;
        else sp[fa].ls == x ? sp[fa].ls = y : sp[fa].rs = y;
        update();
    }
    void Splay::splay(int x, int goal)
    {
        int y, z;
        for(; pre != goal;)
        {
            y = pre;
            if(sp[y].pre == goal) sp[y].rs == x ? sp[y].zig(y) : sp[y].zag(y);
            else
            {
                z = sp[y].pre;
                if(sp[z].rs == y)
                {
                    if(sp[y].rs == x) sp[z].zig(z), sp[y].zig(y);
                    else sp[y].zag(y), sp[z].zig(z);
                }
                else
                {
                    if(sp[y].ls == x) sp[z].zag(z), sp[y].zag(y);
                    else sp[y].zig(y), sp[z].zag(z);
                }
            }
        }
        update();
    }
    void newnode(int &cur)
    {
        cur = ++ node;
        sp[cur].init();
    }
    int insert(int &cur, int fa, int key)
    {
        newnode(cur);
        sp[cur].key = key, sp[cur].pre = fa, sp[cur].update();
        return cur;
    }
    int find(int k)
    {
        if(sp[T].size < k) return -1;
        int i = T;
        for(;;)
        {
            int n = sp[sp[i].ls].size;
            if(n + 1 == k) break;
            if(k <= n) i = sp[i].ls;
            else i = sp[i].rs, k -= n + 1;
        }
        return i;
    }
}
int N, D, min[4 * MAXD], loc[MAXD][2];
void update(int i)
{
    for(; i ^ 1; i >>= 1) min[i >> 1] = std::min(min[i], min[i ^ 1]);
}
void init()
{
    for(D = 1; D < N + 2; D <<= 1);
    memset(min, 0, sizeof(min[0]) * D * 2);
    min[D] = 1, update(D);
    SP::init();
}
int find()
{
    int i = 1;
    for(; i < D;)
    {
        if(min[i << 1] == 0) i <<= 1;
        else i = i << 1 | 1;
    }
    return i - D;
}
void insert(int p)
{
    int i = find(), x, y, t;
    min[D + i] = 1, update(D + i);
    x = SP::find(p + 1), SP::sp[x].splay(x, 0);
    y = SP::find(p + 2), SP::sp[y].splay(y, x);
    t = SP::insert(SP::sp[y].ls, y, i);
    SP::sp[y].update(), SP::sp[x].update();
    loc[i][1] = t, SP::sp[t].splay(t, 0);
    int n = SP::sp[SP::sp[t].ls].num[1] + 1;
    if(n > SP::sp[t].num[0])
    {
        int k = SP::sp[t].size;
        x = SP::find(k - 1), SP::sp[x].splay(x, 0);
        y = SP::find(k), SP::sp[y].splay(y, x);
        t = SP::insert(SP::sp[y].ls, y, -i);
        SP::sp[y].update(), SP::sp[x].update();
        loc[i][0] = t;
    }
    else
    {
        int j = SP::T, k = n;
        for(;;)
        {
            int n = SP::sp[SP::sp[j].ls].num[0], d = SP::sp[j].key < 0;
            if(d == 1 && n + d == k) break;
            if(k <= n) j = SP::sp[j].ls;
            else j = SP::sp[j].rs, k -= n + d;
        }
        SP::sp[j].splay(j, 0);
        x = SP::find(SP::sp[SP::sp[j].ls].size);
        SP::sp[x].splay(x, j);
        t = SP::insert(SP::sp[x].rs, x, -i);
        SP::sp[x].update(), SP::sp[j].update();
        loc[i][0] = t;
    }
}
void remove(int i)
{
    min[D + i] = 0, update(D + i);
    for(int j = 0; j < 2; j ++)
    {
        SP::sp[loc[i][j]].splay(loc[i][j], 0);
        int x, y, n = SP::sp[SP::sp[SP::T].ls].size + 1;
        x = SP::find(n - 1), SP::sp[x].splay(x, 0);
        y = SP::find(n + 1), SP::sp[y].splay(y, x);
        SP::sp[y].ls = 0;
        SP::sp[y].update(), SP::sp[x].update();
    }
}
void query(int i)
{
    int x = loc[i][1], y = loc[i][0];
    SP::sp[x].splay(x, 0), SP::sp[y].splay(y, x);
    printf("%I64d\n", SP::sp[SP::sp[y].ls].sum);
}
void solve()
{
    char op[10];
    for(int i = 0; i < N; i ++)
    {
        int k;
        scanf("%s%d", op, &k);
        if(op[0] == 'i') insert(k);
        else if(op[0] == 'r') remove(k);
        else query(k);
    }
}
int main()
{
    int t = 0;
    while(scanf("%d", &N) == 1)
    {
        init();
        printf("Case #%d:\n", ++ t);
        solve();
    }
    return 0;
}#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 200010
typedef long long LL;
namespace SP
{
    int T, node;
    struct Splay
    {
        int ls, rs, pre, size, num[2], key;
        LL sum;
        void update(); void zig(int x); void zag(int x); void splay(int x, int goal);
        void init()
        {
            ls = rs = pre = 0;
            key = size = sum = num[0] = num[1] = 0;
        }
    }sp[MAXD];
    void init()
    {
        T = 1, node = 2;
        sp[0].init(), sp[1].init(), sp[2].init();
        sp[1].rs = 2, sp[2].pre = 1;
        sp[1].size = 2, sp[2].size = 1;
    }
    inline void Splay::update()
    {
        size = sp[ls].size + sp[rs].size + 1;
        sum = sp[ls].sum + sp[rs].sum + key;
        num[0] = sp[ls].num[0] + sp[rs].num[0] + (key < 0);
        num[1] = sp[ls].num[1] + sp[rs].num[1] + (key > 0);
    }
    inline void Splay::zig(int x)
    {
        int y = rs, fa = pre;
        rs = sp[y].ls, sp[rs].pre = x;
        sp[y].ls = x, pre = y;
        sp[y].pre = fa;
        if(fa == 0) T = y;
        else sp[fa].ls == x ? sp[fa].ls = y : sp[fa].rs = y;
        update();
    }
    inline void Splay::zag(int x)
    {
        int y = ls, fa = pre;
        ls = sp[y].rs, sp[ls].pre = x;
        sp[y].rs = x, pre = y;
        sp[y].pre = fa;
        if(fa == 0) T = y;
        else sp[fa].ls == x ? sp[fa].ls = y : sp[fa].rs = y;
        update();
    }
    void Splay::splay(int x, int goal)
    {
        int y, z;
        for(; pre != goal;)
        {
            y = pre;
            if(sp[y].pre == goal) sp[y].rs == x ? sp[y].zig(y) : sp[y].zag(y);
            else
            {
                z = sp[y].pre;
                if(sp[z].rs == y)
                {
                    if(sp[y].rs == x) sp[z].zig(z), sp[y].zig(y);
                    else sp[y].zag(y), sp[z].zig(z);
                }
                else
                {
                    if(sp[y].ls == x) sp[z].zag(z), sp[y].zag(y);
                    else sp[y].zig(y), sp[z].zag(z);
                }
            }
        }
        update();
    }
    void newnode(int &cur)
    {
        cur = ++ node;
        sp[cur].init();
    }
    int insert(int &cur, int fa, int key)
    {
        newnode(cur);
        sp[cur].key = key, sp[cur].pre = fa, sp[cur].update();
        return cur;
    }
    int find(int k)
    {
        if(sp[T].size < k) return -1;
        int i = T;
        for(;;)
        {
            int n = sp[sp[i].ls].size;
            if(n + 1 == k) break;
            if(k <= n) i = sp[i].ls;
            else i = sp[i].rs, k -= n + 1;
        }
        return i;
    }
}
int N, D, min[4 * MAXD], loc[MAXD][2];
void update(int i)
{
    for(; i ^ 1; i >>= 1) min[i >> 1] = std::min(min[i], min[i ^ 1]);
}
void init()
{
    for(D = 1; D < N + 2; D <<= 1);
    memset(min, 0, sizeof(min[0]) * D * 2);
    min[D] = 1, update(D);
    SP::init();
}
int find()
{
    int i = 1;
    for(; i < D;)
    {
        if(min[i << 1] == 0) i <<= 1;
        else i = i << 1 | 1;
    }
    return i - D;
}
void insert(int p)
{
    int i = find(), x, y, t;
    min[D + i] = 1, update(D + i);
    x = SP::find(p + 1), SP::sp[x].splay(x, 0);
    y = SP::find(p + 2), SP::sp[y].splay(y, x);
    t = SP::insert(SP::sp[y].ls, y, i);
    SP::sp[y].update(), SP::sp[x].update();
    loc[i][1] = t, SP::sp[t].splay(t, 0);
    int n = SP::sp[SP::sp[t].ls].num[1] + 1;
    if(n > SP::sp[t].num[0])
    {
        int k = SP::sp[t].size;
        x = SP::find(k - 1), SP::sp[x].splay(x, 0);
        y = SP::find(k), SP::sp[y].splay(y, x);
        t = SP::insert(SP::sp[y].ls, y, -i);
        SP::sp[y].update(), SP::sp[x].update();
        loc[i][0] = t;
    }
    else
    {
        int j = SP::T, k = n;
        for(;;)
        {
            int n = SP::sp[SP::sp[j].ls].num[0], d = SP::sp[j].key < 0;
            if(d == 1 && n + d == k) break;
            if(k <= n) j = SP::sp[j].ls;
            else j = SP::sp[j].rs, k -= n + d;
        }
        SP::sp[j].splay(j, 0);
        x = SP::find(SP::sp[SP::sp[j].ls].size);
        SP::sp[x].splay(x, j);
        t = SP::insert(SP::sp[x].rs, x, -i);
        SP::sp[x].update(), SP::sp[j].update();
        loc[i][0] = t;
    }
}
void remove(int i)
{
    min[D + i] = 0, update(D + i);
    for(int j = 0; j < 2; j ++)
    {
        SP::sp[loc[i][j]].splay(loc[i][j], 0);
        int x, y, n = SP::sp[SP::sp[SP::T].ls].size + 1;
        x = SP::find(n - 1), SP::sp[x].splay(x, 0);
        y = SP::find(n + 1), SP::sp[y].splay(y, x);
        SP::sp[y].ls = 0;
        SP::sp[y].update(), SP::sp[x].update();
    }
}
void query(int i)
{
    int x = loc[i][1], y = loc[i][0];
    SP::sp[x].splay(x, 0), SP::sp[y].splay(y, x);
    printf("%I64d\n", SP::sp[SP::sp[y].ls].sum);
}
void solve()
{
    char op[10];
    for(int i = 0; i < N; i ++)
    {
        int k;
        scanf("%s%d", op, &k);
        if(op[0] == 'i') insert(k);
        else if(op[0] == 'r') remove(k);
        else query(k);
    }
}
int main()
{
    int t = 0;
    while(scanf("%d", &N) == 1)
    {
        init();
        printf("Case #%d:\n", ++ t);
        solve();
    }
    return 0;
}
