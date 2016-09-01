#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define MAXN 510005
#define MAXM 164444
#define INF 100000000
#define eps 1e-7
#define L(X) X<<1
#define R(X) X<<1|1
using namespace std;
struct node
{
    int left, right;
    int mi;
}tree[4 * MAXN];
int a[MAXN], pos[MAXN];
void up(int C)
{
    tree[C].mi = min(tree[L(C)].mi, tree[R(C)].mi);
}
void make_tree(int s, int e, int C)
{
    tree[C].left = s;
    tree[C].right = e;
    tree[C].mi = INF;
    if(s == e) return;
    int mid = (s + e) >> 1;
    make_tree(s, mid, L(C));
    make_tree(mid + 1, e, R(C));
}
void update(int p, int C)
{
    if(tree[C].left == tree[C].right)
    {
        tree[C].mi = p;
        return;
    }
    int mid = (tree[C].left + tree[C].right) >> 1;
    if(mid >= p) update(p, L(C));
    else update(p, R(C));
    up(C);
}
int ans;
void query(int s, int e, int C)
{
    if(tree[C].left >= s && tree[C].right <= e)
    {
        ans = min(ans, tree[C].mi);
        return;
    }
    int mid = (tree[C].left + tree[C].right) >> 1;
    if(mid >= s) query(s, e, L(C));
    if(mid < e) query(s, e, R(C));
}
int in()
{
    int flag = 1;
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    if(ch == '-') flag = -1;
    else
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return flag * a;
}
void out(int a)
{
    if(a >= 10)out(a / 10);
    putchar(a % 10 + '0');
}
int main()
{
    int t, x, cas = 0;
    char s;
    while(scanf("%d", &t) != EOF && t)
    {
        if(cas) puts("");
        int cnt = 0;
        memset(pos, -1, sizeof(pos));
        printf("Case %d:\n", ++cas);
        make_tree(1, MAXN - 1, 1);
        getchar();
        while(t--)
        {
            s = getchar();
            x = in();
            if(s == 'A')
            {
                if(x < 5000)
                {
                    ans = INF;
                    int tx = x;
                    for(int i = cnt - 1; i >= 0; i--)
                    {
                        if(a[i] % x < tx)
                        {
                            tx = a[i] % x;
                            ans = a[i];
                        }
                        if(tx == 0) break;
                    }
                    if(ans == INF) {puts("-1");}
                    else {out(pos[ans] + 1); putchar('\n');}
                }
                else
                {
                    int bd = 500055 / x;
                    int res = INF;
                    int tx = x;
                    for(int i = 0; i <= bd; i++)
                    {
                        ans = INF;
                        int low = i * x;
                        if(low < 1) low = 1;
                        int high = (i + 1) * x - 1;
                        if(high > 500054) high = 500054;
                        query(low, high, 1);
                        if(ans == INF) continue;
                        if(ans % x < tx)
                        {
                            tx = ans % x;
                            res = ans;
                        }
                        else if(ans % x == tx)
                        {
                            if(pos[ans] > pos[res]) res = ans;
                        }
                    }
                    if(res == INF) {puts("-1");}
                    else {out(pos[res] + 1); putchar('\n');}
                }
            }
            else
            {
                if(pos[x] == -1)
                {
                    pos[x] = cnt;
                    a[cnt++] = x;
                    update(x, 1);
                }
            }
        }
    }
    return 0;
}
